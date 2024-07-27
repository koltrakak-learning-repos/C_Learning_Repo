#include "doubly_linked_list.h"

list emptyList() {  
    list sentinella = (nodo*)malloc(sizeof(nodo));
    if (sentinella == NULL) {
        fprintf(stderr, "Errore nell'allocazione della memoria\n");
        exit(EXIT_FAILURE);
    }
    
    sentinella->value = -1; //valore arbitrario da non considerare
    sentinella->next = sentinella;
    sentinella->prev = sentinella;

    return sentinella;
}

int empty(list sentinella) {
    if (sentinella == NULL) {
        fprintf(stderr, "Hai passato NULL ad empty(), bruh\n");
        exit(EXIT_FAILURE);
    }

    return (sentinella->prev == sentinella->next && sentinella->next == sentinella);
}

position_t head(list sentinella) {
    if (sentinella == NULL) {
        fprintf(stderr, "Hai passato NULL ad head(), bruh\n");
        exit(EXIT_FAILURE);
    }
    return sentinella->next;
}

position_t tail(list sentinella) {
    if (sentinella == NULL) {
        fprintf(stderr, "Hai passato NULL a tail(), bruh\n");
        exit(EXIT_FAILURE);
    }
    return sentinella->prev;
}

position_t next(position_t pos) {
    if (pos == NULL) {
        fprintf(stderr, "Hai passato NULL a next(), bruh\n");
        exit(EXIT_FAILURE);
    }
    return pos->next;
}

position_t prev(position_t pos) {
    if (pos == NULL) {
        fprintf(stderr, "Hai passato NULL a prev(), bruh\n");
        exit(EXIT_FAILURE);
    }
    return pos->prev;
}

int finished(list sentinella, position_t pos) {
    if (sentinella == NULL || pos == NULL) {
        fprintf(stderr, "Hai passato NULL a finished(), bruh\n");
        exit(EXIT_FAILURE);
    }

    return (pos==sentinella);
}

item_t read(position_t pos) {
    if (pos == NULL) {
        fprintf(stderr, "Hai passato NULL a read(), bruh\n");
        exit(EXIT_FAILURE);
    }

    return pos->value;
}

void write(position_t pos, item_t value) {
    pos->value = value;
}

//NB: sia insert che remove non modificano la posizione passata, per aggiornarla bisogna fare un assegnamento al valore ritornato
position_t insertNode(position_t pos, item_t value) {
    if (pos == NULL) {
        fprintf(stderr, "Hai passato NULL a insert(), bruh\n");
        exit(EXIT_FAILURE);
    }

    list newNode = (nodo*)malloc(sizeof(nodo));
    if (newNode == NULL) {
        fprintf(stderr, "Errore nell'allocazione della memoria\n");
        exit(EXIT_FAILURE);
    }

    newNode->value = value;

    newNode->prev = pos->prev;
    newNode->prev->next = newNode;
    pos->prev = newNode;
    newNode->next = pos;

    return newNode;
}

position_t removeNode(position_t pos) {
    if (pos == NULL) {
        fprintf(stderr, "Hai passato NULL a remove(), bruh\n");
        exit(EXIT_FAILURE);
    }

    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    list result = pos->next;
    free(pos);

    //per assicurarmi che non ci siano dangling pointers dovrei passare la posizione per riferimento e fare così:
    //*pos = result;

    return result;
}

void stampaLista(list sentinella) {
    if (sentinella == NULL) {
        fprintf(stderr, "Hai passato NULL a stampaLista(), bruh\n");
        exit(EXIT_FAILURE);
    }

    position_t pos = head(sentinella);
    int indice = 0;

    while( !finished(sentinella, pos) ) {
        printf("elemento: %d, value: %d\n", indice, pos->value);
        pos = pos->next;
        indice++;
    }

    printf("\n");
}