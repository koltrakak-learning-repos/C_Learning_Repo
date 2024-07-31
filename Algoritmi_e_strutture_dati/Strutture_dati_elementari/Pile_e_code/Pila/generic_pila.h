/* 
    NB: generico non va inteso nel senso che può contenere tipi diversi di dato (anche se può),
        ma che è generale per qualsiasi tipo di dato anche complesso.
        (una volta scelto che tipo di dato voglio metterci dentro quando faccio pop()/top() faccio un cast a quel tipo li)

 */

#ifndef GENERIC_STACK_H
#define GENERIC_STACK_H

#include <stdio.h>
#include <stdlib.h>


/* --------------------- DEFINIZIONI DI TIPO --------------------- */

typedef void* item_t;
typedef struct {
    int dim;
    int cursore;
    item_t* elements;
} generic_stack;

/* --------------------- OPERAZIONI --------------------- */

generic_stack createStack(int);
item_t top(generic_stack);
int isEmpty(generic_stack);
item_t pop(generic_stack*);
void push(generic_stack*, item_t);

void stampaStack(generic_stack, void (*)(item_t));

#endif