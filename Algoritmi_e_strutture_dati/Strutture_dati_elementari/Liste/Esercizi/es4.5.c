#include "../Liste_a_puntatori/Lista_bidirezionale_circolare_con_sentinella/doubly_linked_list.h"

#include <time.h>

/*
    Si scriva una procedura ricorsiva che data una lista L di interi, la modifichi eliminando ogni elemento pari e duplicando ogni elemento dispari tante volte 
    quanti sono gli elementi pari che lo precedono. (p.e. L={4,6,7,3,2,5} allora L={7,7,7,3,3,3,5,5,5,5}) 
*/
void eliminaPariDuplicaDispari(list l , position_t testa, int contaPari) {
    if( finished(l, testa) ) {
        return;
    }
    else{
        if( read(testa)%2 == 0 ) {
            contaPari++;
            testa = removeNode(testa);

            eliminaPariDuplicaDispari(l, testa, contaPari);
        }
        else {
            for(int i=0; i<contaPari; i++) {
                insertNode(testa, read(testa));
            }

            eliminaPariDuplicaDispari(l, next(testa), contaPari);
        }
    }
}


void eliminaPariDuplicaDispariIterativa(list L) {
    int contaPari = 0;
    position_t curPos = head(L);

    while( !finished(L, curPos) ) {
        if( read(curPos)%2 == 0 ) {
            contaPari++;
            curPos = removeNode(curPos);
        }
        else {
            for(int i=0; i<contaPari; i++) {
                insertNode(curPos, read(curPos));
            }

            curPos = next(curPos);
        }
    }
}// O(n-1 scorrimenti + n-1 eliminazioni + n-1 inserimenti) => O(n)

int main() {
    list L = emptyList();
    srand(time(NULL));
    for(int i=0; i<5; i++) {
        insertNode(L, (rand()%100 + 1));
    }
    stampaLista(L);

    eliminaPariDuplicaDispari(L, head(L), 0);
    stampaLista(L);

    return 0;
}