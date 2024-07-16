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

void merge(int array[], int inizio, int fine, int mezzo) {
    int i=inizio, j=mezzo+1, k=inizio;
    
    int suppArray[fine+1];  //nel libro è una variabile globale, io la metto qua così non devo cambiare dimensione ogni volta

    //debug
    // printf("\n");
    // printf("PRIMA: inizio: %d, fine: %d, mezzo: %d\n", inizio, fine, mezzo);
    // for(int z=inizio; z<=fine; z++) {
    //     printf("\tindice: %d, valore: %d\n", z, array[z]);
    // }
    // printf("\n");

    while(i<=mezzo && j<=fine) {
        if(array[i] <= array[j]) {
            suppArray[k] = array[i];
            i++;
        }
        else {
            suppArray[k] = array[j];
            j++;
        }

        k++;
    }
    
    //sposto gli elementi non consumati del primo sottoarray in fondo
    j=fine;
    for(int h=mezzo; h>=i; h--) {
        array[j] = array[h];
        j--;
    }
    //ricopio gli elementi salvati nel posto giusto
    for(i=inizio; i<=k-1; i++) {
        array[i] = suppArray[i];
    }

    //debug
    // printf("\n");
    // printf("DOPO: inizio: %d, fine: %d, mezzo: %d\n", inizio, fine, mezzo);
    // for(i=inizio; i<=fine; i++) {
    //     printf("\tindice: %d, valore: %d\n", i, array[i]);
    // }
    // printf("\n");
}

void mergeSort(int array[], int inizio, int fine) {
    //if(inizio < fine) { //forse possiamo aggiustare questa condizione per risparmiare l'ultima divisione
    if( (fine - inizio) >= 1) {
        int mezzo = (inizio+fine)/2;

        mergeSort(array, inizio, mezzo);
        mergeSort(array, mezzo+1, fine);
        merge(array, inizio, fine, mezzo);
    }
}

int main() {
    int dim = 10;
    int testArray[dim];

    generaArrayRandom(testArray, dim);
    //prima
    for(int i=0; i<10; i++) {
        printf("indice: %d, valore: %d\n", i, testArray[i]);
    }

    mergeSort(testArray, 0, dim-1);

    //dopo
    printf("\n");
    for(int i=0; i<10; i++) {
        printf("indice: %d, valore: %d\n", i, testArray[i]);
    }

    return 0;
}