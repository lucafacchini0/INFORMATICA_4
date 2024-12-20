#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void lampeggio(int led) {
        if (led == 1) {
        for (int i = 0; i < 100; i++) {
            printf(GREEN "Led verde acceso\n" RESET);
            usleep(300000);
            printf(GREEN "Led verde spento\n" RESET);
            usleep(300000);
        }
    } else if (led == 2) {
         for (int i = 0; i < 100; i++) {
            printf(RED "Led rosso acceso\n" RESET);
            usleep(700000);
            printf(RED "Led rosso spento\n" RESET);
            usleep(700000);
        }
    } else   if (led == 3) {

        for (int i = 0; i < 100; i++) {
            printf(YELLOW "Led giallo acceso\n" RESET);
             usleep(1200000);
            printf(YELLOW "Led giallo spento\n" RESET);
            usleep(1200000);
        }
    }
}

int main() {
    char comandoDaEseguire;
    int led = 0;
    pid_t pid;

    while (1) {
        printf("Inserisci comando (v: verde, r: rosso, g: giallo, q: quit): ");
        scanf(" %c", &comandoDaEseguire);

        if (comandoDaEseguire == 'q') {  
            printf("Ciao e arrivederci.\n");
            break;  
        }

        if (comandoDaEseguire == 'v') led = 1;
        else if (comandoDaEseguire == 'r') led = 2;
        else if (comandoDaEseguire == 'g') led = 3;
        else { 
            printf("Comando non valido, continua.\n");  
            continue; 
        }

        pid = fork(); 

        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }

        else if (pid == 0) {
            lampeggio(led);
            exit(0); 
        } 
    }
    return 0;
}
