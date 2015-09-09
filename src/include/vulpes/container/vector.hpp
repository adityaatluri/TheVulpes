//
//  vector.hpp
//
//  Created by Aditya Atluri on 7/3/15.
//  Copyright © 2015 Aditya Atluri. All rights reserved.
//

#ifndef vector_hpp
#define vector_hpp

#include "../device.hpp"
#include "../allocator.hpp"
#include "../iterator.hpp"
#include <vector>

namespace vulpes{
    template<typename T>
    class vector{
    private:
        size_t Length;
        device Device;
        size_t Size;
        size_t End;
        size_t Id;
        size_t Capacity;
        id<MTLBuffer> Buffer;
        T *Hostptr;
        std::vector<T,aligned_allocator<T>> Vec;
    public:
        vector(){
            Size = 0;
            Capacity = 0;
            Length = 0;
        }
        vector(size_t _len, device __device){
            Length = _len;
            Capacity = Length;
            Device = __device;
            Size = sizeof(T)*Length;
            Hostptr = NULL;
        }
        
        vector(std::vector<T> &host, device __device){
            Length = host.size();
            Capacity = Length;
            Size = sizeof(T) * Length;
            Hostptr = &host[0];
            Device = __device;
            Buffer = [__device.get_device() newBufferWithBytes:&host[0] length:Size options:0];
        }
        
        vector(std::vector<T> &host){
            Length = host.size();
            Capacity = Length;
            Size = sizeof(T) * Length;
            Hostptr = &host[0];
            Buffer = [Device.get_device() newBufferWithBytes:&host[0] length:Size options:0];
        }
        
        vector(std::vector<T,aligned_allocator<T>> &host){
            Length = host.size();
            Capacity = Length;
            Size = sizeof(T) * Length;
            if(Size%4096 > 0){
                Size = ((Size/4096)+1)*4096;
            }
            Hostptr = &host[0];
            Buffer = [Device.get_device() newBufferWithBytesNoCopy:&host[0] length:Size options:0 deallocator:nil];
        }
        
        vector(std::vector<T,aligned_allocator<T>> &host, device __device){
            Length = host.size();
            Capacity = Length;
            Device = __device;
            Size = sizeof(T) * Length;
            if(Size%4096 > 0){
                Size = ((Size/4096)+1)*4096;
            }
            Hostptr = &host[0];
            Buffer = [__device.get_device() newBufferWithBytesNoCopy:&host[0] length:Size options:0 deallocator:nil];
        }
        
        vector(T* start, T* end){
            Hostptr = start;
            Length = end - start;
            Capacity = Length;
            Size = sizeof(T)*Length;
            Buffer = [Device.get_device() newBufferWithBytes:start length:Size options:0];
        }
        
        vector(size_t _len, T value){
            Length = _len;
            Capacity = _len;
            Size = sizeof(T)*Length;
            std::vector<T> host(_len, value);
            Hostptr = &host[0];
            Buffer = [Device.get_device() newBufferWithBytes:&host[0] length:Size options:0];
        }
        
        ~vector(){
            Length = 0;
            Size = 0;
            Capacity = 0;
            Buffer = NULL;
            Hostptr = NULL;
        }
        
        Iterator<T> begin(){
            vulpes::Iterator<T> _iterator(Device, &Buffer, Hostptr, sizeof(T), Size);
            return _iterator;
        }
        
        Iterator<T> end(){
            vulpes::Iterator<T> _iterator(Device, &Buffer, (T*)Hostptr+Length, sizeof(T), Size);
            return _iterator;
        }
        
        id<MTLBuffer> get_buffer(){
            return Buffer;
        }
        
        void htod(void* array, size_t size, device &_device){
            Hostptr = array;
            Buffer = [_device.get_device() newBufferWithBytes:array length:size options:0];
        }
        
        device get_device(){
            return Device;
        }
        
        vulpes::vector<T>& operator=(std::vector<T>& rhs){
            vector<T> lhs(rhs);
            return lhs;
        }
        
        vulpes::vector<T>& operator=(vulpes::vector<T>& rhs){
            return rhs;
        }
        
        T& operator[](int id){
            if(id < Length){
                return *(Hostptr+id);
            }
            throw std::out_of_range("vulpes::vector: Cannot access element, out of range");
        }
        
        size_t size(){
            return Length;
        }
        
        size_t max_size(){
            // 256 MB
            return 1024*1024*256;
        }
        
        /*
         Capacity is the amount of space that the vector is currently using. Under the hood, a vector just uses an array. The capacity of the vector is the size of that array. This is always equal to or larger than the size. The difference between them is the number of elements that you can add to the vector before the array under the hood needs to be reallocated.
         */
        size_t capacity(){
            return Capacity;
        }
        
        size_t capacity() const{
            return Capacity;
        }
        
        T at(size_t id){
            if(id < Length){
                return *(Hostptr+id);
            }
            throw std::out_of_range("vulpes::vector: Cannot access element, out of range");
        }
        
        T front(){
            return *(Hostptr);
        }
        
        T back(){
            return *(Hostptr)+Length;
        }
        
        T* data(){
            return Hostptr;
        }
        
        void assign(size_t count, T& value){
            if(count < Length){
                for(size_t i = 0;i<count;i++){
                    Hostptr[i] = value;
                }
            }
        }
        
        // Doesn't work with vulpes iterators
        template<class InputIt>
        void assign(InputIt first, InputIt last){
            InputIt iter = first;
            int i=0;
            while(iter != last){
                Hostptr[i] = *iter;
                i++;
                iter = iter+1;
            }
        }
        
        bool empty(){
            bool check;
            if(Length < 1){
                check = true;
            }else{
                check = false;
            }
            return check;
        }
        
        void reserve(size_t new_cap){
            if(new_cap > Capacity){
                std::vector<T,aligned_allocator<T>> vec(new_cap);
                Vec = vec;
                Capacity = vec.size();
                Hostptr = &Vec[0];
                Size = Capacity*sizeof(T);
                Buffer = [Device.get_device() newBufferWithBytesNoCopy:&Vec[0] length:Size options:0 deallocator:nil];
            }
        }
        
        void push_back(T value){
            if(Capacity > Length){
                *(Hostptr+Length) = value;
                Length++;
            }else{
                Capacity = Capacity*2;
                Size = Capacity*sizeof(T);
                std::vector<T,aligned_allocator<T>> vec(Capacity);
                Vec = vec;
                Buffer = [Device.get_device() newBufferWithBytesNoCopy:&Vec[0] length:Size options:0 deallocator:nil];
                for(int i=0;i<Length;i++){
                    Vec[i] = *(Hostptr+i);
                }
                Hostptr = &Vec[0];
                Length = Length+1;
                *(Hostptr+Length) = value;
            }
        }
        
        void clear(){
            for(int i=0;i<Capacity;i++){
                *(Hostptr+i) = 0;
            }
            Length = 0;
        }

        void resize(size_t n){
            Length = n;
        }
        
        void shrink_to_fit(){
            std::vector<T,aligned_allocator<T>>Vec(Length);
            Capacity = Length;
            Size = Capacity*sizeof(T);
            Buffer = [Device.get_device() newBufferWithBytesNoCopy:&Vec[0] length:Size options:0 deallocator:nil];
            for(int i=0;i<Length;i++){
                Vec[i] = *(Hostptr+i);
            }
        }
        
        void pop_back(){
            if(Length > 0){
                Length--;
            }
        }
        
        void swap(vulpes::vector<T> &V){
            T tmp;
            if(V.size() < Length){
                for(int i=0;i<V.size();i++){
                    tmp = Hostptr[i];
                    Hostptr[i] = V[i];
                    V[i] = tmp;
                }
            }else{
                for(int i=0;i<Length;i++){
                    tmp = Hostptr[i];
                    Hostptr[i] = V[i];
                    V[i] = tmp;
                }
            }
        }
    };
}

#endif /* vector_hpp */

/*
TODO:
get_allocator
rbegin
rend
insert
emplace
erase
emplace_back
*/
