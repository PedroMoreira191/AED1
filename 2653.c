#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char *buffer = malloc(1000005);   // buffer para ler strings enormes
    char **joias = NULL;              // vetor dinâmico de ponteiros
    int qtd = 0;                      // quantidade de joias distintas
    int capacidade = 0;

    while (scanf("%s", buffer) == 1) {

        int i, igual = 0;

        // verifica se já existe entre as anteriores
        for (i = 0; i < qtd; i++) {
            if (strcmp(joias[i], buffer) == 0) {
                igual = 1;
                break;
            }
        }

        if (!igual) {

            // aumenta capacidade do vetor se precisar
            if (qtd == capacidade) {
                capacidade = capacidade == 0 ? 2 : capacidade * 2;
                joias = realloc(joias, capacidade * sizeof(char *));
            }

            // aloca e copia a nova string
            joias[qtd] = malloc(strlen(buffer) + 1);
            strcpy(joias[qtd], buffer);
            qtd++;
        }
    }

    printf("%d\n", qtd);

    // libera memória
    for (int i = 0; i < qtd; i++) {
        free(joias[i]);
    }
    free(joias);
    free(buffer);

    return 0;
}
