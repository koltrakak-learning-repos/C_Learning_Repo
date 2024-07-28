#include "arrayList.h"

int main() {
    arrayList al = newArrayList();

    printf("dim: %d, curDim %d\n", al.dim, al.cur_dim);
    printf("memoria allocata inizialmente:\n");
    for(int i=0;i<al.dim; i++) {
        printf("indice: %d, indirizzo: %p, value: %d\n", i, al.list+i, *(al.list + i));
    }
    printf("\n");

    for(int i=head(al); i<BASE_ARRAYLIST_DIM/2; i++) {
        insertArrayListElement(&al, i, i);
    }
    printf("dim: %d, curDim %d\n", al.dim, al.cur_dim);
    printf("memoria allocata inizialmente:\n");
    for(int i=0;i<al.dim; i++) {
        printf("indice: %d, indirizzo: %p, value: %d\n", i, al.list+i, *(al.list + i));
    }
    printf("\n");

    for(int i = 0; i<BASE_ARRAYLIST_DIM/2; i++) {
        insertArrayListElement(&al, i, i+5);
    }
    printf("dim: %d, curDim %d\n", al.dim, al.cur_dim);
    printf("memoria allocata inizialmente:\n");
    for(int i=0;i<al.dim; i++) {
        printf("indice: %d, indirizzo: %p, value: %d\n", i, al.list+i, *(al.list + i));
    }
    printf("\n");

    insertArrayListElement(&al, 10, 100);
    printf("dim: %d, curDim %d\n", al.dim, al.cur_dim);
    printf("memoria allocata inizialmente:\n");
    for(int i=0;i<al.dim; i++) {
        printf("indice: %d, indirizzo: %p, value: %d\n", i, al.list+i, *(al.list + i));
    }
    printf("\n");
    stampaLista(al);

    removeArrayListElement(&al, 9);
    printf("dim: %d, curDim %d\n", al.dim, al.cur_dim);
    printf("memoria allocata inizialmente:\n");
    for(int i=0;i<al.dim; i++) {
        printf("indice: %d, indirizzo: %p, value: %d\n", i, al.list+i, *(al.list + i));
    }
    printf("\n");
    stampaLista(al);

    return 0;
}