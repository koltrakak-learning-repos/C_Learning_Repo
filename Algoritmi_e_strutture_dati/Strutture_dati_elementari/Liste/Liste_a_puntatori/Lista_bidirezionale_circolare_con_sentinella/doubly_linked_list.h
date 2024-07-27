#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>

/* ----------------- DEFINIZIONI DI TIPO ----------------- */
typedef int item_t;

//NB: questa è una struttura dati ricorsiva!
//    è strettamente necessario dare un nome alla struct (in questo caso list_element) e non lasciare una struttura anonima
//    in quanto nel caso di struttura anonima l'elemento next non direbbe al compilatore nulla a che cosa sta puntando.
//    (non si può neanche lasciare una struct anonima e usare il nuovo tipo, in questo caso nodo, dato che dentro alla definizione della struct
//     il nuovo tipo non è ancora stato definito)
typedef struct list_element {
    item_t value;
    struct list_element* next;
    struct list_element* prev;
} nodo;

typedef nodo* list;
typedef nodo* position_t;

/* ----------------- OPERAZIONI ----------------- */

list emptyList();
int empty(list);

position_t head();
position_t tail();
position_t next(position_t);
position_t prev(position_t);

int finished(list, position_t);

item_t read(position_t);
void write(position_t, item_t value);
position_t insertNode(position_t, item_t);
position_t removeNode(position_t);

void stampaLista(list l);

#endif // DOUBLY_LINKED_LIST_H