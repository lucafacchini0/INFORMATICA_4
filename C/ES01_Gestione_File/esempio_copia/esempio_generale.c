#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePrincipale, *fileCopia;
    char ch;

    // Apertura del file principale in lettura
    filePrincipale = fopen("file_testuali/ES1_mioFile.txt", "r");
    if (filePrincipale == NULL) {
        perror("Errore nell'apertura del file principale");
        return 1; 
    }

    fileCopia = fopen("file_testuali/ES1_copia.txt", "w");
    if (fileCopia == NULL) {
        perror("Errore nell'apertura del file copia");
        fclose(filePrincipale);  // Chiude il file principale aperto
        return 1; 
    }

    // Copia del contenuto del file principale nel file copia
    while ((ch = fgetc(filePrincipale)) != EOF) {
        if (fputc(ch, fileCopia) == EOF) {
            perror("Errore durante la scrittura nel file copia");
            fclose(filePrincipale);
            fclose(fileCopia);
            return 1;
        }
    }

    printf("Contenuto copiato con successo!\n");

    fclose(filePrincipale);
    fclose(fileCopia);
    return 0;
}
