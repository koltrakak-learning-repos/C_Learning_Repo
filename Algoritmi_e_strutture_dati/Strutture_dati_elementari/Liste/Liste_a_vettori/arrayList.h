#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stdlib.h>
#include <stdio.h>

#define BASE_ARRAYLIST_DIM 10

/* ----------------- DEFINIZIONI DI TIPO ----------------- */
typedef int item_t;
typedef item_t* list;

typedef struct {
    unsigned int dim;
    unsigned int cur_dim;    
    list list;
} arrayList;


/* ----------------- OPERAZIONI ----------------- */

arrayList newArrayList();
int empty(arrayList);

int head(arrayList);
int tail(arrayList);
int next(int);
int prev(int);

int finished(arrayList, int pos);

item_t read(arrayList, int);
void write(arrayList, int, item_t);
int insertArrayListElement(arrayList*, int, item_t);
int removeArrayListElement(arrayList*, int);

void stampaLista(arrayList);

#endif // ARRAY_LIST_H