#include <stdio.h>

int main() {
    int a;
    int res = scanf("%d", &a);  
    
    //NB: bisogna controllare il valore di ritorno della scanf!
    if (res == 1) {
        // Input corretto
        printf("result: %d, value: %d\n", res, a);
    } else if (res == 0) {      //potrei inserire un carattere al posto di un intero
        // Input non valido
        printf("Input non valido, non è stato inserito un numero.\n");
    } else if (res == EOF) {    //potrei anche inserire EOF e proseguire nel programma bypassando questo input
        // EOF inserito
        printf("EOF inserito.\n");
    }

    //Problema comune: carattere di fine linea rimasto nel buffer di input
    float reale1;
    char car1;
    printf("Inserire un numero reale: ");
    scanf("%f", &reale1);

    getchar();       //soluzione consumare il carattere

    printf("\nInserire un carattere: ");
    scanf("%c", &car1);
    printf("\nLetti: %f,%c\n", reale1, car1);

    return 0;
}