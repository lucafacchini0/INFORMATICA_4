/**
 * @file separazione_liste.cpp
 * @author Luca Facchini
 * @brief Separa la prima lista dalla seconda; la prima lista deve avere solo i nodi
 * di posizione dispari, mentre la seconda lista deve avere solo i nodi di posizione
 * pari. 
 * 
 * Devi ricollegare i nodi sulla seconda lista, NON crearli nuovi.
 * @version 0.1
 * @date 2025-03-27
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include <iostream>

using namespace std;

class Nodo {
    public:
        int valore;
        Nodo* next;

        Nodo(int valore) : valore(valore) {}
};

class Lista {
    private:
        Nodo* testa;

    public:
        Lista() : testa(nullptr) {}

        Nodo* getTesta() { return testa; }
        void setTesta(Nodo* testa) { this->testa = testa; }

        void inserimentoTesta(int valore) {
            Nodo* nuovo = new Nodo(valore);
            nuovo->next = testa;
            testa = nuovo;

            cout << "Valore inserito." << endl;
        }

        Lista* dividiListaPariDispari() {
            Lista* pari = new Lista;

            if(!testa || !testa->next) return pari;

            // A questo punto del programma, sicuramente ci sono 
            // almeno due nodi.

            Nodo* q = testa; // Puntatore alla testa della prima lista
            Nodo* p = testa->next; // Puntatore al successivo rispetto a 'q'

            pari->setTesta(p); // Imposto la testa della seconda lista su 'p', il secondo nodo della lista principale.

            Nodo* appoggio = q; // Verrà utilizzato per fare i controlli sul successivo di q o p.

            bool q_or_p = false; // false: appoggio è su q -- true: appoggio è su p

            while(appoggio->next->next) {

                // Collego i nodi dispari / pari
                if(q_or_p == false) { // se 'appoggio' è sulla q
                    q->next = p->next;
                    appoggio = p;
                    q_or_p = true; // 'appoggio'si sposta su p
                    q = q->next;
                } else { // se 'appoggio' è sulla p
                    p->next = q->next;
                    appoggio = q;
                    q_or_p = false; // 'appoggio' si sposta sulla q
                    p = p->next;
                }
            }

            // Scollego l'ultimo nodo della lista
            if(q_or_p == false) { // se è su q, ovvero la lista originale ha x nodi (x pari)
                q->next = nullptr;
            } else { // se è su q, ovvero la lista originale ha x nodi (x dispari)
                p->next = nullptr;
            }

            return pari;
        }

        void stampa() {
            Nodo* temp = testa;

            while(temp) {
                cout << "[" << temp->valore << "] ";
                temp = temp->next;
            }

            cout << endl;
        }
};

int main() {
    Lista lista;

    lista.inserimentoTesta(20);
    lista.inserimentoTesta(33);
    lista.inserimentoTesta(10);
    lista.inserimentoTesta(248);
    lista.inserimentoTesta(213);
    lista.inserimentoTesta(192);
    lista.inserimentoTesta(1293);
    lista.inserimentoTesta(1442); 
    lista.inserimentoTesta(3);
    //nodi pari (IGNORA)
   // lista.inserimentoTesta(200);

    cout << "\n\nOriginale\n";
    lista.stampa();

    cout << "\n\n\nLe due liste dopo la funzione\n" << endl;
    Lista* nuovaLista = lista.dividiListaPariDispari();

    lista.stampa();
    cout << endl;
    nuovaLista->stampa();
};
