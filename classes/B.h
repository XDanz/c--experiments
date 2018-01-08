//
// Created by danter on 2018-01-08.
//

#ifndef C_EXPERIMENTS_B_H
#define C_EXPERIMENTS_B_H

#include "A.h"

namespace ABC {
    class B: public A {
    public:

        B(int _a, int _b, int _c) : A(_a, _b, _c) {
            std::cout << "  B::B(" << _a << "," <<  _b << "," <<  _c << ")" << std::endl;
        }

        virtual ~B() {
            std::cout << " B::~B()" << std::endl;
        }

        virtual void toString(std::ostream& os) const {
            os << "ABC::B@" << this;
            os << "{a:";
            os << _a;
            os << " b:";
            os << _b;
            os << " c:";
            os << _c << "}";
        }

        int calc() const override {
            std::cout << " B::calc() _a = " << _a  << "\n" ;
            return 1;
        }
        void adjust_values(int i) override {
            _a = _a + i, _b = _b + i, _c = _c + i;
            std::cout << " B::adjust_values(" << i << "): a=" << _a << ", b=" << _b << " , c=" << _c << std::endl;
        }

        A& operator=(const A& a) {
            std::cout << " A& B::operator(const A&) =>" << std::endl;
            this->A::operator=(a);
            std::cout << " A& B::operator(const A&) => done" << std::endl;
            return *this;
        }
    };
}
#endif //C_EXPERIMENTS_B_H
