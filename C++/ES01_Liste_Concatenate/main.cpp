#include "lista.h"

int main() {
    Lista lista;

    lista.inserisciInTesta(10);
    lista.visualizza();
    lista.inserisciInTesta(100);
    lista.visualizza();
    lista.inserisciInTesta(1000);
    lista.visualizza();
    lista.inserisciInCoda(1000);
    lista.visualizza();
    lista.inserisciInCoda(1000);
    lista.visualizza();
    lista.inserisciInCoda(1000);
    lista.visualizza();
    lista.rimuoviDuplicati();
    lista.visualizza();
    lista.elimina(100);
    lista.visualizza();

    return 0;
}
