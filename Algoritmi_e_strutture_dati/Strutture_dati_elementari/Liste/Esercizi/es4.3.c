#include "../Liste_a_puntatori/Lista_bidirezionale_circolare_con_sentinella/doubly_linked_list.h"

/*
    Si rappresenta un numero decimale attraverso una lista in cui ogni nodo è una cifra. 
    Si scriva una funzione che effettui una somma tra due liste.
*/
list somma(list L1, list L2) {
    position_t cursore_1 = tail(L1);
    position_t cursore_2 = tail(L2); 

    list result = emptyList();

    int riporto = 0;

    while( !( finished(L1, cursore_1) && finished(L2, cursore_2) ) ) {
        if( !finished(L1, cursore_1) && !finished(L2, cursore_2) ) { 
            //somma
            int somma = read(cursore_1) + read(cursore_2);
            int resto;
            if( somma >= 10) {
                resto = somma % 10;
            }
            else {
                resto = somma;
            }

            //inserimento
            insertNode(head(result) , resto + riporto); 
            //calcolo riporto per prossima iterazione
            riporto = somma / 10;

            //incremento cursori
            cursore_1 = prev(cursore_1);
            cursore_2 = prev(cursore_2);
        }
        else if( finished(L1, cursore_1) ) {
            insertNode(head(result) , read(cursore_2) + riporto); 
            cursore_2 = prev(cursore_2);
            riporto = 0;
        }
        else {
            insertNode(head(result) , read(cursore_1) + riporto); 
            cursore_1 = prev(cursore_1);
            riporto = 0;
        }
    }

    //riporto finale
    if(riporto != 0) {
        insertNode(head(result) , riporto);
    }

    return result;
}   

int main() {
    list L1 = emptyList();
    list L2 = emptyList();

    insertNode(L1, 9);
    insertNode(L1, 9);
    insertNode(L1, 9);
    insertNode(L2, 9);
    insertNode(L2, 9);
    insertNode(L2, 9);

    stampaLista(L1);
    stampaLista(L2);
    
    list result = somma(L1, L2);

    printf("Somma\n");
    stampaLista(result);
    
    return 0;
}