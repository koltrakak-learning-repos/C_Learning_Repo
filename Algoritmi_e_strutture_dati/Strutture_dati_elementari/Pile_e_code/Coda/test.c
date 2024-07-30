#include "coda.h"

int main() {
    queue q = createQueue(10);
    printf("%d\n", isEmpty(q));
    stampaQueue(q);

    for(int i=0; i<q.dim; i++) {
        enqueue(&q, i);
        stampaQueue(q);

        if(i%3 == 0) {
            dequeue(&q);
            stampaQueue(q);
        }

    }

    printf("%d\n", top(q));

    return 0;
}

