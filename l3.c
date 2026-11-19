#include <stdio.h>
#include <stdlib.h>

int *cria_sequencia(int n) {
    int *v, i;

    v = malloc(n * sizeof(int));
    if (v == NULL) {
        return NULL;
    }

    for (i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    return v;
}

int main(void) {
    int *v, i;
    int n = 5;

    v = cria_sequencia(n);
    if (v == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    return 0;
}
