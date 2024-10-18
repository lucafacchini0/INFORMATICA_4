/**
 * @file Es_B.c
 * @brief Programma per calcolare la differenza tra due periodi di tempo.
 * 
 * Questo programma definisce la struttura "tempo" e fornisce una funzione
 * per calcolare la differenza tra due periodi di tempo espressi in ore, min, sec
 *
 * @author Luca Facchini
 * @date 20-09-2024
 * 
 * @section Sezione Struttura
 * 
 * La struttura "tempo" è definita come:
 * 
 * - secondi!
 * - minuti
 * - ore
 *
 * @section Sezione Funzioni
 * 
 * - void differenzaTraPeriodi(struct tempo t1, struct tempo t2, struct tempo *diff):
 *   Calcola la differenza tra due periodi di tempo.
 * 
 * @section Sezione Utilizzo
 * 
 * L'utente deve fornire sei valori tramite la linea di comando: ore, minuti e secondi
 * per ciascun periodo di tempo.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int secondi;
    int minuti;
    int ore;
} Tempo;

void differenzaTraPeriodi(Tempo t1, Tempo t2, Tempo *diff);

int main(int argc, char *argv[]) {
    if (argc != 7) {
        printf("Uso: %s <h1> <m1> <s1> <h2> <m2> <s2>\n", argv[0]);
        return 1;
    }

    Tempo t1, t2, diff;

    // Attenzione, atoi server per convertire una stringa ASCII in int.
    t1.ore = atoi(argv[1]);
    t1.minuti = atoi(argv[2]);
    t1.secondi = atoi(argv[3]);

    t2.ore = atoi(argv[4]);
    t2.minuti = atoi(argv[5]);
    t2.secondi = atoi(argv[6]);

    // Calcola la differenza
    differenzaTraPeriodi(t1, t2, &diff);

    // Stampa il risultato
    printf("Differenza: %02d:%02d:%02d\n", diff.ore, diff.minuti, diff.secondi);

    return 0;
}

void differenzaTraPeriodi(Tempo t1, Tempo t2, Tempo *diff) {
    // converto entrambi i tempi in secondi totali
    int secondiTotali1 = t1.ore * 3600 + t1.minuti * 60 + t1.secondi;
    int secondiTotali2 = t2.ore * 3600 + t2.minuti * 60 + t2.secondi;

    // Calcolo della differenza (Abs serve a utilizzare il valore
    //assoluto, ovvero, una differenza negativa sarà positiva
    int differenzaInSecondi = abs(secondiTotali1 - secondiTotali2);

    diff->ore = differenzaInSecondi / 3600;
    differenzaInSecondi %= 3600;
    diff->minuti = differenzaInSecondi / 60;
    diff->secondi = differenzaInSecondi % 60;
}