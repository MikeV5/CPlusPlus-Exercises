#include <iostream>

class A {
public:
  void stampa(){
    std::cout<<"A";
  }
};

class B {
public:
  void stampa(){
    std::cout<<"B";
  }
};

class C: public  A, public B {

};

int main() {
  C c;
 // c.stampa(); //Errore di compilazione: ambiguità
  return 0;
}
