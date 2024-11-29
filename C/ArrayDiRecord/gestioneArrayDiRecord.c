#include <stdlib.h>
#define DIMENSIONE_ARRAY 5
#include <stdio.h>

typedef struct {
    char nome[50];
    int eta;
} Studente;

int main() {
    FILE *file;
    Studente studenti[DIMENSIONE_ARRAY];
    int NUMERO_STUDENTI = 18;
    int i, j;

    file = fopen("file.dat", "wb");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    for (i = 0; i < NUMERO_STUDENTI / DIMENSIONE_ARRAY; i++) {
        for (j = 0; j < DIMENSIONE_ARRAY; j++) {
            // Caricamento dei dati degli studenti
            snprintf(studenti[j].nome, sizeof(studenti[j].nome), "Studente%d", i * DIMENSIONE_ARRAY + j + 1);
            studenti[j].eta = 20 + (i * DIMENSIONE_ARRAY + j) % 10;
        }
        fwrite(studenti, sizeof(Studente), DIMENSIONE_ARRAY, file);
    }

    int restanti = NUMERO_STUDENTI % DIMENSIONE_ARRAY;
    if (restanti > 0) {
        for (j = 0; j < restanti; j++) {
            // Caricamento dei dati degli studenti rimanenti
            snprintf(studenti[j].nome, sizeof(studenti[j].nome), "Studente%d", i * DIMENSIONE_ARRAY + j + 1);
            studenti[j].eta = 20 + (i * DIMENSIONE_ARRAY + j) % 10;
        }
        fwrite(studenti, sizeof(Studente), restanti, file);
    }

    fclose(file);
    return 0;
}