#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int verifica_unicidade(int vetor[]) {
    int freq[10] = {0};
    for (int i = 0; i < SIZE; i++) {
        int num = vetor[i];
        if (num < 1 || num > 9 || freq[num]) return 0;
        freq[num] = 1;
    }
    return 1;
}

int verifica_linhas(int **m) {
    for (int i = 0; i < SIZE; i++) {
        if (!verifica_unicidade(m[i])) return 0;
    }
    return 1;
}

int verifica_colunas(int **m) {
    for (int j = 0; j < SIZE; j++) {
        int col[SIZE];
        for (int i = 0; i < SIZE; i++) {
            col[i] = m[i][j];
        }
        if (!verifica_unicidade(col)) return 0;
    }
    return 1;
}

int verifica_subgrades(int **m) {
    for (int lin = 0; lin < SIZE; lin += 3) {
        for (int col = 0; col < SIZE; col += 3) {
            int sub[SIZE], k = 0;
            for (int i = lin; i < lin + 3; i++) {
                for (int j = col; j < col + 3; j++) {
                    sub[k++] = m[i][j];
                }
            }
            if (!verifica_unicidade(sub)) return 0;
        }
    }
    return 1;
}

int eh_sudoku_valido(int **m) {
    return verifica_linhas(m) && verifica_colunas(m) && verifica_subgrades(m);
}

int main() {
    int n;
    scanf("%d", &n);

    int **matriz = (int **) malloc(SIZE * sizeof(int *));
    if (matriz == NULL) return 1;

    for (int i = 0; i < SIZE; i++) {
        matriz[i] = (int *) malloc(SIZE * sizeof(int));
        if (matriz[i] == NULL) return 1;
    }

    for (int instancia = 1; instancia <= n; instancia++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);
        if (eh_sudoku_valido(matriz)) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    for (int i = 0; i < SIZE; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
