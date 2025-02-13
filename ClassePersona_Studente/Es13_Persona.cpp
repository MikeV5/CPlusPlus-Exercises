#include <iostream>

class Persona{
    char* nome;
    char* cognome;
    public:
        Persona(char* n, char* c);
        friend std::ostream& operator<<(std::ostream& os, const Persona& p);

};
//La funzione operatore deve essere definita amica(friend) per poter accedere 
//agli attributi privati della classe Persona

Persona::Persona(char* n, char* c){
    char* p1 = n;
    char* p2 = c;
    int lunghN=0;
    int lunghC=0;
    while(*p1!='\0'){
        p1++;
        lunghN;
    }
    nome = new char[lunghN+1];
    char *tempN = nome;
    while (*n != '\0'){
        *tempN = *n;
        tempN++;
        n++;
    }
    *tempN = *n;

    while(*p2!='\0'){
        p2++;
        lunghC;
    }
    cognome = new char[lunghC+1];
    char *tempC = cognome;
    while (*c != '\0'){
        *tempC = *c;
        tempC++;
        c++;
    }
    *tempC = *c;
};
std::ostream& operator<<(std::ostream& os, const Persona& p){
    return os<<"Nome: "<<p.nome<<"\n"<<"Cognome: "<<p.cognome<<"\n";
};

int main(){
    char nome[]="Paolo";
    char cognome[]="Rossi";
    //Persona studente = Persona("Paolo","Rossi");
    Persona studente = Persona(nome,cognome);
    std::cout<<studente;
    return 0;
}