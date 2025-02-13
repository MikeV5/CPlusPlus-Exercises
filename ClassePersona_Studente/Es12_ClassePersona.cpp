#include <iostream>

class Persona{
    char* nome;
    char* cognome;
    int matricola;
    public:
        Persona(const char* name,const char* surname, int m){
            matricola = m;
            const char* p1 = name;
            const char* p2 = surname;
            int lunghNome=0;
            int lunghCognome=0;
            while(*p1!='\0'){
                p1++;
                lunghNome++;
            };
            nome = new char[lunghNome+1]; //+1 per il terminatore
           
            char* tempNome = nome; // Puntatore temporaneo per copia, 
                    //Errore  se coppiamo direttamente da name a nome senza tempNome
            while (*name != '\0'){
                *tempNome = *name;
                tempNome++;
                name++;
            }
             *tempNome = *name; // Terminatore per nome, oppure *tempNome = '\0';
/*
            //Oppure un ciclo for
            p1 = name;        // Ripristina il puntatore p1 all'inizio di name
            for (int i = 0; i < lunghNome; i++)
            {
                nome[i] = *p1;
                p1++;
            }
*/
            while(*p2!='\0'){
                p2++;
                lunghCognome++;
            };
            cognome = new char[lunghCognome+1]; //+1 per il terminatore
            char* tempCognome = cognome; 
            while (*surname != '\0'){
                *tempCognome = *surname;
                tempCognome++;
                surname++;
            }
             *tempCognome = *surname; // Terminatore per nome, oppure *tempCognome = '\0';
        };
        friend std::ostream& operator<<(std::ostream& os, const Persona& p);
};

std::ostream& operator<<(std::ostream& os, const Persona& p){
    return os<<"Nome:"<<p.nome<<"\n"<<"Cognome:"<<p.cognome<<"\n"
          <<"Matricola:"<<p.matricola<<"\n";
}

int main(){
    //char nome[] = "Fabio";
    //char cognome[]="Rossi";
    //Persona p(nome,cognome,75643); //Senza const, questo è l'unico modo di passare parametri  
    Persona p("Fabio","Rossi",75643); //Con const si soluziona
    std::cout<<p;
    return 0;
}