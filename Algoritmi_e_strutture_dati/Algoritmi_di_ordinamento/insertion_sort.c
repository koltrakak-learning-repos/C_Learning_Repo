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

void insertionSort(int array[], int dim) {
    int j;

    for(int i=1; i<dim; i++) {      //dentro a questo ciclo, ad ogni iterazione, considero uno slice sempre più grande [0...i]
        int temp = array[i];        //considero dove inserire questo elemento nel sottoarray corrente

        j=i;
        while(j>0 && array[j-1]>temp) {     // questo ciclo shifta gli elementi di una posizione fino a che non raggiungo la posizione in cui copiare l'elemento corrente
            array[j] = array[j-1];
            j--;
        }
        array[j] = temp;
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

    //insertion sort
    insertionSort(testArray, dim);

    //dopo
    printf("\n");
    for(int i=0; i<10; i++) {
        printf("indice: %d, valore: %d\n", i, testArray[i]);
    }

    return 0;
}