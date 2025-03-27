/**
 * @file pila_OOP.cpp
 * @author Luca Facchini
 * @brief Implementa una pila in C++ utilizzando la programmazione ad oggetti
 * @version 0.1
 * @date 2025-02-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

class Nodo {
    public:
        int info;
        Nodo* next;
};

class Pila {
    private:
        Nodo* testa; // La testa identifica il primo nodo della pila, o "la cima" della pila
    public:
        Pila() {
            testa = nullptr; // Inizializzo la testa a nullptr, ciò significa che la pila è vuota, il nodo iniziale non esiste
        }

        void aggiungiNodoTesta(int num) {
            Nodo* successivo; // Dichiaro un puntatore ad un nodo. Questo nodo sarà il nodo successivo a quello che sto inserendo
            successivo = new Nodo(); // assegno l'indirizzo di new Nodo() a successivo

            successivo->info = num;
            successivo->next = testa;
            testa = successivo;
        }

        void stampaLista() {
            Nodo* q = testa;

            while(q != nullptr) {
                std::cout << q->info << std::endl;
                q = q->next;
            }
        }
};

int main() {
    bool scelta = false;
    Pila pila;

    do {
        std::cout << "inserisci un numero nella lista: " << std::endl;
        
        int num;
        std::cin >> num;

        pila.aggiungiNodoTesta(num);

        std::cout << "Continuare? y/n" << std::endl;
        char sceltaChar;
        std::cin >> sceltaChar;

        if(sceltaChar == 'y' || sceltaChar == 'Y') {
            scelta = true;
        } else {
            scelta = false;
        }
        
    }while(scelta == true);

    pila.stampaLista();
}