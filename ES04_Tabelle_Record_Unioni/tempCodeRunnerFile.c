/**
 * @file Es_A.c
 * @brief Programma per la gestione dei dati di una persona.
 * 
 * Questo programma permette di definire la struttura "persona", che include
 * nome, cognome, indirizzo, provincia e data di nascita. L'utente inserisce
 * i dati richiesti e il programma li stampa.
 *
 * @author Luca Facchini
 * @date 20-9-2024
 */

#include <stdio.h>
#define N 50

// Codici ANSI per i colori
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

typedef struct {
    char via[N];
    char comune[N];
    char provincia[2];
    int civico;
} Indirizzo;

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct {
    char nome[N];
    char cognome[N];
    Indirizzo indirizzo;
    Data nascita;
} Persona;

int main() {
    Persona persona1;

    // Input dei dati
    printf(BLUE "Inserisci nome: " RESET);
    scanf("%s", persona1.nome);

    printf(BLUE "Inserisci cognome: " RESET);
    scanf("%s", persona1.cognome);

    printf(BLUE "Inserisci la via di residenza: " RESET);
    scanf("%s", persona1.indirizzo.via);

    printf(BLUE "Inserisci il numero civico: " RESET);
    scanf("%d", &persona1.indirizzo.civico);

    printf(BLUE "Inserisci il comune di residenza: " RESET);
    scanf("%s", persona1.indirizzo.comune);

    printf(BLUE "Inserisci la sigla di provincia: " RESET);
    scanf("%s", persona1.indirizzo.provincia);

    printf(BLUE "Inserisci l'anno di nascita: " RESET);
    scanf("%d", &persona1.nascita.anno);

    printf(BLUE "Inserisci il mese di nascita: " RESET);
    scanf("%d", &persona1.nascita.mese);

    printf(BLUE "Inserisci il giorno di nascita: " RESET);
    scanf("%d", &persona1.nascita.giorno);

    // Stampa dei risultati
    printf(CYAN "--------------------------------------------\n" RESET);
    printf(CYAN " [ " GREEN "%s" RESET CYAN " ] [ " GREEN "%s" RESET CYAN " ]\n\n", persona1.nome, persona1.cognome);
    
    printf(CYAN "[ DATA DI NASCITA ]\n" RESET);
    printf(GREEN "%d-%d-%d\n\n" RESET, persona1.nascita.giorno, persona1.nascita.mese, persona1.nascita.anno);
    
    printf(CYAN "[ RESIDENZA ]\n" RESET);
    printf(GREEN "%s %d, %s (%s)\n" RESET, persona1.indirizzo.via, persona1.indirizzo.civico, persona1.indirizzo.comune, persona1.indirizzo.provincia);
    
    printf(CYAN "--------------------------------------------\n" RESET);

    return 0;
}
