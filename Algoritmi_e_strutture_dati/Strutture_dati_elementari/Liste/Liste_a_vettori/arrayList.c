#include "arrayList.h"

//TODO: fai gestione degli errori

arrayList newArrayList() {
    list l = (item_t*)calloc(BASE_ARRAYLIST_DIM, sizeof(item_t));

    arrayList result;
    result.dim = BASE_ARRAYLIST_DIM;
    result.cur_dim = 0;
    result.list = l;

    return result;
}

int empty(arrayList al) {
    if(al.cur_dim == 0) {
        return 1;
    }

    return 0;
}

int head(arrayList al) {
    return 0;
}

int tail(arrayList al) {
    return al.cur_dim-1;
}

int next(int pos) {
    return pos+1;
}

int prev(int pos) {
    return pos-1;
}

int finished(arrayList al, int pos) {
    if(pos == al.cur_dim)
        return 1;
    
    return 0;
}

item_t read(arrayList al, int pos) {
    return al.list[pos];
}

void write(arrayList al, int pos, item_t value) {
    al.list[pos] = value;
}

int insertArrayListElement(arrayList* al, int pos, item_t value) {
    //controllo se c'è spazio
    if(al->cur_dim == al->dim) {
        //resize
        al->dim *= 2;
        list temp = (item_t*)calloc(al->dim, sizeof(item_t));
        //copy
        for(int i=0; i<al->cur_dim; i++) {
            temp[i] = al->list[i];
        }
        //libera vecchia memoria
        free(al->list);
        //assegna nuova memoria
        al->list = temp;
    }

    //shift a destra
    for(int i=al->cur_dim; i>pos; i--) {
        al->list[i] = al->list[i-1];
    }
    al->list[pos] = value;
    al->cur_dim++;

    return pos;
}

int removeArrayListElement(arrayList* al, int pos) {
    //shift a sinistra
    for(int i=pos; i<al->cur_dim-1; i++) {
        al->list[i] = al->list[i + 1];
    }
    //al.list[cur_dim] = 0; posso anche fare niente
    al->cur_dim--;

    return pos;
}

void stampaLista(arrayList al) {
    for(int i=0; i<al.cur_dim; i++) {
        printf("elemento: %d, value: %d\n", i, al.list[i]);
    }
    printf("\n");
}
