#include "coda.h"

queue createQueue(int dim) {
    queue q;
    q.dim = dim;
    q.cur_dim = 0;
    q.cursore_testa = 0;
    q.elements = (item_t*)calloc(dim, sizeof(item_t));

    return q;
}


item_t top(queue q) {
    if(q.cur_dim == 0) {
        fprintf(stderr, "hai passato una coda vuota a top()\n");
        exit(EXIT_FAILURE);
    }

    return q.elements[q.cursore_testa];
}

int isEmpty(queue q) {
    return q.cur_dim == 0;
}

item_t dequeue(queue* q) {
    if(q->cur_dim == 0) {
        fprintf(stderr, "hai passato una coda vuota a dequeue()\n");
        exit(EXIT_FAILURE);
    }

    item_t result = q->elements[q->cursore_testa];
    q->cur_dim--;
    q->cursore_testa = (q->cursore_testa + 1) % q->dim;

    return result;
}

void enqueue(queue* q, item_t i) {
    if(q->cur_dim == q->dim) {
        fprintf(stderr, "hai chiamato enqueue() con coda piena\n");
        exit(EXIT_FAILURE);
    }

    q->cur_dim++;
    int indice = (q->cursore_testa + q->cur_dim-1) % q->dim;
    q->elements[indice] = i;
}

void stampaQueue(queue q) {
    if(q.cur_dim == 0) {
        fprintf(stderr, "hai passato una coda vuota a stampaQueue()\n");
    }

    int indiceReale;

    for(int i=0; i<q.cur_dim; i++) {
        indiceReale = (q.cursore_testa + i) % q.dim;
        printf("elemento %d, value: %d\n", i, q.elements[indiceReale]);
    }

    printf("\n");
} 