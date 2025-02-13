#include <iostream>
using namespace std;



class Persona{
    char* nome;
    char* cognome;
    static int cnt;
    public:
        static int in_vita(){return cnt;}; //siccome static per la chiamata basta
                                            //Persona::in_vita e non p.in_vita()
        Persona(char* name,char* surname){
            //Puntatori temporali per ricavare la lunghezza di loro e poter creare i vettori
            char* p1= name;
            char* p2= surname;
            int contName=0;
            while(*p1 != '\0'){
                p1++; //Mi sposto di un carattere nell'array
                contName++;
            };
            nome = new char[contName+1]; //+1 per il terminatore(ancora non lo mettiamo)
            while(*name !='\0'){
                *nome = *name; 
                name++; //Sposto il vettore
                nome++; //Sposto il vettore
            };
            //Ora si posso chiudere il primo vettore nome
            //Siccome entrambi puntavano precedentemente all'ultimo elemento, basta fare:
            *nome = *name; 

            int contCognome=0;
            while(*p2 != '\0'){
                p2++; //Mi sposto di un carattere nell'array
                contCognome++;
            };
            cognome = new char[contCognome+1]; //+1 per il terminatore(ancora non lo mettiamo)
            while(*surname !='\0'){
                *cognome = *surname; 
                surname++; //Sposto il vettore
                cognome++; //Sposto il vettore
            };
            //Ora si posso chiudere il secondo vettore cognome
            //Siccome entrambi puntavano precedentemente all'ultimo elemento, basta fare:
            *cognome = *surname; 
            cnt++; //Passo più importante: +1 oggetto
        };
        friend std::ostream& operator<<(std::ostream& os, const Persona& p);
        //Distruttore per diminuire di 1 gli oggetti esistenti
        ~Persona(){
            delete[] nome;
            delete[] cognome;
            cnt--; //Importante: -1 oggetto
        };
};
int Persona::cnt=0; //Inizializzazione della variabile statica (fuori dalla classe)
    std::ostream& operator<<(std::ostream& os, const Persona& p){
    return os<<"Nome:"<<p.nome<<"\n"<<"Cognome:"<<p.cognome<<"\n";
};


int main(){
    char nome[] = "Miguel";
    char cognome[]="Valerio";
    Persona p(nome,cognome);
    cout<< Persona::in_vita()<<endl;
    Persona p1(nome,cognome);
    p.~Persona(); //In realtà anche mettendo p1 il contatore oggetti diminusice di uno perché statico
   // p.~Persona(); //Prova che anche se non metto p1 diminuisce il contatore
    cout<< Persona::in_vita();
    cout<<p1;
    
    return 0;
};