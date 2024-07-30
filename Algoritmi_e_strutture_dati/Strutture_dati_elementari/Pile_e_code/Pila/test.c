#include "pila.h"

int main() {
    stack s = createStack(10);
    printf("%d\n", isEmpty(s));
    stampaStack(s);

    for(int i=0; i<5; i++) {
        push(&s, i);
    }
    stampaStack(s);

    for(int i=0; i<5; i++) {
        push(&s, i+5);
    }
    stampaStack(s);

    printf("%d\n", top(s));
    printf("%d\n", pop(&s));
    stampaStack(s);

    return 0;
}

