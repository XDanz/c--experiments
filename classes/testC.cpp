#include <iostream>
#include "A.h"
#include "B.h"
#include "C.h"

using namespace std;


int
main (int argc , char** argv)
{
    std::cout << "create b1" << std::endl;
    ABC::B b1 {1,2,3};
    std::cout << "create c1" << std::endl;

    ABC::C c1 {1,2,3};
    std::cout << "Assignment b1 = c1" << std::endl;
    b1 = c1;
    std::cout << "b1 = " << b1 << std::endl;
    return 0;
}
