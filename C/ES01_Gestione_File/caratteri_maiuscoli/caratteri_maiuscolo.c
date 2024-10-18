#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *filePrincipale, *fileCopia;
    char ch;

    filePrincipale = fopen("file_testuali/nomi.txt", "r");
    if (filePrincipale == NULL) {
        perror("Errore nell'apertura del file");
        return 1;
    }

    fileCopia = fopen("file_testuali/nomi_maiuscolo.txt", "w");
    if (fileCopia == NULL) {
        perror("Errore nell'apertura del file");
        fclose(filePrincipale);
        return 1;
    }

    // Metodo 1: usando toupper()
    // while ((ch = fgetc(filePrincipale)) != EOF) {
    //     fputc(toupper(ch), fileCopia);
    // }

    // Metodo 2: usando un ciclo iterando su ogni carattere
    while ((ch = fgetc(filePrincipale)) != EOF) {
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - 32;
        }
        fputc(ch, fileCopia);
    }
    

    fclose(filePrincipale);
    fclose(fileCopia);

    return 0;
}