#include <stdio.h>

const int TEXT_LENGTH = 50;
const int MAX_VOTI = 5;

typedef struct {
    int anno;
    int mese;
    int anno;
} Data;

typedef struct {
    char nome[TEXT_LENGTH];
    char cognome[TEXT_LENGTH];
    Data dataNascita;
    int voti[MAX_VOTI];
} Persona;

void inserisci