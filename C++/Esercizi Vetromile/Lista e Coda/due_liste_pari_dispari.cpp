#include <iostream>

/**
 * @file due_liste_pari_dispari.cpp
 * @author Luca Facchini
 * @brief Crea un programma che gestisce due liste: 
 * una lista inizialmente piena e l'altra vuota. La prima lista dovrà avere solo i 
 * nodi dispari, mentre la seconda lista dovrà avere solo i nodi pari.
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */

int numNodi = 0;

class Nodo {
    public:
        int valore;
        Nodo* next;

        Nodo(int valore) : valore(valore), next(nullptr) {}
};

class Lista {
    private:
        Nodo* testa;

    public:
        Lista() : testa(nullptr) {}

        void inserimentoTesta(int valore) {
            Nodo* nuovo = new Nodo(valore);
            nuovo->next = testa;
            testa = nuovo;
            numNodi++;
        }


        /**
         * @brief Separa i nodi di una lista in due liste: una per i nodi nelle posizioni dispari 
         *        e una per i nodi nelle posizioni pari. (senza creare nuovi nodi)
         * 
         * la funzione itera su ciascun nodo della lista originale determinando la sua 
         * posizione. I nodi che si trovano in posizioni dispari vengono collegati alla 
         * lista dei nodi dispari , mentre i nodi che si trovano in posizioni pari 
         * vengono collegati alla lista dei nodi pari 
         * 
         * La funzione aggiorna i puntatori next dei nodi per separare fisicamente le due liste.
         * 
         * @param listaDispari La lista che conterrà i nodi nelle posizioni dispari.
         * @param listaPari La lista che conterrà i nodi nelle posizioni pari.
         * 
         * @details
         * 1. Inizializza un puntatore corrente che punta alla testa della lista originale.
         * 2. Inizializza due puntatori (prevDispari e prevPari) a nullptr, per tenere traccia
         *    dell'ultimo nodo aggiunto nelle  liste.
         * 3.   utilizza un contatore posizione che parte da 1, per tracciare la posizione del nodo 
         *    corrente nell'elenco.
         * 
         * 4. Per ogni nodo:
         *    - Se la posizione è dispari, il nodo viene aggiunto alla lista dispari e il puntatore 
         *      prevDispari viene aggiornato per farlo puntare al nodo appena aggiunto.
         * 
         *    - Se la posizione è pari, il nodo viene aggiunto alla lista pari e il puntatore 
         *      prevPari viene aggiornato
         * 
         * 5. Ogni volta che un nodo viene aggiunto a una delle due liste, il suo next viene settato 
         *    a nullptr per segnare la fine della lista.
         * 6. La funzione continua a scorrere la lista originale finché non raggiunge la fine.
         * 
         * @note La funzione non crea nuovi nodi, ma ricollega quelli esistenti nelle nuove liste.
         *       Alla fine della funzione, `listaDispari` e `listaPari` conterranno i nodi separati 
         *       dalle rispettive posizioni (dispari e pari).
         */
        void separaPariDispari(Lista& listaDispari, Lista& listaPari) {
            Nodo* corrente = testa;
            Nodo* prevDispari = nullptr;
            Nodo* prevPari = nullptr;
            int posizione = 1;

            while (corrente != nullptr) {



                Nodo* nextNodo = corrente->next;



                if (posizione % 2 != 0) {  // Posizione dispari
                    if (prevDispari != nullptr) {
                        prevDispari->next = corrente;
                    } else {
                        listaDispari.testa = corrente;
                    }
                    prevDispari = corrente;
                    corrente->next = nullptr; // termine lista


                } else {  // Posizione pari
                    if (prevPari != nullptr) {
                        prevPari->next = corrente;
                    } else {
                        listaPari.testa = corrente;
                    }
                    prevPari = corrente;
                    corrente->next = nullptr;  // term. lista
                }

                corrente = nextNodo;
                posizione++;
            }
        }

        void stampa() {
            Nodo* corrente = testa;
            while (corrente != nullptr) {
                std::cout << corrente->valore << " ";
                corrente = corrente->next;
            }
            std::cout << std::endl;
        }
};

int main() {
    Lista listaIniziale;
    listaIniziale.inserimentoTesta(1);
    listaIniziale.inserimentoTesta(4341);
    listaIniziale.inserimentoTesta(3);
    listaIniziale.inserimentoTesta(111);
    listaIniziale.inserimentoTesta(5);
    listaIniziale.inserimentoTesta(111);

    std::cout << "Lista iniziale: ";
    listaIniziale.stampa();

    Lista listaDispari;
    Lista listaPari;

    listaIniziale.separaPariDispari(listaDispari, listaPari);


    std::cout << "Lista originale : ";
    listaIniziale.stampa();
    
        std::cout << "Lista dispari :";
    listaDispari.stampa();

    std::cout << "Lista pari : ";
    listaPari.stampa();

    return 0;
}
