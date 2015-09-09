//
//  Created by Aditya Atluri on 9/9/15.
//  Copyright © 2015 Aditya Atluri. All rights reserved.
//

#include <iostream>
#include <string>
#include "vulpes.hpp"
#include <vector>

/*
This program is to check the functionality of swap
against two vulpes::vectors
*/

int main(int argc, const char * argv[]) {
    const int l1 = 10;
    const int l2 = 20;
    std::vector<float,aligned_allocator<float>> V1(l1);
    std::vector<float,aligned_allocator<float>> V2(l2);
    
    vulpes::vector<float>V1d(V1);
    vulpes::vector<float>V2d(V2);
    
    vulpes::fill(V1d.begin(), V1d.end(), 10.0f);
    V2d.swap(V1d);
    
    std::cout<<V2d[l1-1]<<" "<<V2d[l2-1]<<std::endl;
    
    vulpes::fill(V2d.begin(), V2d.end(), 11.0f);
    V1d.swap(V2d);
    
    std::cout<<V1d[l1-1]<<std::endl;
    
    return 0;
}
