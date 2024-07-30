#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

/* --------------------- DEFINIZIONI DI TIPO --------------------- */

typedef int item_t;
typedef struct {
    int dim;
    int cursore_testa;
    int cur_dim;
    item_t* elements;
} queue;

/* --------------------- OPERAZIONI --------------------- */

queue createQueue(int dim);
item_t top(queue);
int isEmpty(queue);
item_t dequeue(queue*);
void enqueue(queue*, item_t);

void stampaQueue(queue);

#endif