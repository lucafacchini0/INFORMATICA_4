/**
 * @file lista_OOP.cpp
 * @author Luca Facchini
 * @brief Una lista implementata in C++ utilizzando la programmazione ad oggetti.
 * @version 0.1
 * @date 2025-03-05
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

class Lista {
    private:
        Nodo* testa;
    public:
        Lista() {
            testa = nullptr;
        }

        void aggiungiNodoTesta(int num) {
            Nodo *successivo;
            successivo = new Nodo();

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