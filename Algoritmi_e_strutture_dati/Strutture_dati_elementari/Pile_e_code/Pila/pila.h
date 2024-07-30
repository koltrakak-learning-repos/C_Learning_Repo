#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

/* --------------------- DEFINIZIONI DI TIPO --------------------- */

typedef int item_t;
typedef struct {
    int dim;
    int cursore;
    item_t* elements;
} stack;

/* --------------------- OPERAZIONI --------------------- */

stack createStack(int);
item_t top(stack);
int isEmpty(stack);
item_t pop(stack*);
void push(stack*, item_t);

void stampaStack(stack);

#endif