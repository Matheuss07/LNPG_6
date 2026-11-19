#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v, i;

    v = malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++) {
        v[i] = i * 10;
    }

    printf("%d\n", v[2]);

    free(v);
    v = NULL;

    return 0;
}
