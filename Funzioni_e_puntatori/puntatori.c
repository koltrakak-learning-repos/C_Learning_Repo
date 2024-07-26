#include<stdio.h>
#include<stdlib.h>


int main() {
    int a = 3;
    float b = 4.12f;
    int* intp = &a;
    float* floatp = &b;

    printf("%p, %lu bytes\n", intp, sizeof(intp));
    printf("%p, %lu bytes\n", floatp, sizeof(floatp));

    //continua...

    return 0;
}