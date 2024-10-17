#include <stdio.h>

int main() {
    FILE *principale, *copia;
    char ch;

    principale = fopen("mioFile.txt", "r");
         copia = fopen("copia.txt", "w")

    while(!feof(principale)) {
        ch = fgetc(principale);
                fputc(ch, copia);

        printf("%c", ch);
    }

    while(!feof(principale)) {
        ch = fgetc(principale);
                fputc(ch, copia);

        printf("%c", ch);
    }
 
    printf("Contenuto copiato con successo!\n");

    fclose(principale);
    fclose(copia);
    return 0;
}



