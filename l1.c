#include <stdio.h>

int proximo_id(void) {
    static int id = 0;
    id++;
    return id;
}

int main(void) {
    int i;

    for (i = 0; i < 5; i++) {
        printf("%d ", proximo_id());
    }
    printf("\n");

    return 0;
}
