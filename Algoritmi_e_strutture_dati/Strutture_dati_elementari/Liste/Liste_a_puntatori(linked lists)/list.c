#include <stdlib.h>
#include "list.h"

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
    if (empty(pos))
        exit(1);

    return pos;
}

position_t tail(position_t pos) {
    if (empty(pos))
        exit(1);

    position_t tail = pos;
    while( !finished(pos->next) ) {
        pos = pos->next;
    }

    return pos;
}

position_t next(position_t);
position_t prev(position_t);

position_t insert(position_t, item_t);
position_t remove(position_t);
item_t read(position_t);
void write(position_t, item_t);
