//
// Created by danter on 1/16/18.
//

#include <iostream>
#include "ArrayWrapper.h"

int main()
{
    wrapper::MetaData metaData {3, "Hej"};
    std::cout << "MD=:" << metaData << std::endl;
    std::cout << "getNme=:" << metaData.getName() << std::endl;
    std::cout << "getSize=:" << metaData.getSize() << std::endl;

    wrapper::ArrayWrapper a1{3, "A1"};
    std::cout << "a1=:" << a1 << std::endl;

    wrapper::ArrayWrapper a2{3, "A2"};
    std::cout << "a2=:" << a2 << std::endl;

    std::cout << "a1 = a2 calls " << std::endl;
    a1 = a2; // user-defined copy assignment

    std::cout << "a1=:" << a1 << std::endl;
    std::cout << "is_copy_assignable: " << std::is_copy_assignable<wrapper::ArrayWrapper>::value << std::endl;
    std::cout << "is_trivially: " << std::is_trivially_copy_assignable<wrapper::ArrayWrapper>::value << std::endl;
}
