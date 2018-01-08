//
// Created by danter on 2018-01-08.
//

#include <iostream>
#include "B.h"


int 
main (int argc , char** argv) 
{
    std::cout << "create B (b1) ABC::B b1{1,2,3};" << std::endl;
    ABC::B b1{1,2,3};
    std::cout << "b1 = " << b1 << std::endl;

//    std::cout << "create B (b2) ABC::B b2{2,3,4};" << std::endl;
//    ABC::B b2{2,3,4};
//    std::cout << "b2 = " << b2 << std::endl;
//
//    std::cout << "create C (c1)" << std::endl;
//    ABC::C c1{11,22,33};
//    std::cout << " c1 = " << c1 << std::endl;
//
//    std::cout << "Assignment b1=c1" << std::endl;
//    b1 = c1;
//    std::cout << " b1= " << b1 << std::endl;
//
//    b1 = b2;
//    std::cout << "b1 = " << b1 << std::endl;

    return 0;
}