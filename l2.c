#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, i;
    double *notas;
    double soma = 0.0;

    printf("Quantas notas? ");
    scanf("%d", &n);

    notas = malloc(n * sizeof(double));
    if (notas == NULL) {
        printf("Erro no malloc\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        scanf("%lf", &notas[i]);
        soma += notas[i];
    }

    printf("Media: %.2f\n", soma / n);

    free(notas);
    return 0;
}
