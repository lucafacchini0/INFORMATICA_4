#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COGNOME 50
#define NUM_VOTI 8

// Colori ansii
#define RESET "\033[0m"
#define ROSSO "\033[1;31m"
#define VERDE "\033[1;32m"
#define BLU "\033[1;34m"
#define GIALLO "\033[1;33m"

typedef struct {
    char cognome[MAX_COGNOME];
    int giorno, mese, anno;
    int voti[NUM_VOTI];
} Record;

void inserisciRecord(char fileName[], int numRecord);
void stampaFile(char fileName[]);
int ricercaRecord(char fileName[], char cognome[]);
int stampaRecord(char fileName[], int posizione);
int correggiRecord(char fileName[], int posizione);
int numeroRecord(char fileName[]);

int main() {
    char fileName[] = "record.dat";
    int scelta, numRecord, posizione;
    char cognome[MAX_COGNOME]; // avrei anche potuto usare char *cognome;

    do {
        printf(BLU "\nMenu:\n" RESET);
        printf(GIALLO "1. Inserisci Record\n" RESET);
        printf(BLU "2. Stampa File\n" RESET);
        printf(GIALLO "3. Ricerca Record\n" RESET);
        printf(BLU"4. Stampa Record\n" RESET);
        printf(GIALLO"5. Correggi Record\n" RESET);
        printf(BLU"6. Numero di Record\n" RESET);
        printf(ROSSO "0. Esci\n");
        printf(VERDE "Scelta: " RESET);
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                printf(GIALLO "Quanti record vuoi inserire? " RESET);
                scanf("%d", &numRecord);
                inserisciRecord(fileName, numRecord);
                break;
            case 2:
                stampaFile(fileName);
                break;
            case 3:
                printf(GIALLO "Inserisci il cognome da cercare: " RESET);
                scanf("%s", cognome);
                posizione = ricercaRecord(fileName, cognome);
                if (posizione == -1) {
                    printf(ROSSO "Record non trovato.\n" RESET);
                }
                break;
            case 4:
                printf(GIALLO "Inserisci la posizione del record da stampare: " RESET);
                scanf("%d", &posizione);
                if (stampaRecord(fileName, posizione) == -1) {
                    printf(ROSSO "Record non presente.\n" RESET);
                }
                break;
            case 5:
                printf(GIALLO "Inserisci la posizione del record da correggere: " RESET);
                scanf("%d", &posizione);
                if (correggiRecord(fileName, posizione) == -1) {
                    printf(ROSSO "Record non presente.\n" RESET);
                }
                break;
            case 6:
                printf(VERDE "Numero di record: %d\n" RESET, numeroRecord(fileName));
                break;
            case 0:
                printf(BLU "BYE BYE!\n" RESET);
                break;
            default:
                printf(ROSSO "Scelta non valida.\n" RESET);
        }
    } while (scelta != 0);

    return 0;
}

void inserisciRecord(char fileName[], int numRecord) {
    FILE *file = fopen(fileName, "ab");
    if (!file) {
        printf(ROSSO "Errore nell'apertura del file.\n" RESET);
        return;
    }

    Record record;

    for (int i = 0; i < numRecord; i++) {
        printf(GIALLO "Inserisci cognome: " RESET);
        scanf("%s", record.cognome);
        printf(GIALLO "Inserisci data di nascita (gg mm aaaa): " RESET);
        scanf("%d %d %d", &record.giorno, &record.mese, &record.anno);
        printf(GIALLO "Inserisci %d voti: " RESET, NUM_VOTI);
        for (int j = 0; j < NUM_VOTI; j++) {
            scanf("%d", &record.voti[j]);
        }
        fwrite(&record, sizeof(Record), 1, file);
    }

    printf(VERDE "Record inseriti con successo.\n" RESET);
    fclose(file);
}

void stampaFile(char fileName[]) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf(ROSSO "Errore nell'apertura del file.\n" RESET);
        return;
    }

    Record record;
    while (fread(&record, sizeof(Record), 1, file)) {
        printf(BLU "Cognome: %s, Data di nascita: %02d/%02d/%04d, Voti: " RESET, record.cognome, record.giorno, record.mese, record.anno);
        for (int i = 0; i < NUM_VOTI; i++) {
            printf("%d ", record.voti[i]);
        }
        printf("\n");
    }
    fclose(file);
}

int ricercaRecord(char fileName[], char cognome[]) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf(ROSSO "Errore nell'apertura del file.\n" RESET);
        return -1;
    }

    Record record;
    int posizione = 0;

    while (fread(&record, sizeof(Record), 1, file)) {
        if (strcmp(record.cognome, cognome) == 0) {
            int sommaVoti = 0;
            for (int i = 0; i < NUM_VOTI; i++) {
                sommaVoti += record.voti[i];
            }
            float media = sommaVoti / (float)NUM_VOTI;
            int eta = 2024 - record.anno; // anno corrente: 2024
            printf(VERDE "Cognome: %s, Età: %d, Media voti: %.2f\n" RESET, record.cognome, eta, media);
            fclose(file);
            return posizione;
        }
        posizione++;
    }

    fclose(file);
    return -1;
}

int stampaRecord(char fileName[], int posizione) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf(ROSSO "Errore nell'apertura del file.\n" RESET);
        return -1;
    }

    Record record;
    fseek(file, posizione * sizeof(Record), SEEK_SET);
    if (fread(&record, sizeof(Record), 1, file)) {
        printf(BLU "Cognome: %s, Data di nascita: %02d/%02d/%04d, Voti: " RESET, record.cognome, record.giorno, record.mese, record.anno);
        for (int i = 0; i < NUM_VOTI; i++) {
            printf("%d ", record.voti[i]);
        }
        printf("\n");
        fclose(file);
        return 0;
    }

    fclose(file);
    return -1;
}

int correggiRecord(char fileName[], int posizione) {
    if (stampaRecord(fileName, posizione) == -1) {
        return -1;
    }

    FILE *file = fopen(fileName, "rb+");
    if (!file) {
        printf(ROSSO "Errore nell'apertura del file.\n" RESET);
        return -1;
    }

    Record record;
    fseek(file, posizione * sizeof(Record), SEEK_SET);
    printf(GIALLO "Inserisci nuovo cognome: " RESET);
    scanf("%s", record.cognome);
    printf(GIALLO "Inserisci nuova data di nascita (gg mm aaaa): " RESET);
    scanf("%d %d %d", &record.giorno, &record.mese, &record.anno);
    printf(GIALLO "Inserisci %d nuovi voti: " RESET, NUM_VOTI);
    for (int i = 0; i < NUM_VOTI; i++) {
        scanf("%d", &record.voti[i]);
    }
    fseek(file, posizione * sizeof(Record), SEEK_SET);
    fwrite(&record, sizeof(Record), 1, file);

    printf(VERDE "Record corretto con successo.\n" RESET);
    fclose(file);
    return 0;
}

int numeroRecord(char fileName[]) {
    FILE *file = fopen(fileName, "rb");
    if (!file) {
        printf(ROSSO "Errore nell'apertura del file.\n" RESET);
        return -1;
    }

    fseek(file, 0, SEEK_END);
    // Calcola il numero di record nel file dividendo la posizione 
    //attuale del file (in byte) per la dimensione di un singolo record
    // essendo che sono a SEEK_END, il gioco è fatto.
    int numRecord = ftell(file) / sizeof(Record);
    fclose(file);
    return numRecord;
}
