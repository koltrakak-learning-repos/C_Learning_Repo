#include<stdio.h>

int main() {
    int a = 1;
    printf("sono fuori dal blocco, a vale: %d\n", a);

    {
        int a = 3;
        printf("sono dentro ad un altro blocco, a vale: %d\n", a);
    }

    //char a = 62; non posso definire la stessa variabile due volte nello stesso blocco
    return 0;
}