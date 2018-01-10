//
// Created by danter on 2018-01-10.
//

#include <cstdlib>
#include <iostream>
#include "MergeSort.h"

void print(int *a, int num);

int
main (int argc, char **argv)
{
    int a[8] = {23, 398, 34, 100, 57, 67, 55, 320};

    print(a, 8);

    sort::MergeSort<int>(a, 8,0);
    print(a, 8);
    exit(0);
}

void print(int *a, int num) {
    std::cout << "[";
    for (int i = 0; i<num; ++i) {

        if (i != (num-1))
            std::cout << a[i] << ", ";
        else
            std::cout << a[i] << "]" << std::endl;
    }
}