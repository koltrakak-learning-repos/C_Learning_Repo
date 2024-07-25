#include <stdio.h>

#include "list.h"

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


    return 0;
}