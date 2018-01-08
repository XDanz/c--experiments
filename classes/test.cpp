#include <iostream>
using namespace std;

namespace ABC {
    class A {
    public:
        A(int _a, int _b, int _c) : _a(_a), _b(_b), _c(_c) {
            cout << " A::A(int,int,int)" << endl;
        }

        A& operator=(const A& a)  {
            cout << "A::operator=(const &A) =>" << endl;
            this->adjust_values(a.calc());
            cout << "A::operator=(const &A) => ok" << endl;
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

    class C;

    class B: public A {
    public:

        B(int _a, int _b, int _c) : A(_a, _b, _c) {
            cout << "  B::B(int,int,int)" << endl;
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
    
        int calc  ( ) const {
            std::cout << " B::calc() _a = " << _a  << "\n" ;
            return 1;
        }
        void adjust_values(int i ) {
            _a = _a+i, _b = _b + i, _c = _c + i;
            std::cout << " B::adjust_values(" << i << ") " << std::endl;
        }

        A& operator=(const A& a) {
            std::cout << "in A& B::operator(const A&) =>\n";
            this->A::operator=(a);
            //adjust_values(a.calc());
            std::cout << "in A& B::operator(const A&) => ok\n";
            return *this;
        }
    };


    class C: public A {
    public:
        C(int _a, int _b, int _c) : A(_a, _b, _c) {
            cout << " C::C(int,int,int)" << endl;
        }

        void toString(std::ostream& os) const {
            os << "ABC::C@" << this << "{a:";
            os << _a;
            os << " b:";
            os << _b;
            os << " c:";
            os << _c << "}";
        }

        void adjust_values(int i ) {
            _a = _a+i, _b = _b + i, _c = _c + i;
            std::cout << " C::adjust_values() _a = " << _a  << "\n" ;
        }

        int calc () const {
            std::cout << " C::calc() _a = " << _a  << "\n" ;
            return 2;
        }
    };

    std::ostream& operator<<(std::ostream& os, const A& d) {
        d.toString(os);
        return os;
    }
} // namespace


int main (int argc , char** argv) {
    std::cout << "create B (b1)" << std::endl;
    ABC::B b1{1,2,3};
    std::cout << " b1 = " << b1 << std::endl;

    std::cout << "create B (b2)" << std::endl;
    ABC::B b2{2,3,4};
    std::cout << "b2 = " << b2 << std::endl;

    std::cout << "create C (c1)" << std::endl;
    ABC::C c1{11,22,33};
    std::cout << " c1 = " << c1 << std::endl;

    std::cout << "Assignment b1=c1" << std::endl;
    b1 = c1;    
    std::cout << " b1= " << b1 << std::endl;

    b1 = b2;
    std::cout << "b1 = " << b1 << std::endl;

    return 0;
}
