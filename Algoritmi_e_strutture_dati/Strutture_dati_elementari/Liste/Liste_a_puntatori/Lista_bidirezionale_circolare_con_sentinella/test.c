#include "doubly_linked_list.h"

int main() {
    list l = emptyList();
    printf("%d\n", empty(l));
    stampaLista(l);

    position_t curPos = head(l);
    for(int i=0; i<10; i++) {
        insertNode(curPos, i);
    }
    stampaLista(l);

    curPos = next(curPos);
    insertNode(curPos, 100);
    stampaLista(l);

    curPos = tail(l);
    curPos = prev(curPos);
    curPos = removeNode(curPos);    // occhio ai dangling pointers
    stampaLista(l);

    int newValue = read(curPos) + 12;
    write(curPos, newValue);
    stampaLista(l);

    
    return 0;
}