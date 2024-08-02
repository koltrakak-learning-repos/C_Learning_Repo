#include "../Liste_a_puntatori/Lista_bidirezionale_circolare_con_sentinella/doubly_linked_list.h"

#include <time.h>


/*
    Dopo essere stati inquisiti per tangentopoli, n politici hanno deciso di suicidarsi diponendosi in cerchio ed uccidendo una persona ogni k.
    Si scriva una procedura che data la lista L degli aspiranti suicidi, e dato k (1<=k<=n) stampi l'ordine delle vittime.
    (p.e. se L=caio, sempronio, tizio, tullio; e k=3; allora l'ordine delle vittime è: tizio, sempronio, tullio, caio).  
*/
void stampaSuicidi(list L, int k) {
    int contatore = 1;

    position_t curPos = head(L);

    while( !empty(L) ) {
        curPos = next(curPos);
        contatore++;

        if( finished(L, curPos) ) {
            curPos = next(curPos);
        }

        if( contatore == k) {
            printf("%d\n", read(curPos));
            curPos = removeNode(curPos);
            contatore = 1;
        }
    }
}   // k*n scorrimenti, O(n);

int main() {
    list L = emptyList();
    srand(time(NULL));
    for(int i=0; i<10; i++) {
        insertNode(L, (rand()%100 + 1));
    }
    stampaLista(L);

    stampaSuicidi(L, 3);
    
    stampaLista(L);

    return 0;
}