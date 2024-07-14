#include<stdio.h>

int main() {
    char c = 88;
    short s = 12;
    printf("%zu; %d\n\n", sizeof(c+s), c+s);  //nota come la somma occupa comunque 4 byte; -> char e short vengono comunque promossi ad int!

    int d1 = 2000000000;
    int d2 = 2000000000;
    long l1 = d1 + d2;                      //qua c'è overflow 
    long l2 = (long)d1 + d2;
    printf("variabile: %ld\n", l1);
    printf("variabile con casting: %ld\n", l2);
    printf("literal: %ld\n\n",d1+d2);       //qua il compilatore promuove, non capisco perche non promuove anche in asegnamento a questo punto

    int x = 88;
    char y = 'c';
    double r = 12.88;

    x = y;
    printf("char -> int: %d\n", x);
    x = y+x;
    printf("char -> int: %d\n", x);
    r = y;
    r += 0.1;
    printf("char -> int -> double: %f\n", r);
    x = r;
    printf("double -> int; troncamento: %d\n", x);

    float f=2.71F; 
    double d=3.1415161718;

    f = d;      // i float hanno 6/7 cifre decimali di precisione quindi questo assegnamente causa una perdita di informazione
                // nonostante questo la conversione double -> float è considerata legittima e non causa warning (flag -Wconversion per mostrare)
    printf("double -> float: %.10lf; perdita di informazione / arrotondamento\n", f);

    return 0;
}