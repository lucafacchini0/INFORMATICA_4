#include <stdio.h>

int main() {
    FILE *file, *copia;
    char ch;

    file = fopen("mioFile.txt", "r");


    copia = fopen("copia.txt", "w");


    while ((ch = fgetc(file)) != EOF) {
        fputc(ch, copia);
    }

    printf("Contenuto copiato con successo!\n");

    fclose(file);
    fclose(copia);
    return 0;

}



int numero = 0;


if(carattere = 'a') {
    numero = 1;
}