#include <stdio.h>

void cesareCrypt(const char *nomeFileInput, const char *outputFileName, int chiave);
void cesareDecrypt(const char *nomeFileInput, const char *outputFileName, int chiave);

int main() {
    const char *nomeFileInput = "input.txt";  
    const char *nomeFileEncrypted = "encrypted.txt";
    const char *nomeFileDecrypted = "decrypted.txt";
    int chiave = 3; 

    // Cripta il file
    cesareCrypt(nomeFileInput, nomeFileEncrypted, chiave);

    // Decripta il file
    cesareDecrypt(nomeFileEncrypted, nomeFileDecrypted, chiave);

    return 0;
}


void cesareCrypt(const char *nomeFileInput, const char *outputFileName, int chiave) {
    FILE *inputFile = fopen(nomeFileInput, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Errore nell'apertura dei file.\n");
        return;
    }

    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + chiave) % 26) + 'A'; 
        } else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + chiave) % 26) + 'a'; 
        }
        fputc(c, outputFile); // Scrivi il carattere criptato nel file di output

        // Spiegazione dell'algoritmo di crittografia di Cesare:
        // - 'c - 'A' o 'c - 'a': Questo passaggio converte il carattere 'c' nella sua posizione relativa all'interno dell'alfabeto.
        //   Ad esempio, se 'c' è 'A', il risultato sarà 0 (perché 'A' è il primo carattere dell'alfabeto) e se 'c' è 'B', sarà 1, e così via.
        //   Così lavoriamo con valori che partono da 0 anziché dai codici ASCII originali, facilitando i calcoli successivi.
        //   Per le lettere maiuscole, utilizziamo 'A', mentre per quelle minuscole utilizziamo 'a'.
        //
        // - '+ chiave': Questo passaggio aggiunge il valore della chiave (key) al risultato precedente.
        //   La chiave rappresenta il numero di posizioni di spostamento nell'alfabeto. Ad esempio, se la chiave è 3 e il carattere è 'A', il nuovo valore sarà 0 + 3 = 3,
        //
        // - '% 26': una volta superata la lettera 'Z' (o 'z' per le minuscole), il conteggio riprenda da 'A' (o 'a').

    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File criptato in %s\n", outputFileName);
}

void cesareDecrypt(const char *nomeFileInput, const char *outputFileName, int chiave) {
    FILE *inputFile = fopen(nomeFileInput, "r");
    FILE *outputFile = fopen(outputFileName, "w");
    
    if (inputFile == NULL || outputFile == NULL) {
        printf("Errore nell'apertura dei file.\n");
        return;
    }

    char c;
    while ((c = fgetc(inputFile)) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' - chiave + 26) % 26) + 'A'; 
        } else if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' - chiave + 26) % 26) + 'a'; 
        }
        fputc(c, outputFile); 
    }

    fclose(inputFile);
    fclose(outputFile);
    printf("File decriptato in %s\n", outputFileName); // Output file
}