#include <kevin_stuff/kr_alloc.h>
#include <stdio.h>

int main() {
    int *int_array = (int *)kr_malloc(10*sizeof(int));

    for(int i=0; i<10; i++) {
        int_array[i]=i;
    }

    for(int i=0; i<10; i++) {
        printf("%d\n", int_array[i]);
    }

    kr_free(int_array);
}
