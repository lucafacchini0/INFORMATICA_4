#ifndef LISTA_H
#define LISTA_H

/**
 * @file lista.h
 * @author Luca Facchini
 * @brief Definizione della struttura dati della Lista e della classe Nodo.
 * 
 * Questa libreria fornisce l'implementazione di una lista concatenata singola.
 * Possibilità di: inserire, eliminare, cercare nodi e rimuovere duplicati.
 * La lista è composta da nodi che memorizzano un valore intero e un puntatore al nodo successivo.
 * 
 * @version 1.0
 * @date 2025-03-11
 * @copyright Copyright (c) 2025 Luca Facchini
 */

#include <iostream>
#include <unordered_set>

/**
 * @class Nodo
 * @brief Rappresenta un nodo di una lista concatenata.
 * 
 * La classe Nodo ricordiamo essere una struttura di base per costruire una lista concatenata. Ogni nodo
 * contiene un valore intero e un puntatore al nodo successivo, che permette proprio di navigare
 * attraverso la lista. Se il nodo è l'ultimo della lista, il puntatore al successivo sarà nullptr.
 */
class Nodo {
    public:
        /**
         * @brief Valore contenuto nel nodo
         * 
         * Questo campo memorizza il dato associato al nodo della lista. Può essere utilizzato
         * per memorizzare qualsiasi valore numerico intero desiderato. Nell'esercizio del prof. Bilardo,
         * il valore è un intero.
         */
        int valore;

        /**
         * @brief Puntatore al nodo successivo nella lista.
         * 
         * Questo puntatore permette di collegare il nodo al nodo successivo nella lista concatenata.
         * Se il nodo è l'ultimo della lista, il puntatore sarà nullptr (implementato nella classe Lista).
         */
        Nodo* next;
};

/**
 * @class Lista
 * @brief Implementazione di una lista concatenata.
 * 
 * La classe Lista fornisce operazioni per manipolare una lista concatenata singola. 
 * È possibile inserire nodi in testa o in coda, eliminare nodi, cercare un valore, visualizzare
 * la lista, contare il numero di nodi e rimuovere i duplicati. 
 */
class Lista {
    private:
        /**
         * @brief Puntatore al primo nodo della lista.
         * 
         * Questo puntatore rappresenta la testa della lista concatenata. Se la lista è vuota,
         * il valore di questo puntatore sarà nullptr. La testa è come un punto di accesso alla lista.
         * Come la "root" del filesystem, ma al contrario.
         */
        Nodo* head;

    public:
        /**
         * @brief Costruttore della classe Lista.
         * 
         * Il costruttore inizializza il puntatore head a nullptr; la lista inizia vuota.
         */
        Lista();

        /**
         * @brief Inserisce un nodo con valore in testa alla lista.
         * 
         * Questa funzione crea un nuovo nodo con il valore passato come parametro e lo inserisce
         * all'inizio della lista. Gli altri nodi vengono spostati di una posizione verso destra.
         * L'head della lista viene aggiornato con il nuovo nodo, di per sè diventando la nuova testa.
         * 
         * @param val Il valore intero da inserire nel nuovo nodo.
         */
        void inserisciInTesta(int val);

        /**
         * @brief Inserisce un nodo con valore in coda alla lista.
         * 
         * Questa funzione crea un nuovo nodo con il valore passato come parametro e lo inserisce
         * alla fine della lista. Se la lista è vuota, il nuovo nodo diventa la testa della lista.
         * 
         * @param val Il valore intero da inserire nel nuovo nodo.
         */
        void inserisciInCoda(int val);

        /**
         * @brief Elimina il nodo con un valore specifico dalla lista.
         * 
         * Questa funzione cerca e rimuove il primo nodo che contiene il valore specificato. Se il valore
         * non è presente nella lista, la lista rimane invariata.
         * 
         * @param val Il valore intero del nodo da eliminare.
         */
        void elimina(int val);

        /**
         * @brief Ricerca un nodo con un valore specifico.
         * 
         * Questa funzione verifica se un nodo con il valore specificato è presente nella lista.
         * 
         * @param val Il valore intero da cercare nella lista.
         * @return true Se il valore è presente nella lista.
         * @return false Se il valore non è presente nella lista.
         */
        bool ricerca(int val);

        /**
         * @brief Visualizza tutti i nodi della lista.
         * 
         * Questa funzione stampa i valori di tutti i nodi nella lista, partendo dalla testa e proseguendo
         * fino all'ultimo nodo. 
         */
        void visualizza();

        /**
         * @brief Conta il numero di nodi nella lista.
         * 
         * Questa funzione restituisce il numero di nodi presenti nella lista concatenata.
         * 
         * @return int Il numero di nodi presenti nella lista.
         */
        int contaNodi();

        /**
         * @brief Rimuove i duplicati dalla lista.
         * 
         * Questa funzione rimuove i nodi con valori duplicati dalla lista. Utilizza una struttura dati 
         * come unordered_set per tracciare i valori già incontrati e rimuovere quelli ripetuti.
         */
        void rimuoviDuplicati();

        /**
         * @brief Distruttore della classe Lista.
         * 
         * Il distruttore dealloca tutta la memoria utilizzata dai nodi della lista concatenata,
         * liberando le risorse. Viene invocato automaticamente quando l'oggetto Lista esce dallo scope.
         */
        ~Lista();
};

#endif // LISTA_H
