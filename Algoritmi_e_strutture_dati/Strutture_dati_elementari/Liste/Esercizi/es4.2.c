#include "../Liste_a_puntatori/Lista_bidirezionale_circolare_con_sentinella/doubly_linked_list.h"

/*
    Si scriva una procedura che, data una list L di interi, restituisca un'altra lista M che contenga solamente gli elementi di L
    i cui valori NON compaiono esattamente due volte (p.e., se L = {5, 7, 3, 2, 2, 1, 2, 3} -> M = {5, 7, 2, 2, 1, 2}) 
*/
list epurazione(list L) {
    list M = emptyList();

    position_t testa = head(L);

    while( !finished(L, testa) ) {
        position_t cursore = head(L);
        int contatore = 0;

        while( !finished(L, cursore) ) {
            if( read(testa) == read(cursore) ) 
                contatore++;

            cursore = next(cursore);
        }

        if( contatore != 2 ) {
            insertNode(M, read(testa)); //inserimento in coda (inserimento sequenziale, guarda es4.1 se confuso) 
        }

        testa = next(testa);
    }

    return M;
}   // doppia scansione -> complessità O(n^2)

int main() {
    list L = emptyList();

    insertNode(L, 1);
    insertNode(L, 3);
    insertNode(L, 1);
    insertNode(L, 2);
    insertNode(L, 1);
    insertNode(L, 3);

    stampaLista(L);
    
    list M = epurazione(L);

    stampaLista(M);
    
    return 0;
}