//
//  functional.hpp
//
//  Created by Aditya Atluri on 7/3/15.
//  Copyright © 2015 Aditya Atluri. All rights reserved.
//

#ifndef functional_hpp
#define functional_hpp

#include "vulpes.hpp"


namespace vulpes{
    class functional{
    private:
        std::string Src;
        std::string Name;
    public:
        functional(std::string _src,
                   std::string _name):Src(_src), Name(_name){
        }
        std::string get_source(){
            return Src;
        }
        std::string  get_name(){
            return Name;
        }
    };
    
    template<typename T>
    functional plus(){
        std::string name;
        std::string src("NULL");
        if(std::is_same<T, char>::value){
            name = "functional_plus_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_plus_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_plus_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_plus_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_plus_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_plus_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_plus_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_plus_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional minus(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_minus_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_minus_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_minus_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_minus_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_minus_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_minus_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_minus_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_minus_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_minus_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional multiplies(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_multiplies_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_multiplies_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_multiplies_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_multiplies_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_multiplies_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_multiplies_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_multiplies_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_multiplies_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_multiplies_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional divides(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_divides_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_divides_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_divides_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_divides_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_divides_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_divides_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_divides_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_divides_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_divides_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional modulus(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_modulus_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_modulus_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_modulus_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_modulus_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_modulus_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_modulus_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_modulus_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_modulus_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_modulus_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional negate(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_negate_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_negate_short";
        }
        if(std::is_same<T, int>::value){
            name = "functional_negate_int";
        }
        if(std::is_same<T, float>::value){
            name = "functional_negate_float";
        }

        functional _functional(src, name);
        return _functional;
    }
    
    // This is broken
    template<typename T>
    functional equal_to(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_equal_to_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_equal_to_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_equal_to_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_equal_to_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_equal_to_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_equal_to_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_equal_to_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_equal_to_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_equal_to_float";
        }

        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional sqrt(){
        std::string src("NULL");
        std::string name;
/*        if(std::is_same<T, char>::value){
            name = "functional_sqrt_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_sqrt_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_sqrt_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_sqrt_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_sqrt_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_sqrt_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_sqrt_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_sqrt_uint";
        }*/
        if(std::is_same<T, float>::value){
            name = "functional_sqrt_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional get_fill(){
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_fill_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_fill_unsigned_char";

        }
        if(std::is_same<T, short>::value){
            name = "functional_fill_short";

        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_fill_unsigned_short";

        }
        if(std::is_same<T, ushort>::value){
            name = "functional_fill_ushort";

        }
        if(std::is_same<T, int>::value){
            name = "functional_fill_int";

        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_fill_unsigned_int";

        }
        if(std::is_same<T, uint>::value){
            name = "functional_fill_uint";

        }
        if(std::is_same<T, float>::value){
            name = "functional_fill_float";

        }
        std::string src("NULL");
        functional _functional(src, name);
        return _functional;
    }

    
    template<typename T>
    functional get_sequence(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_seq_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_seq_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_seq_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_seq_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_seq_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_seq_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_seq_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_seq_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_seq_float";
        }
        functional _functional(src, name);
        return _functional;
    }


    template<typename T>
    functional get_replace(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_replace_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_replace_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_replace_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_replace_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_replace_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_replace_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_replace_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_replace_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_replace_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional get_replace_copy(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_replace_copy_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_replace_copy_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_replace_copy_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_replace_copy_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_replace_copy_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_replace_copy_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_replace_copy_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_replace_copy_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_replace_copy_float";
        }
        functional _functional(src, name);
        return _functional;
    }
    
    template<typename T>
    functional get_find(){
        std::string src("NULL");
        std::string name;
        if(std::is_same<T, char>::value){
            name = "functional_find_char";
        }
        if(std::is_same<T, unsigned char>::value){
            name = "functional_find_unsigned_char";
        }
        if(std::is_same<T, short>::value){
            name = "functional_find_short";
        }
        if(std::is_same<T, unsigned short>::value){
            name = "functional_find_unsigned_short";
        }
        if(std::is_same<T, ushort>::value){
            name = "functional_find_ushort";
        }
        if(std::is_same<T, int>::value){
            name = "functional_find_int";
        }
        if(std::is_same<T, unsigned int>::value){
            name = "functional_find_unsigned_int";
        }
        if(std::is_same<T, uint>::value){
            name = "functional_find_uint";
        }
        if(std::is_same<T, float>::value){
            name = "functional_find_float";
        }

        functional _functional(src, name);
        return _functional;
    }


};



#endif /* functional_hpp */
