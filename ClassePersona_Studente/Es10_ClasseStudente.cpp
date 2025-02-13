#include <iostream>
//using namespace std;

class Studente{
    char* nome;
    char* cognome;
    int matricola;
    public:
        Studente(const char* n, const char* c, int m)
        {
            matricola = m; //Oppure dopo Studente (...) dichiarare ": matricola(m)"
            int lunghezzaNome = 0;
             int lunghezzaCognome = 0;
            const char* p1 = n;
            const char* p2 = c;
            while (*p1 != '\0')
            {
                p1++;
                lunghezzaNome++;
            }
            nome = new char[lunghezzaNome + 1];
            p1 = n;
            for (int i = 0; i < lunghezzaNome; i++)
            {
                nome[i] = *p1;
                p1++;
            }
            nome[lunghezzaNome] = '\0'; //In alternativa: *nome = *n (dopo il while punta all'ultimo elemento)
            while (*p2 != '\0')
            {
                p2++;
                lunghezzaCognome++;
            }
            cognome = new char[lunghezzaCognome + 1];
            p2 = c;
            for (int i = 0; i < lunghezzaCognome; i++)
            {
                cognome[i] = *p2;
                p2++;
            }
            cognome[lunghezzaCognome] = '\0';
        }

    ~Studente() {
        delete[] nome;
        delete[] cognome;
    }

    //Dichiarando friend possiamo utilizzarla fuori dalla classe e senza
    friend std::ostream& operator<<(std::ostream& os, const Studente& s); 
};

std::ostream& operator<<(std::ostream& os, const Studente& s){
    return os<< "Nome:"<<s.nome<<'\n'<<"Cognome:"<<s.cognome<<'\n'<<"Matricola:"
           <<s.matricola<<'\n';
};


int main(){
    Studente s("Marco", "Bianchi", 77543);
    std::cout<<s;
    return 0;
}