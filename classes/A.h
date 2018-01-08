//
// Created by danter on 2018-01-08.
//

#ifndef C_EXPERIMENTS_A_H
#define C_EXPERIMENTS_A_H

#include <iostream>
namespace ABC {
    class A {
    public:
        A(int _a, int _b, int _c) : _a(_a), _b(_b), _c(_c) {
            std::cout << " A::A(" << _a << "," <<  _b << "," <<  _c << ")" << std::endl;
        }

        virtual ~A() {
            std::cout << " A::~A()" << std::endl;
        }

        A& operator=(const A& a)  {
            std::cout << "A& A::operator=(const &A) =>" << std::endl;
            adjust_values(a.calc());
            std::cout << "A& A::operator=(const &A) => done" << std::endl;
            return *this;
        }

        virtual void adjust_values(int i) = 0;

        virtual int calc() const  = 0;

        virtual void toString(std::ostream&) const = 0;

        int getA() const { return _a; };
        int getB() const { return _b; };
        int getC() const { return _c; };

    protected:
        int _a;
        int _b;
        int _c;
    };

    std::ostream& operator<<(std::ostream& os, const A& d) {
        d.toString(os);
        return os;
    }
}

#endif //C_EXPERIMENTS_A_H
