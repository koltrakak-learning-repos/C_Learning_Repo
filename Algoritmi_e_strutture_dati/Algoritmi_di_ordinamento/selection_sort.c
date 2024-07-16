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

int trovaIndiceMin(int array[], int start, int dim) {
    int indiceMin = start;

    for(int i=start+1; i<dim; i++) {
        if(array[i] < array[indiceMin]) {
            indiceMin = i;
        }
    }

    return indiceMin;
}

void selectionSort(int array[], int dim) {
    int indiceMin;
    int temp;

    for(int i=0; i<dim; i++) {      //l'ultima iterazione non è che serva davvero, andrebbe bene anche dim -1
        indiceMin = trovaIndiceMin(array, i, dim);

        temp = array[i];
        array[i] = array[indiceMin];
        array[indiceMin] = temp;
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

    //selection sort
    // printf("%d\n", trovaIndiceMin(testArray, 0, dim));
    selectionSort(testArray, dim);

    //dopo
    printf("\n");
    for(int i=0; i<10; i++) {
        printf("indice: %d, valore: %d\n", i, testArray[i]);
    }

    return 0;
}