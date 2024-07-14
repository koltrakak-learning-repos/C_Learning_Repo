#include <stdio.h>
#include <limits.h>

int main() {
    char a;
    printf("CHAR:\n");
    printf("\tSize: %zu bytes\n", sizeof(a));   // sizeof() restituisce un size_t (equivalente ad un long unsigned int); utilizziamo quindi il formanto %zu per stamparlo
    printf("\tMin: %d\n", CHAR_MIN);
    printf("\tMax: %d\n", CHAR_MAX);
    signed char b;
    printf("SIGNED CHAR:\n");
    printf("\tSize: %zu bytes\n", sizeof(b));
    printf("\tMin: %d\n", SCHAR_MIN);
    printf("\tMax: %d\n", SCHAR_MAX);
    unsigned char c;
    printf("UNSIGNED CHAR:\n");
    printf("\tSize: %zu bytes\n", sizeof(c));
    printf("\tMin: 0\n");                       // il minimo dei tipi unsigned è sempre zero
    printf("\tMax: %u\n---\n", UCHAR_MAX);

    // Dimensione di int e unsigned int non fissa. Dipende dal compilatore
    int a_int;
    printf("INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(a_int));
    printf("\tMin: %d\n", INT_MIN);
    printf("\tMax: %d\n", INT_MAX);
    signed int b_sint;
    printf("SIGNED INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(b_sint));
    printf("\tMin: %d\n", INT_MIN);
    printf("\tMax: %d\n", INT_MAX);
    unsigned int c_uint;
    printf("UNSIGNED INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(c_uint));
    printf("\tMin: 0\n");
    printf("\tMax: %u\n---\n", UINT_MAX);

    short int a_sint;
    printf("SHORT INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(a_sint));
    printf("\tMin: %d\n", SHRT_MIN);
    printf("\tMax: %d\n", SHRT_MAX);
    signed short int b_ssint;
    printf("SIGNED SHORT INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(b_ssint));
    printf("\tMin: %d\n", SHRT_MIN);
    printf("\tMax: %d\n", SHRT_MAX);
    unsigned short int c_usint;
    printf("UNSIGNED SHORT INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(c_usint));
    printf("\tMin: 0\n");
    printf("\tMax: %u\n", USHRT_MAX);
    short d_short;
    printf("SHORT:\n");
    printf("\tSize: %zu bytes\n", sizeof(d_short));
    printf("\tMin: %d\n", SHRT_MIN);
    printf("\tMax: %d\n---\n", SHRT_MAX);

    long int a_lint;
    printf("LONG INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(a_lint));
    printf("\tMin: %ld\n", LONG_MIN);
    printf("\tMax: %ld\n", LONG_MAX);
    signed long int b_slint;
    printf("SIGNED LONG INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(b_slint));
    printf("\tMin: %ld\n", LONG_MIN);
    printf("\tMax: %ld\n", LONG_MAX);
    unsigned long int c_ulint;
    printf("UNSIGNED LONG INT:\n");
    printf("\tSize: %zu bytes\n", sizeof(c_ulint));
    printf("\tMin: 0\n");
    printf("\tMax: %lu\n", ULONG_MAX);
    long d_long;
    printf("LONG:\n");
    printf("\tSize: %zu bytes\n", sizeof(d_long));
    printf("\tMin: %ld\n", LONG_MIN);
    printf("\tMax: %ld\n\n", LONG_MAX);

    printf("----------------------- ESPERIMENTI -----------------------\n");

    unsigned char carattere = 75;
    printf("%c\n", carattere);
    printf("%d\n", carattere);

    return 0;
}

