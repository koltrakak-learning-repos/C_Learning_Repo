#include "singularly_linked_list.h"

list emptyList() {
    return NULL;
}

int empty(list lista) {
    if(lista != NULL)
        return 0;

    return 1;
}

int finished(position_t pos) {
    if(pos == NULL) 
        return 1;

    return 0;
}

// poco sensato se non sono bidirezionale
position_t head(position_t pos) {
    if (finished(pos))
        exit(1);

    return pos;
}

//anche questo poco utile
position_t tail(position_t pos) {
    if (finished(pos))
        exit(1);

    position_t tail = pos;
    while( !finished(pos->next) ) {
        pos = pos->next;
    }

    return pos;
}

position_t next(position_t pos) {
    if (finished(pos))
        exit(1);

    return pos->next;
}

/* non implementabile in una lista linkata singolarmente, non ho accesso all'elemento precedente */
// position_t prev(position_t);
// position_t insert(position_t pos, item_t item);
// position_t remove(position_t);

list aggiungi_in_testa(list l, item_t value) {
    list newNodo = (nodo*)malloc(sizeof(nodo));
    newNodo->value = value;
    newNodo->next = l;

    return newNodo;
}
list rimuovi_da_testa(list l) {
    if(empty(l))
        exit(1);

    list result = l->next;
    free(l);

    return result;
}

list aggiungi_in_coda(list l, item_t value) {
    list newNodo = (nodo*)malloc(sizeof(nodo));
    newNodo->value = value;
    newNodo->next = NULL;

    if(empty(l)) {
        return newNodo;
    }

    list temp = l;
    while( !finished(temp->next) ) {
        temp = temp->next;
    }
    temp->next = newNodo;

    return l;
}

void rimuovi_da_coda(list l) {
    if(empty(l))
        exit(1);

    //faccio così per evitare dei dangling pointers, arrivo al penultimo elemento, libero l'ultimo, aggiusto il next del penultimo
    while( !finished(l->next->next) ) {
        l = l->next;
    }

    free(l->next);
    l->next = NULL;
}

item_t read(list l, int indice) {
    if(empty(l))
        exit(1);

    int curIndice = 0;
    while( curIndice!=indice && !finished(l) ) {
        curIndice++;
        l = l->next;
    }

    if(finished(l))
        exit(1);

    return l->value;
}

void write(list l, int indice, item_t value) {
    if(empty(l))
        exit(1);

    int curIndice = 0;
    while( curIndice!=indice && !finished(l) ) {
        curIndice++;
        l = l->next;
    }

    if(finished(l))
        exit(1);

    l->value = value;
}

void stampaLista(list l) {
    if(empty(l))
        exit(1);

    int i=0;

    while( !finished(l) ) {
        printf("elemento %d, value: %d\n", i, l->value);
        i++;
        l=l->next;
    }
}