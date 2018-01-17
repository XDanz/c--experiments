//
// Created by danter on 1/16/18.
//

#ifndef C_EXPERIMENTS_MOVEA_H
#define C_EXPERIMENTS_MOVEA_H


#include <iostream>
#include <string>


class MoveA
{
public:
    // default constructor
    MoveA() : s("default") {
        std::cout << "Default constructur!" << std::endl;
    }

    // copy constructor
    MoveA(const MoveA& o) : s(o.s) { std::cout << "move failed!\n";}

    // move constructor
    MoveA(MoveA&& o) : s(std::move(o.s)) {}

    std::string printObj() { return s; }
private:
    std::string s;
};

MoveA temp(MoveA a) {
    return a;
}




#endif //C_EXPERIMENTS_MOVEA_H
