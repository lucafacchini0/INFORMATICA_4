#include "lista.h"

Lista::Lista() {
    /* 
    Inizialmente la lista è vuota, quindi l'head è nullptr.
    Head, che è un puntatore al primo nodo della lista, ora è nullptr.
    */
    this->head = nullptr;
}

void Lista::inserisciInTesta(int val) {
    /*
    nuovoNodo è un puntatore a un Nodo. Lo assegno a new Nodo;
    succede che nella memoria heap viene allocato spazio per un nuovo nodo,
    e il puntatore nuovoNodo punta a questo spazio. (gli viene proprio
    assegnato l'indirizzo di memoria del nuovo nodo)
    */
    Nodo* nuovoNodo = new Nodo;

    /*
    assegno i valori al nuovo nodo. Il valore del nodo è il valore passato
    */
    nuovoNodo->valore = val;
    nuovoNodo->next = head;

    /*
    Importantissimo: l'head, che è l'attributo privato della classe Lista,
    diventa il nuovoNodo. Questo significa che il nuovo nodo diventa la testa!

    Ogni volta che chiamiamo questo metodo, nuovoNodo->next sarà l'head precedente,
    e di per se si andrà a creare una lista concatenata.
    */
    head = nuovoNodo;
}

void Lista::inserisciInCoda(int val) {
    /*
    nuovoNodo è un puntatore a un Nodo. Lo assegno a new Nodo;
    succede che nella memoria heap viene allocato spazio per un nuovo nodo,
    e il puntatore nuovoNodo punta a questo spazio. (gli viene proprio
    assegnato l'indirizzo di memoria del nuovo nodo)
    */
    Nodo* nuovoNodo = new Nodo;

    /*
    Il valore del nuovo nodo è il valore passato come parametro.
    */
    nuovoNodo->valore = val;

    /*
    Attenzione: nel caso di inserimento in coda, è diverso rispetto all'inserimento in testa.

    Nell'inserimento in testa, il nuovo nodo diventa la testa, quindi il suo next è l'head precedente.
    Nell'inserimento in coda, il nuovo nodo diventa l'ultimo nodo, non più il primo. Quindi,
    se head è nullptr, il nuovo nodo diventa la testa. Altrimenti, scorro la lista fino all'ultimo
    */
    if (head == nullptr) {
        head = nuovoNodo;
        return;
    }

    /*
    temp è un puntatore a Nodo. Lo assegno a head, lo sto copiando per non alterare l'head originale.
    mi serve perchè dovrò scorrere la lista fino all'ultimo nodo per assegnare all'ultimo nodo
    il nuovo nodo.
    */
    Nodo* temp = head;  // ATTENZIONE! Se dereferenzio temp, le modifiche si riflettono su head!

    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = nuovoNodo;
}

void Lista::elimina(int val) {
    if (head == nullptr) return;

    // caso se il nodo da eliminare è in testa
    if (head->valore == val) {
        head = head->next; // assegno la testa al nodo successivo
        return;
    }

    Nodo* temp = head;

    while (temp->next != nullptr && temp->next->valore != val) {
        temp = temp->next;
    }

    if (temp->next == nullptr) return;  // Nodo non trovato

    // se arriviamo a questo punto, temp->next è il nodo da eliminare
    // e implica il fatto che è val == temp->next->valore
    Nodo* daEliminare = temp->next;


    temp->next = temp->next->next; 
    delete daEliminare;
}

bool Lista::ricerca(int val) {
    Nodo* temp = head;

    while (temp != nullptr) {
        if (temp->valore == val) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}


void Lista::visualizza() {
    Nodo* temp = head;

    if (temp == nullptr) {
        std::cout << "Lista vuota!" << std::endl;
        return;
    }

    while (temp != nullptr) {
        std::cout << temp->valore << "\t";
        temp = temp->next;
    }

    std::cout << std::endl;
}

int Lista::contaNodi() {
    int count = 0;
    Nodo* temp = head;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }

    return count;
}

void Lista::rimuoviDuplicati() {
    if (head == nullptr) return;

    Nodo* temp = head;

    while (temp != nullptr) {
        Nodo* temp2 = temp;
        while (temp2->next != nullptr) {
            if (temp->valore == temp2->next->valore) {
                Nodo* daEliminare = temp2->next;
                temp2->next = temp2->next->next;
                delete daEliminare;
            } else {
                temp2 = temp2->next;
            }
        }
        temp = temp->next;
    }
}

Lista::~Lista() {
    Nodo* temp = head;

    while (temp != nullptr) {
        Nodo* daEliminare = temp;
        temp = temp->next;
        delete daEliminare;
    }
}
