#include "../Liste_a_puntatori/Lista_bidirezionale_circolare_con_sentinella/doubly_linked_list.h"

/*
    Si scriva una procedura ricorsiva di complessità ottima che, dato un intero n >= 1,
    costruisca due liste L e M tali che: L = 1, 2, ..., n ed M = n, n-1, ..., 1 
*/
void primiNInteri(int n, list L, list M) {
    //assumo che alla prima invocazione L e M siano liste vuote
    if( n == 0 ) {
        return;
    }
    else{
        //per L aggiungo in ogni nuovo elemento in testa, quelli più grandi si sposteranno verso destra
        insertNode(head(L), n);
        //per M aggiungo in coda
        insertNode(next(tail(M)), n);   // equivalente a insertNode(L, n); 

        primiNInteri(n-1, L, M);
    }

}

int main() {
    list L = emptyList();
    list M = emptyList();
    primiNInteri(10, L, M);

    printf("L, ordine crescente\n");
    stampaLista(L);
    printf("M, ordine decrescente\n");
    stampaLista(M);
    
    return 0;
}