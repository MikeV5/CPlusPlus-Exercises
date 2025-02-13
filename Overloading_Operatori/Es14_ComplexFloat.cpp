#include <iostream>

class Complex {
    float re;
    float imm;

public:
    Complex(float a, float b){
        re = a;
        imm = b;
    };

  operator float() const {
    return re;
  }

};
int main(){
  float x;
  Complex y = Complex(1.0, 2.0);
  x = 3.7 - y; //y viene trasformato a float
  std::cout << "x = " << x << std::endl;

  return 0;
}