#include <stdio.h>

int main() {
    FILE *fileInput, *filePari, *fileDispari;

    // Per avere una chiarezza maggiore, dichiaro i nomi dei file in variabili
    char *nomeFileInput = "file_testuali/numeri.txt"; 
    char *nomeFilePari = "file_testuali/pari.txt";     
    char *nomeFileDispari = "file_testuali/dispari.txt"; 

    int numero;

    fileInput = fopen(nomeFileInput, "r");
    if (fileInput == NULL) {
        printf("Impossibile aprire il file %s\n", nomeFileInput);
        return 1;
    }

    filePari = fopen(nomeFilePari, "w");
    if (filePari == NULL) {
        printf("Impossibile aprire il file %s\n", nomeFilePari);
        fclose(fileInput);
        return 1;
    }

    fileDispari = fopen(nomeFileDispari, "w");
    if (fileDispari == NULL) {
        printf("Impossibile aprire il file %s\n", nomeFileDispari);
        fclose(fileInput);
        fclose(filePari);
        return 1;
    }

    // Metodo 1: usare fscanf() e fprintf()
    /*
    while (fscanf(fileInput, "%d", &numero) == 1) {
        if (numero % 2 == 0) {
            fprintf(filePari, "%d\n", numero);  // Numero pari
        } else {
            fprintf(fileDispari, "%d\n", numero);   // Numero dispari
        }
    }
    */

    // Metodo 2: usare fgetc() e fputs()
    char c;
    int inNumero = 0;  // Flag per tenere traccia se siamo in un numero
    
    numero = 0;

    while ((c = fgetc(fileInput)) != EOF) {
        if (c == ' ' || c == '\n') { // Se il numero è terminato
            if (inNumero) {
                if (numero % 2 == 0) {
                    fprintf(filePari, "%d\n", numero);  
                } else {
                    fprintf(fileDispari, "%d\n", numero);  
                }
                numero = 0; // Reset del numero
                inNumero = 0; // Resetta il flag
            }
        } else {
            numero = numero * 10 + (c - '0'); // Costruiscie il numero

            // - 'numero' viene inizialmente impostato a zero. 
            // - Per ogni carattere 'c' che rappresenta una cifra numerica 
            //
            // 1. 'c - '0'' converte il carattere in un valore numerico (sarebbe int).
            //    Ad esempio, se 'c' è '5', l'operazione 'c - '0'' restituirà il valore intero 5.
            // 
            // 2. Moltiplicando 'numero' per 10, si sposta il valore corrente 
            //    a sinistra nella rappresentazione decimale, creando spazio la una nuova cifra.
            //    Ad esempio, se 'numero' era 12 e si legge '5', la moltiplicazione per 10
            //    porta a 120.
            //
            // 3. L'operazione finale 'numero * 10 + (c - '0')' somma il valore della nuova cifra 
            //    al valore corrente di 'numero'. 

            inNumero = 1; // Siamo in un numero
        }
    }

    // Gestisci l'ultimo numero se presente
    if (inNumero) {
        if (numero % 2 == 0) {
            fprintf(filePari, "%d\n", numero);  
        } else {
            fprintf(fileDispari, "%d\n", numero);
        }
    }

    fclose(fileInput);
    fclose(filePari);
    fclose(fileDispari);

    printf("I numeri sono stati scritti in %s e %s.\n", nomeFilePari, nomeFileDispari);

    return 0;
}
