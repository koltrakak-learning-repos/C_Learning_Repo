#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void generaArrayRandom(int array[], int dim) {
    // Inizializza il generatore di numeri casuali con il tempo corrente
    srand(time(NULL));

    for(int i=0; i<dim; i++) {
        array[i] = rand() % 101;
    }
}

void countingSort(int array[], int dim, int max) {
    int countingArray[max+1];
    int i, j;
    //inizializzo
    for(i=0; i<max+1; i++) {
        countingArray[i] = 0;
    }
    //conto
    for(j=0; j<dim; j++) {
        countingArray[array[j]]++;
    }

    //ordino consumando una posizione alla volta
    j=0;
    for(i=0; i<max+1; i++) {
        while(countingArray[i]>0) {
            array[j] = i;
            j++;
            countingArray[i]--;
        }
    }
}

int main() {
    int dim = 10, max=100;
    int testArray[dim];

    generaArrayRandom(testArray, dim);
    //prima
    for(int i=0; i<10; i++) {
        printf("indice: %d, valore: %d\n", i, testArray[i]);
    }

    //counting sort
    countingSort(testArray, dim, max);

    //dopo
    printf("\n");
    for(int i=0; i<10; i++) {
        printf("indice: %d, valore: %d\n", i, testArray[i]);
    }

    return 0;
}