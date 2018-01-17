//
// Created by danter on 1/16/18.
//

#include "MoveA.h"

std::string getName() {
    return "Daniel";
}

void printReference(const std::string& str) {
    std::cout << "ref: " << str << std::endl;
}

void printReference(std::string&& str) {
    std::cout << "rval: " << str << std::endl;
}

int main()
{
    // move-construct from rvalue temporary
    std::string str("Dan");
    printReference(getName());
    return 0;
}