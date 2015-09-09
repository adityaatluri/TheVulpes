//
//  Created by Aditya Atluri on 9/9/15.
//  Copyright © 2015 Aditya Atluri. All rights reserved.
//

#include <iostream>
#include <string>
#include "vulpes.hpp"
#include <vector>

/*
This program tests the vulpes::vector functionality against std::vector functionality
*/

int main(int argc, const char * argv[]) {
    const int length = 100000000;
    
    std::vector<float,aligned_allocator<float>>A(length);
    vulpes::vector<float>Ad(A);
    std::vector<float>D(length);
    
    std::cout<<"Doing Ad: "<<std::endl;
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    std::cout<<"Pushing.."<<std::endl;
    Ad.push_back(1.1);
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    std::cout<<"Pushing.."<<std::endl;
    Ad.push_back(1.1);
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    Ad.reserve(1000000000);
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    std::cout<<"Pushing.."<<std::endl;
    Ad.push_back(1.1);
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    std::cout<<"Clearing.."<<std::endl;
    Ad.clear();
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    std::cout<<"Resizing.."<<std::endl;
    Ad.resize(10);
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    Ad.shrink_to_fit();
    std::cout<<Ad.size()<<" "<<Ad.capacity()<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;
    
    
    std::cout<<"Doing D: "<<std::endl;
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    std::cout<<"Pushing.."<<std::endl;
    D.push_back(1.1);
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    std::cout<<"Pushing.."<<std::endl;
    D.push_back(1.1);
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    D.reserve(1000000000);
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    std::cout<<"Pushing.."<<std::endl;
    D.push_back(1.1);
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    std::cout<<"Clearing.."<<std::endl;
    D.clear();
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    std::cout<<"Resizing.."<<std::endl;
    D.resize(10);
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    D.shrink_to_fit();
    std::cout<<D.size()<<" "<<D.capacity()<<std::endl;
    
    return 0;
}
