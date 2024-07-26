#include "singularly_linked_list.h"

int main() {
    item_t var = 0;

    nodo n = {3, NULL};
    nodo n2 = {4, NULL};
    n.next = &n2;
    printf("value: %d, size: %ld\n", var, sizeof(item_t));
    //notare i byte di padding, dimensione effettiva 16 != dimensione teorica 9
    printf("value: %d, next_value: %d; node_size: %ld\n", n.value, n.next->value, sizeof(nodo));    

    list l;
    l = &n;
    while(l != NULL) {
        printf("value: %d\n", l->value);
        l = l->next;
    }
    printf("\n");

    /* ------------------- testing operazioni ------------------- */
    list lista = emptyList();

    for(register int i=0; i<10; i++) {
        lista = aggiungi_in_testa(lista, (item_t)i);
        
    }
    stampaLista(lista);
    printf("\n");

    lista = aggiungi_in_coda(lista, 100);
    stampaLista(lista);
    printf("\n");

    lista = rimuovi_da_testa(lista);
    rimuovi_da_coda(lista);
    stampaLista(lista);
    printf("\n");

    printf("valore ad indice 5: %d\n", read(lista, 5));
    write(lista, 5, 13);
    printf("valore ad indice 5: %d\n", read(lista, 5));
    //printf("valore ad indice 10: %d\n", read(lista, 10));
    printf("\n");

    lista = tail(lista);
    stampaLista(lista);
    printf("\n");

    return 0;
}