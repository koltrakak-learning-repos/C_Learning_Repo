#include "../Pila/pila.h"

#define NUM_DISCHI 3

typedef struct {
    stack origine;
    stack destinazione;
    stack intermedio;
} pioli_hanoi;

void stampaHanoi(pioli_hanoi p) {
    int finished = 0, i;
    int cursore_origine = p.origine.cursore;
    int cursore_intermedio = p.intermedio.cursore;
    int cursore_destinazione = p.destinazione.cursore;

    printf("    ORIGINE\t    INTERMEDIO\t     DESTINAZIONE\n");

    for(i=NUM_DISCHI-1; i>=0; i--) {
        if(i <= p.origine.cursore) {
            printf("\t%d\t|\t", p.origine.elements[cursore_origine]);
            cursore_origine--;
        }
        else {
            printf("\t \t|\t");
        }

        if(i <= p.intermedio.cursore) {
            printf("%d\t|\t", p.intermedio.elements[cursore_intermedio]);
            cursore_intermedio--;
        }
        else {
            printf(" \t|\t");
        }

        if(i <= p.destinazione.cursore) {
            printf("%d\n", p.destinazione.elements[cursore_destinazione]);
            cursore_destinazione--;
        }
        else {
            printf(" \n");
        }

        if(cursore_origine == -1 && cursore_intermedio == -1 && cursore_destinazione == -1) {
            finished = 1;
        }
    }

    printf("\n");
}

pioli_hanoi init_hanoi(pioli_hanoi p) {
    p.origine = createStack(NUM_DISCHI);
    p.destinazione = createStack(NUM_DISCHI);
    p.intermedio = createStack(NUM_DISCHI);

    for(int i=NUM_DISCHI; i>0; i--) {
        push(&p.origine, i);
    }

    return p;
}

void hanoiRicorsiva(int numDischi, stack* origine, stack* destinazione, stack* intermedio) {
    pioli_hanoi p;

    if( numDischi == 1) {
        p.origine = *origine;
        p.intermedio = *intermedio;
        p.destinazione = *destinazione;
        stampaHanoi(p);

        push(destinazione, pop(origine));

        p.origine = *origine;
        p.intermedio = *intermedio;
        p.destinazione = *destinazione;
        stampaHanoi(p);
    }
    else {
        //sposto n-1 dischi da origine a intermedio
        hanoiRicorsiva(numDischi-1, origine, intermedio, destinazione);

        p.origine = *origine;
        p.intermedio = *intermedio;
        p.destinazione = *destinazione;
        stampaHanoi(p);
        
        //sposto l'ultimo disco, che è il più grande, da origine a destinazione
        push(destinazione, pop(origine));

        p.origine = *origine;
        p.intermedio = *intermedio;
        p.destinazione = *destinazione;
        stampaHanoi(p);
        //riaggiusto gli n-1 dischi in intermedio a destinazione
        hanoiRicorsiva(numDischi-1, intermedio, destinazione, origine);
    }

    
}

int main() {
    pioli_hanoi p = init_hanoi(p);
 
    hanoiRicorsiva(NUM_DISCHI, &p.origine, &p.destinazione, &p.intermedio);

    return 0;
}