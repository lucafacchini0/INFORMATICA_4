#include <iostream>
#include <string>

class Persona {
    public:

        Persona() {
            std::cout << "ciao" << std::endl;
        }

        Persona(std::string nome, int eta, int giorno, int mese, int anno) {
            this->nome = nome;
            this->eta = eta;

            this->dataNascita.giorno = giorno;
            this->dataNascita.mese = mese;
            this->dataNascita.anno = anno;
        }

        void stampa() {
            std::cout << nome << std::endl;
            std::cout <<  eta << std::endl;
            std::cout << dataNascita.giorno << std::endl;
            std::cout << dataNascita.mese << std::endl;
            std::cout <<  dataNascita.anno << std::endl;

        }


    private:
        std::string nome;
        int eta;
        
        typedef struct {
            int giorno;
            int mese;
            int anno;
        } Data;

        Data dataNascita;
};

int main() {
    Persona necker;
    Persona necker1("Luca", 90, 16, 10, 2007);

    necker1.stampa();
}