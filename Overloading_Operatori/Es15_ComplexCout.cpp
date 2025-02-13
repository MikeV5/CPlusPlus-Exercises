#include <iostream>

using namespace std;
class Complex {
    double re;
    double im;

public:
    Complex(double r, double i):re(r),im(i){}
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

ostream& operator<<(std::ostream& os, const Complex& c){
    return os<<"("<<c.re<<","<<c.im<<")";
}

int main(void){
    Complex a(1.1,2.2);
    cout<<a;
}