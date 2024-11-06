#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 
#define VOTI 5

typedef struct {
    char cognome[50];
    int voti[VOTI];
} Studente;

void scriviFile(const char *nomeFile);
void leggiFile(const char *nomeFile);
int contaCognome(const char *nomeFile, const char *cognome);
void stampaDettagli(const char *nomeFile);

int main() {
    const char *nomeFile = "studenti.dat";

    scriviFile(nomeFile);
    leggiFile(nomeFile);

    const char *cognomeDaCercare = "Facchini";

    int contCognomi = contaCognome(nomeFile, cognomeDaCercare);

    if (contCognomi != -1) {
        printf("Il cognome '%s' e presente %d volte.\n", cognomeDaCercare, contCognomi);
    }

    stampaDettagli(nomeFile);

    return 0;
}


void scriviFile(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "w");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    Studente studenti[N] = {
        {"Facchini", {10, 10, 10, 10, 10}},
        {"Macchioni", {3, 4, 5, 6, 7}},
        {"Moreschi", {4, 5, 6, 7, 8}},
        {"Bilardo", {5, 6, 7, 8, 9}},
        {"Vetromile", {6, 7, 8, 9, 10}},
        {"Bolognino", {7, 8, 9, 10, 2}},
        {"Panetta", {8, 9, 10, 2, 3}},
        {"Netaka", {9, 10, 2, 3, 4}},
        {"Welikadage", {10, 2, 3, 4, 5}},
        {"Vegetti", {2, 3, 4, 5, 6}}
    };



    for (int i = 0; i < N; i++) {
        fwrite(&studenti[i], sizeof(Studente), 1, file);
    }

    fclose(file);
    printf("File scritto con successo.\n");
}



void leggiFile(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    Studente studente; // Record standard che poi assegnerò 

    while (fread(&studente, sizeof(Studente), 1, file)) { // Finchè ci sono ancora record nel file
        printf("Cognome: %s, Voti: ", studente.cognome);
        for (int i = 0; i < VOTI; i++) {
            printf("%d ", studente.voti[i]);
        }
        printf("\n");
    }

    fclose(file);
}

// Funzione per contare il numero di studenti con un dato cognome
int contaCognome(const char *nomeFile, const char *cognome) {
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return -1;
    }

    int count = 0;

    Studente studente;
    while (fread(&studente, sizeof(Studente), 1, file)) {
        if (strcmp(studente.cognome, cognome) == 0) {
            count++;
        }
    }

    fclose(file);

    return count;
}

void stampaDettagli(const char *nomeFile) {
    FILE *file = fopen(nomeFile, "r");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    Studente studente;

    while (fread(&studente, sizeof(Studente), 1, file)) { // Finchè ci sono ancora record nel file

        // A ogni iterazione resetto
        int somma = 0, votoMin = studente.voti[0], votoMax = studente.voti[0];

        for (int i = 0; i < VOTI; i++) {
            somma += studente.voti[i];
            if (studente.voti[i] < votoMin) {
                votoMin = studente.voti[i];
            }
            if (studente.voti[i] > votoMax) {
                votoMax = studente.voti[i];
            }
        }
        double media = somma / 5.0;
        printf("Cognome: %s, Media: %.2f, Voto più alto: %d, Voto più basso: %d\n", studente.cognome, media, votoMax, votoMin);
    }

    fclose(file);
}

