#include <iostream>
using namespace std;
class Complex {
    double re;
    double im;
    public:
        Complex(double r, double i):re(r),im(i){}

    operator float(){
        return re;
    }

};

int main(void){
float x; 
Complex y=Complex(1.0,2.0);
x=y+6.7;
std::cout << "x = " << x << std::endl;

}