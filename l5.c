#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *v, i;

    v = malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++) {
        v[i] = i * 10;
    }

    free(v);

    // leitura depois do free, de proposito
    printf("%d\n", v[2]);

    return 0;
}
