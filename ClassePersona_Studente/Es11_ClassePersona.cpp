#include <iostream>
#include <cstring>

using namespace std;
class Persona{
    char nome[10];
    char cognome[20];
    public:
        Persona(char* name, char* surname){
            int i=0;
            while(name[i]!='\0' && i<9){
                nome[i]=*name;
                name++;
                i++;
            }
            nome[i]= '\0';
        }
    
        
        friend ostream& operator<<(ostream& os, const Persona& p);
};
/*
Persona::Persona(const char* name, const char* surname) { 
        //Esempio di implementazione altrimenti dovremmo scorrere ogni array(name e surname)
        strncpy(nome, name, 9);
        nome[9] = '\0'; // Assicurarsi che il nome sia terminato correttamente
        strncpy(cognome, surname, 19);
        cognome[19] = '\0'; // Assicurarsi che il cognome sia terminato correttamente
}*/


ostream& operator<<(ostream& os, const Persona& p){
    return os<<"Nome: "<<p.nome<<"\n"<<"Cognome: "<<p.cognome<<"\n";
};

int main(){
    char nome[]="123456789";
    char cognome[]="Rossi";
    cout<<strlen(nome)<<'\n';
    Persona p(nome,cognome);
    cout << p;
    return 0;
}