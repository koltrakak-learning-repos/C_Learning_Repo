// #include "pila.h"
#include "generic_pila.h"

struct tipoStrano {
    int a;
    char b;
    float c;
};

void stampaElemento(item_t elemento) {
    struct tipoStrano* t = (struct tipoStrano*)elemento;
    printf("%d - %c - %f\n", t->a, t->b, t->c);
}


int main() {
    // stack s = createStack(10);
    // printf("%d\n", isEmpty(s));
    // stampaStack(s);

    // for(int i=0; i<5; i++) {
    //     push(&s, i);
    // }
    // stampaStack(s);

    // for(int i=0; i<5; i++) {
    //     push(&s, i+5);
    // }
    // stampaStack(s);

    // printf("%d\n", top(s));
    // printf("%d\n", pop(&s));
    // stampaStack(s);

    generic_stack gs = createStack(10);
    printf("%d\n", isEmpty(gs));
    stampaStack(gs, stampaElemento);

    /*
        ATTENZIONE COMPORTAMENTO CHE NON MI ASPETTAVO
        facendo come sotto 'a' non viene riallocata ma cambia semplicemente valore.
        Di conseguenza nello stack tutte le posizioni vengono modificate all'ultimo valore.
        Utilizzando allocazione dinamica a viene riallocata e quindi questo problema scompare, tuttavia bisogna stare attenti a liberare la memoria. 
    */
    // for(int i=0; i<5; i++) {
    //     struct tipoStrano a = {i, 'a', i};
    //     printf("%p\n", &a);
    //     push(&gs, &a);
    // }
    // stampaStack(gs, stampaElemento);

    for(int i=0; i<5; i++) {
        struct tipoStrano* a = (struct tipoStrano*)malloc(sizeof(struct tipoStrano));
        a->a = i;
        a->b = 'c';
        a->c = i; 
        printf("%p\n", a);
        push(&gs, a);
    }
    stampaStack(gs, stampaElemento);

    return 0;
}

