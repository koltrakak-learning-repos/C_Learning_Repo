#include <stdio.h>
#include <float.h>

int main() {
    float a;
    printf("FLOAT:\n");
    printf("\tSize: %zu bytes\n", sizeof(a));
    printf("\tMin: %e\n", FLT_MIN);  // Usa %e per una rappresentazione scientifica
    printf("\tMax: %e\n", FLT_MAX);
    printf("\tMin negativo: %e\n", -FLT_MAX);

    double b;
    printf("DOUBLE:\n");
    printf("\tSize: %zu bytes\n", sizeof(b));
    printf("\tMin: %e\n", DBL_MIN);
    printf("\tMax: %e\n", DBL_MAX);
    printf("\tMin negativo: %e\n", -DBL_MAX);

    long double c;
    printf("LONG DOUBLE:\n");
    printf("\tSize: %zu bytes\n", sizeof(c));
    printf("\tMin: %Le\n", LDBL_MIN); // Usa %Le per long double
    printf("\tMax: %Le\n", LDBL_MAX);
    printf("\tMin negativo: %Le\n", -LDBL_MAX);
 
    printf("----------------------- ESPERIMENTI -----------------------\n");

    return 0;
}
