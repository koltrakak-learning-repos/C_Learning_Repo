#include "generic_pila.h"

generic_stack createStack(int dim) {
    generic_stack s;
    s.dim = dim;
    s.cursore = -1;
    s.elements= (item_t*)calloc(dim, sizeof(item_t));

    return s;
}

item_t top(generic_stack s) { 
    if( s.cursore == -1 ) {
        fprintf(stderr, "hai passato uno stack vuoto a top()\n");
        exit(EXIT_FAILURE);
    }

    return s.elements[s.cursore];
}

int isEmpty(generic_stack s) {
    return s.cursore == -1;
}

item_t pop(generic_stack* s) {
    if( s->cursore == -1 ) {
        fprintf(stderr, "hai passato uno stack vuoto a pop()\n");
        exit(EXIT_FAILURE);
    }

    item_t result = s->elements[s->cursore];
    s->cursore--; 

    return result; 
}

void push(generic_stack* s, item_t i) {
    if( s->cursore == s->dim-1 ) {
        fprintf(stderr, "hai provato ad aggiungere un elemento ad uno stack pieno, push()\n");
        exit(EXIT_FAILURE);
    }

    s->cursore++;
    s->elements[s->cursore] = i;
}

void stampaStack(generic_stack s, void (*stampaElemento)(item_t elemento)) {
    if( s.cursore == -1 ) {
        printf("stack vuoto\n");
        return;
    }

    for(int i=s.cursore; i>=0; i--) {
        stampaElemento(s.elements[i]);
    }

    printf("\n");
}