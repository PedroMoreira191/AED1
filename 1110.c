#include <stdio.h>
#include <stdlib.h>

// usando fila

typedef struct cel {
    int valor;
    struct cel* seg;
} celula;

celula *inicio = NULL, *fim = NULL;

void enfileira(int x) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = x;
    nova->seg = NULL;
    if (fim != NULL)
        fim->seg = nova;
    else
        inicio = nova;
    fim = nova;
}

int desenfileira() {
    if (inicio == NULL) return -1;
    celula *p = inicio;
    int x = p->valor;
    inicio = inicio->seg;
    if (inicio == NULL) fim = NULL;
    free(p);
    return x;
}

void libera() {
    while (inicio != NULL)
        desenfileira();
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        int descartadas[50];
        int d = 0;

        // monta a fila de 1 até n
        for (int i = 1; i <= n; i++)
            enfileira(i);

        // executa as operações
        while (inicio != fim) {
            descartadas[d++] = desenfileira();     // descarta topo
            enfileira(desenfileira());             // move próxima para base
        }

        // imprime resultados
        printf("Discarded cards:");
        if (d > 0) {
            printf(" %d", descartadas[0]);
            for (int i = 1; i < d; i++)
                printf(", %d", descartadas[i]);
        }
        printf("\nRemaining card: %d\n", inicio->valor);

        libera();
    }
    return 0;
}
