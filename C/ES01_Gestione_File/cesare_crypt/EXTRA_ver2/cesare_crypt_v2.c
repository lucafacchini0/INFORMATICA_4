#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

void crittografa(const char *nomeFileInput, const char *nomeFileOutput, int chiave);
void decrittografa(const char *nomeFileInput, const char *nomeFileOutput, int chiave);
char spostaCarattere(char c, int chiave);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Uso: %s <azione> <file_input> <file_output> <chiave>\n", argv[0]);
        fprintf(stderr, "Azione: -e per crittografare, -d per decrittografare\n");
        return EXIT_FAILURE;
    }

    int chiave = atoi(argv[4]);
    if (chiave < 0) {
        fprintf(stderr, "Errore: La chiave deve essere un numero positivo.\n");
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "-e") == 0) {
        crittografa(argv[2], argv[3], chiave);
    } else if (strcmp(argv[1], "-d") == 0) {
        decrittografa(argv[2], argv[3], chiave);
    } else {
        fprintf(stderr, "Errore: Azione non valida. Usa -e o -d.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void crittografa(const char *nomeFileInput, const char *nomeFileOutput, int chiave) {
    FILE *fileInput = fopen(nomeFileInput, "r");
    if (!fileInput) {
        perror("Errore nell'aprire il file di input");
        exit(EXIT_FAILURE);
    }

    FILE *fileOutput = fopen(nomeFileOutput, "w");
    if (!fileOutput) {
        fclose(fileInput);
        perror("Errore nell'aprire il file di output");
        exit(EXIT_FAILURE);
    }

    int c;
    while ((c = fgetc(fileInput)) != EOF) {
        fputc(spostaCarattere(c, chiave), fileOutput);
    }

    fclose(fileInput);
    fclose(fileOutput);
}

void decrittografa(const char *nomeFileInput, const char *nomeFileOutput, int chiave) {
    crittografa(nomeFileInput, nomeFileOutput, -chiave);
}

char spostaCarattere(char c, int chiave) {
    if (c >= 'A' && c <= 'Z') {
        return ((c - 'A' + chiave) % 26 + 26) % 26 + 'A'; // Gestisce anche chiavi negative
    } else if (c >= 'a' && c <= 'z') {
        return ((c - 'a' + chiave) % 26 + 26) % 26 + 'a'; // Gestisce anche chiavi negative
    }
    return c; 
