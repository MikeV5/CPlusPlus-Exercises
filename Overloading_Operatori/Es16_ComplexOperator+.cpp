#include <iostream>
using namespace std;
class Complex {
    double re;
    double im;

public:
    Complex(double r, double i):re(r),im(i){}
    friend Complex operator+(const Complex& a, const Complex& b);
    friend ostream& operator<<(std::ostream& os, const Complex& c);
};

Complex  operator+(const Complex& a, const Complex& b){
    return Complex(a.re+b.re,a.im+b.im);
}
ostream& operator<<(std::ostream& os, const Complex& c){
    return os<<"("<<c.re<<","<<c.im<<")";
}

int main(void){
Complex a(1.1,2.2);
Complex b(1.1,2.2);
Complex c(1.1,2.2);
a = b+c;
cout<<a;

}