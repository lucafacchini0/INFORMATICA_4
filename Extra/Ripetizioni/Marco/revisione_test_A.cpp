/**
 * @file revisione_test_A.cpp
 * @brief Algoritmi di base - Test A
 * e gestione delle stringhe.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 10

void caricaArray(int a[]);
void caricaArrayRandom(int a[]);
void stampaArray(int a[]);

int main() { 
    
    srand(static_cast<unsigned int>(time(0)));

    int matrice[N][N];

    // Carica la riga 0 con numeri casuali chiamando la funzione caricaArrayRandom
    caricaArrayRandom(matrice[0]);

    // Carica la riga 1 con numeri inseriti dall'utente chiamando la funzione caricaArray
    caricaArrayRandom(matrice[1]);

    // Stampa riga 0
    stampaArray(matrice[0]); 

    // Carica la colonna 0 con numeri casuali chiamando la funzione caricaArrayRandom
    caricaArrayRandom(matrice[0]);    

    // --- //
    // principali funzioni della libreria string.h

    // strlen: restituisce la lunghezza di una stringa
    char stringa[] = "Ciao";
    printf("La lunghezza della stringa è %d\n", strlen(stringa));

    // strcpy: copia una stringa in un'altra
    char stringa1[] = "Ciao";
    char stringa2[10];
    strcpy(stringa2, stringa1);

    // strcmp: confronta due stringhe: restituisce 0 se sono uguali, un numero negativo se la prima è minore della seconda, un numero positivo altrimenti
    char stringa3[] = "Ciao";
    char stringa4[] = "Ciao";
    if(strcmp(stringa3, stringa4) == 0) {
        printf("Le stringhe sono uguali\n");
    } else if (strcmp(stringa3, stringa4) < 0) {
        printf("La prima stringa è minore della seconda\n");
    } else {
        printf("La prima stringa è maggiore della seconda\n");
    }

    // strcat: concatena due stringhe
    char stringa5[10] = "Ciao";
    char stringa6[] = " mondo!";
    strcat(stringa5, stringa6);

    // Inserire i caratteri in una stringa da tastiera con %s
    char stringa7[10];
    scanf("%s", stringa7);

    // strchr: cerca un carattere in una stringa
    char stringa7[] = "Ciao";
    char carattere = 'a';

    if(strchr(stringa7, carattere) != NULL) {
        printf("Il carattere è presente nella stringa\n");
    } else {
        printf("Il carattere non è presente nella stringa\n");
    }

    // strstr: cerca una sottostringa in una stringa
    char stringa8[] = "Ciao mondo!";
    char sottostringa[] = "mondo";

    if(strstr(stringa8, sottostringa) != NULL) {
        printf("La sottostringa è presente nella stringa\n");
    } else {
        printf("La sottostringa non è presente nella stringa\n");
    }
}

void caricaArray(int a[]) {
    for(int i = 0; i < N; i++) {
        printf("Inserisci l'elemento %d: ", i);
        scanf("%d", &a[i]);
    }
}

void caricaArrayRandom(int a[]) {
    for(int i = 0; i < N; i++) {
        a[i] = rand() % (90 - 10 + 1) + 10; // formula: rand() % (max - min + 1) + min
    }
}

void stampaArray(int a[]) {
    for(int i = 0; i < N; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void caricaColonnaMatrice(int m[][N], int col) {
    for(int i = 0; i < N; i++) {
        printf("Inserisci l'elemento %d: ", i);
        scanf("%d", &m[i][col]);
    }
}

void bubbleSort(int a[]) {
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}



void ordinamentoLento(int v[]) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

// Stampa diagonale matrice
void stampaDiagonale(int m[][N]) {
    for(int i = 0; i < N; i++) {
        printf("%d ", m[i][i]);
    }
    printf("\n");
}

// Stampa diagonale inversa matrice
void stampaDiagonaleInversa(int m[][N]) {
    for(int i = 0; i < N; i++) {
        printf("%d ", m[i][N - i - 1]);
    }
    printf("\n");
}

// Ricerca dicotomica
int ricercaDicotomica(int v[], int x) {
    int min = 0, max = N-1, half;

    while(min <= max) {
        half = (min + max) / 2;

        if(v[half] == x) return 1;
        if(x < v[half]) max = half - 1;
        else min = half + 1; 
    }

    return 0;
}

void scambia(int *a, int *b) {
    int temp = *a; 
    *a = *b;        
    *b = temp;    
}