#include <stdio.h>

int main() {
    FILE *file;
    int caratteri = 0, parole = 0, righe = 0;
    char c, ultimoCarattere = ' ';

    file = fopen("file_testuali/il_mio_file.txt", "r");
    if (file == NULL) {
        printf("Impossibile aprire il file");
        return 1;
    }

    while ((c = fgetc(file)) != EOF) {
        caratteri++; 

        if (c == '\n') righe++;

        // Controlla se è l'inizio di una parola
        if (c == ' ' || c == '\t' || c == '\n') {
            if (ultimoCarattere != ' ' && ultimoCarattere != '\t' && ultimoCarattere != '\n') {
                parole++; // Conta la parola
            }
        }

        ultimoCarattere = c;
    }

    // Controlla se l'ultima parola è stata contata
    if (ultimoCarattere != ' ' && ultimoCarattere != '\t' && ultimoCarattere != '\n') {
        parole++;
    }

    // Chiudi il file
    fclose(file);

    // Stampa i risultati
    printf("Caratteri: %d\n", caratteri);
    printf("Parole: %d\n", parole);
    printf("Righe: %d\n", righe + 1); // Aggiungi 1 per contare l'ultima riga

    return 0;
}
