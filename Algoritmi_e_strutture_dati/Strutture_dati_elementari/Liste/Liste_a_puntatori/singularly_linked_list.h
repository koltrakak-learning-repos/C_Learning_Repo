#include <stdlib.h>
#include <stdio.h>

/* ----------------- DEFINIZIONI DI TIPO ----------------- */
typedef char item_t;

//NB: questa è una struttura dati ricorsiva!
//    è strettamente necessario dare un nome alla struct (in questo caso list_element) e non lasciare una struttura anonima
//    in quanto nel caso di struttura anonima l'elemento next non direbbe al compilatore nulla a che cosa sta puntando.
//    (non si può neanche lasciare una struct anonima e usare il nuovo tipo, in questo caso nodo, dato che dentro alla definizione della struct
//     il nuovo tipo non è ancora stato definito)
typedef struct list_element {
    item_t value;
    struct list_element* next;         
} nodo;

typedef nodo* list;
typedef nodo* position_t;

/* ----------------- OPERAZIONI ----------------- */

list emptyList();
int empty(list);
int finished(position_t);
position_t head();
position_t tail();
position_t next(position_t);
list aggiungi_in_testa(list l, item_t value);
list rimuovi_da_testa(list l);
list aggiungi_in_coda(list l, item_t value);
void rimuovi_da_coda(list l);
item_t read(list l, int indice);
void write(list l, int indice, item_t value);

void stampaLista(list l);

