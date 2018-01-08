//
// Created by danter on 2018-01-08.
//

#ifndef C_EXPERIMENTS_C_H
#define C_EXPERIMENTS_C_H

#include "A.h"

namespace ABC {

    class C: public A {
    public:
        C(int _a, int _b, int _c) : A(_a, _b, _c) {
            std::cout << " C::C(" << _a << "," << _b << "," << _c << ")" << std::endl;
        }

        void toString(std::ostream& os) const override {
            os << "ABC::C@" << this << "{a:";
            os << _a;
            os << " b:";
            os << _b;
            os << " c:";
            os << _c << "}";
        }

        void adjust_values(int i ) override {
            _a = _a + i, _b = _b + i, _c = _c + i;
            std::cout << " C::adjust_values() _a = " << _a  << "\n" ;
        }

        int calc () const override {
            std::cout << " C::calc()" << std::endl;
            return 2;
        }
    };


} // namespace

#endif //C_EXPERIMENTS_C_H
