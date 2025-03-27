/**
 * @file pila.cpp
 * @author Luca Facchini
 * @brief Implementazione della pila in C++
 * @version 0.1
 * @date 2025-02-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <iostream>

void aggiungiNodoTesta(Nodo*);

typedef struct {
    int info;   
    Nodo* next;
} Nodo;

int main() {
    bool scelta = false;

    do {
        std::cout << "Inserisci un numero nella lista: " << std::endl;
        
        int num;
        std::cin >> num;

        Nodo* pila = aggiungiNodoTesta(pila, num);

        std::cout << "Continuare? y/n" << std::endl;
        int sceltaChar;
        std::cin >> sceltaChar;

        if(sceltaChar == 'y' || sceltaChar == 'Y') {
            scelta = true;
        } else {
            scelta = false;
        }
        
    }while(scelta == true);
}

Nodo* aggiungiNodoTesta(Nodo* pila, int num) {
    Nodo *successivo;
    successivo = new Nodo();

    successivo->info = num;
    successivo->next = pila;
    pila = successivo;

    return pila;

}

void stampaPila(Nodo* pila) {
    Nodo* q = pila;

    while(q != nullptr) {
        std::cout << q->info << std::endl;
        q = q->next;
    }
}