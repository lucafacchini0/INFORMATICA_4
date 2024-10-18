/**
 * @file Es_C.c
 * @brief Programma per la gestione dei dati di una persona.
 * 
 * Questo programma consente di memorizzare e gestire informazioni su N studenti,
 * inclusi matricola, cognome, data di nascita (opzionale) e 8 voti.

 *
 * @author Luca Facchini
 * @date 20-09-2024
 * 
 * @section Sezione Struttura
 * 
  * @details
 * Funzioni principali:
 * - CaricaTabella: carica i dati degli studenti in un array.
 * - CaricaTabellaRandom: carica casualmente i dati degli studenti.
 * - StampaTabella: stampa le informazioni di tutti gli studenti.
 * - TrovaVotoAlto: trova e restituisce l'indice dello studente con il voto più alto.
 * - M_cog: modifica i cognomi degli studenti per avere il primo carattere maiuscolo.
 * - RicercaPerMatricola: cerca uno studente in base alla matricola.
 * - RicercaPerCognome: cerca uno studente in base al cognome e restituisce l'indice.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define N 10 // studenti della classe
#define L 20 // Lunghezza massima del nome
#define V 8  // massima numero voti

// Codici ANSI per i colori
#define RESET   "\033[0m"
#define GREEN  "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define ORANGE  "\033[38;5;214m" // Arancione

typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct {
    int italiano[V];
    int matematica[V];
    int informatica[V];
    int inglese[V];
} Voti;

typedef struct {
    int matricola;
    char nome[L];
    char cognome[L];
    Voti voti;
    Data nascita;
} Studente;

// Funzioni primarie
void caricaTabella(Studente a[]);
void stampaTabella(Studente a[], int index);
void caricaTabellaRandom(Studente a[]);
int mediaVoti(int voti[]);
int trovaVotoAlto(Studente a[]);
void M_cog(Studente a[]);
int ricercaPerMatricola(Studente a[], int matricola);
int ricercaPerCognome(Studente a[], char cognome[]);
void ordinaSuCognome(Studente a[]);

// Funzioni secondarie
void inserimentoVoti(int voti[]);
void stampaVoti(int voti[]);

int main() {
    srand(time(NULL));

    Studente CLASSE_4H[N];
    // Caricamento manuale della tabella. Togliere il commento e disattivare la funzione caricaTabellaRandom
    // caricaTabella(CLASSE_4H);
    caricaTabellaRandom(CLASSE_4H);

    // Modifica dei cognomi degli studenti
    printf("Tutti i cognomi sono stati modificati\n");
    M_cog(CLASSE_4H);

    stampaTabella(CLASSE_4H, N-1);

    // Trova lo studente col voto piu alto
    int index = trovaVotoAlto(CLASSE_4H);

    // Attenzione. La media dei voti è stata effettuata utilizzando integer. 
    // Per avere una media e un risultato più preciso, si consiglia di utilizzare float.

    printf(GREEN "Lo studente con i voti piu alti e' %s %s\n" RESET, CLASSE_4H[index].nome, CLASSE_4H[index].cognome);

    while(1) {
        // Cosa scegli? 
        printf("\nCosa vuoi fare?\n");
        printf("1. Ricerca per matricola\n");
        printf("2. Ricerca per cognome\n");
        printf("3. Stampa tabella\n");

        int scelta = 0;
        printf("Scelta: ");
        scanf("%d", &scelta);

        if(scelta < 0 && scelta > 3) {
            printf(RED "Scelta non valida\n" RESET);
            continue;
        }

        if(scelta == 1) {
            // Ricerca per matricola
            int matricola = 0;
            printf("Inserisci la matricola da cercare: ");
            scanf("%d", &matricola);

            int indexMatricola = ricercaPerMatricola(CLASSE_4H, matricola);

            if(indexMatricola != -1) {
                printf(GREEN "Studente trovato: %s %s\n" RESET, CLASSE_4H[indexMatricola].nome, CLASSE_4H[indexMatricola].cognome);
            } else {
                printf(RED "Studente non trovato. Tabella ordinata in ordine alfabetico in base ai cognomi.\n" RESET);
            }
        } else if (scelta == 2) {
            // Ricerca per cognome
            char cognome[L];
            printf("Inserisci il cognome da cercare: ");
            scanf("%s", cognome);

            int indexCognome = ricercaPerCognome(CLASSE_4H, cognome);

            if(indexCognome != -1) {
                printf(GREEN "Studente trovato: %s %s\n" RESET, CLASSE_4H[indexCognome].nome, CLASSE_4H[indexCognome].cognome);
            } else {
                ordinaSuCognome(CLASSE_4H);
                printf(RED "Studente non trovato. Tabella ordinata in ordine alfabetico in base ai cognomi.\n" RESET);
            }
        } else if (scelta == 3) {
            // stampa tabella
            stampaTabella(CLASSE_4H, N-1);
            printf(GREEN "Tabella stampata\n" RESET);
        
        }
    }

    return 0;

}




void inserimentoVoti(int voti[]) {
    for (int i = 0; i < V; i++) {
        printf(YELLOW "Voto %d: " RESET, i + 1);
        scanf("%d", &voti[i]); 
    }
}

void caricaTabella(Studente a[]) {
    for (int i = 0; i < N; i++) {
        // Inserimento nome e matricola
        printf(RED "[NULL] " RESET "Inserisci matricola studente\n");
        scanf("%d", &a[i].matricola);

        printf(BLUE "[MAT: %d] " RESET "Inserisci nome studente: ", a[i].matricola);
        scanf("%s", a[i].nome);  

        printf(BLUE "[MAT: %d] " RESET "Inserisci cognome studente: ", a[i].matricola);
        scanf("%s", a[i].cognome);           

        // Inserimento dei voti
        printf(BLUE "[MAT: %d] " RESET "Inserisci i voti di italiano\n", a[i].matricola);
        inserimentoVoti(a[i].voti.italiano);
        
        printf(BLUE "[MAT: %d] " RESET "Inserisci i voti di matematica\n", a[i].matricola);
        inserimentoVoti(a[i].voti.matematica);

        printf(BLUE "[MAT: %d] " RESET "Inserisci i voti di informatica\n", a[i].matricola);
        inserimentoVoti(a[i].voti.informatica);

        printf(BLUE "[MAT: %d] " RESET "Inserisci i voti di inglese\n", a[i].matricola);
        inserimentoVoti(a[i].voti.inglese);            

        // Inserimento data di nascita
        printf("Inserisci la data di nascita\n\n");
        printf("GIORNO: ");
        scanf("%d", &a[i].nascita.giorno);

        printf("MESE: ");
        scanf("%d", &a[i].nascita.mese);

        printf("ANNO: ");
        scanf("%d", &a[i].nascita.anno);

        stampaTabella(a, i);
    }
}

void stampaVoti(int voti[]) {
    for (int i = 0; i < V; i++) {
        printf(CYAN "%-4d" RESET, voti[i]);  // Allineamento a sinistra con una larghezza di 4
    }
    printf("| Media (aprx.): %d\n", mediaVoti(voti));
}

void stampaTabella(Studente a[], int index) {
    if (index == -1) {
        index = N;  // Stampa tutti gli studenti
    }

    // Intestazione della tabella
    printf("Dati inseriti al momento\n");
    printf(YELLOW "%-12s %-20s %-15s\n" RESET, "[ MATRICOLA ]", "[ NOME E COGNOME ]", "[ DATA DI NASCITA ]");
    printf(YELLOW "________________________________________________________________________________________\n" RESET);

    for (int i = 0; i < index + 1; i++) {
        // Stampa i dati personali dello studente in una riga ben allineata
        printf("\n%-12d %-15s %-20s Nato/a il %02d/%02d/%d\n\n", a[i].matricola, a[i].nome, a[i].cognome,
               a[i].nascita.giorno, a[i].nascita.mese, a[i].nascita.anno);

        // Stampa i voti allineati
        printf(RED "[ MATEMATICA  ] " RESET);
        stampaVoti(a[i].voti.matematica);
        
        printf(BLUE "[  ITALIANO   ] " RESET);
        stampaVoti(a[i].voti.italiano);
        
        printf(ORANGE "[ INFORMATICA ] " RESET);
        stampaVoti(a[i].voti.informatica);
        
        printf(YELLOW "[   INGLESE   ] " RESET);
        stampaVoti(a[i].voti.inglese);

    printf(YELLOW "________________________________________________________________________________________\n" RESET);
    }
}

void caricaTabellaRandom(Studente a[]) {


    // Un array di stringhe si fa con un puntatore a puntatore
    char *nomi[] = {"Luca", "Ivan", "Noemi", "AmicoFritz", "Shamal", "Luciana", "Filippo", "Salvatore", "Mattia", "Andrea"};
    char *cognomi[] = {"Facchini", "Moreschi", "Vegetti", "Sconosciuto", "Welikadage", "Vetromile", "Bilardo", "Spanu", "Macchioni", "Petillo"};

    for (int i = 0; i < N; i++) {
        // Inserimento matricola, numero random da 100000 a 999999
        a[i].matricola = rand() % 900000 + 100000;

        // Inserimento nome
        strcpy(a[i].nome, nomi[i]);

        // Inserimento cognome
        strcpy(a[i].cognome, cognomi[i]);

        // Inserimento voti
        for (int j = 0; j < V; j++) {
            a[i].voti.italiano[j] = rand() % 10 + 1;
            a[i].voti.matematica[j] = rand() % 10 + 1;
            a[i].voti.informatica[j] = rand() % 10 + 1;
            a[i].voti.inglese[j] = rand() % 10 + 1;
        }

        // Inserimento data di nascita
        a[i].nascita.giorno = rand() % 31 + 1;
        a[i].nascita.mese = rand() % 12 + 1;
        a[i].nascita.anno = rand() % 3 + 2006;

    }
}

int mediaVoti(int voti[]) {

    int somma = 0;
    for (int i = 0; i < V; i++) {
        somma += voti[i];
    }
    return somma / V;
}

int trovaVotoAlto(Studente a[]) {
    int max = INT_MIN;  // Il valore minimo di un intero
    int index = -1;

    for(int i = 0; i < N; i++) {
        int mediaGenerale = mediaVoti(a[i].voti.italiano) + mediaVoti(a[i].voti.matematica) + mediaVoti(a[i].voti.informatica) + mediaVoti(a[i].voti.inglese);

        if(mediaGenerale > max) {
            max = mediaGenerale;
            index = i;
        }
    }

    return index;
}

void M_cog(Studente a[]) {
   // toupper è una funzione inclusa nella libreria ctype.h, in questo esercizio
   // non inclusa. Per utilizzarla, aggiungere #include <ctype.h> all'inizio del programma.
   // for (int i = 0; i < N; i++) {
   //     a[i].cognome[0] = toupper(a[i].cognome[0]);
   // }

   for(int i = 0; i < N; i++) {
         if(a[i].cognome[0] >= 'a' && a[i].cognome[0] <= 'z') {
              a[i].cognome[0] -= 32;
         }
   }
}


int ricercaPerMatricola(Studente a[], int matricola) {
    for(int i = 0; i < N; i++) {
        if(a[i].matricola == matricola) {
            return i;
        }
    }
    
    
    return -1 ;
}


int ricercaPerCognome(Studente a[], char cognome[]) {
    for(int i = 0; i < N; i++) {
        if(strcmp(a[i].cognome, cognome) == 0) {
            return i;
        }
    }
    
    return -1;
}

void ordinaSuCognome(Studente a[]) {
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(strcmp(a[i].cognome, a[j].cognome) > 0) {
                Studente temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}