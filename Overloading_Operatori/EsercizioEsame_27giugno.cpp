#include <iostream>

class Stringa{
public:
    Stringa(char c);
    Stringa(char *s);
    int size() { return length; };
    friend Stringa& operator-(Stringa& s);
    void stampa(){
        std::cout<<st;
    }
    char *stampa2(){
        int i = 0;
        char *tmp;
        tmp = new char[size() + 1];

        int n = size() - 1;
        while (n >= 0){
            tmp[i] = st[n];
            i++;
            n--;
        }
        tmp[i] = '\0';
        return tmp;
    }

private:
    char *st;
    int length;
};

Stringa::Stringa(char c){
    st = new char[2];
    st[0] = c;
    st[1] = '\0';
    length = 1;
}

Stringa::Stringa(char *c){
    int count = 0;
    char *ptr = c;
    if (c == NULL){
        st = c;
        return;
    }
    while (*c != '\0'){
        count++;
        c++;
    }

    st = new char[count + 1];
    length = count;
    while (count >= 0){
        st[count] = ptr[count];
        count--;
    }
};

Stringa& operator-(Stringa& s){

    char c;
    int i = 0;
    int j = s.size();
    j--;
    while (i < j){
        c = s.st[i];
        s.st[i] = s.st[j];
        s.st[j] = c;
        i++;
        j--;
    }

    return s;

    /*
      int count = s.size();
      char* tmp;
      tmp = new char[count+1];
       // Copia s.st in tmp
       for (int i = 0; i < count; i++) {
           tmp[i] = s.st[i];
       }

       int n = s.size()-1;
       int i = 0;
       while (n >= 0){
           s.st[i] = tmp[n];
           i++;
           n--;
       }
       return s;
       */
}







int main(){
    char nome[] = "Matteo";
    Stringa s(nome);
    Stringa p = -s;

    // Utilizzo di stampa2() per ottenere la stringa invertita
    //char* invertedString = s.stampa2();
    //std::cout << invertedString;
    p.stampa();
    //s.stampa();
    //std::cout << s.stampa2(); 
    //delete[] invertedString;
  return 0;
}