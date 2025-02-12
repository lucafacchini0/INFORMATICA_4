#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

void caricaArray(int *array);
void stampaArray(int *array);
int trovaMax(int *array);
int* trovaMax_ptr(int *array);

int main() {
    srand(time(NULL));
    int vet[N];

    caricaArray(vet);
    stampaArray(vet);
    printf("\n\nMax: %d", trovaMax(vet));
    printf("\nMax ptr: %x\n\n\n",trovaMax_ptr(vet));

    return 0;
}

void caricaArray(int *array) {
    for (int *p = array; p - array < N; p++) {
        *p = rand() % 11;
    }
}

void stampaArray(int *array) {
    for (int *p = array; p - array < N; p++) {
        printf("%d ", *p);
    }
}

int trovaMax(int *array) {
    int *p = array;
    int max = *p++;
    int indice = 0;

    for(p = array; p - array < N; p++) {
        if(max < *p) {
            max = *p;
            indice = p - array;
        }
    }
    return max;
}

int* trovaMax_ptr(int *array) {
    int *p = array;
    int *max = p;

    

    for(p = array; p - array < N; p++) {
        if(*p > *max) {
            max = p;
        }
    }
    return max;
}