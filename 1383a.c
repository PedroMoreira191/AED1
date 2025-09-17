#include <stdio.h>
#define SIZE 9
int verifica_unicidade(int vetor[]) {
    int i, frequencia[10] = {0};
    for (i = 0; i < SIZE; i++) {
        int num = vetor[i];
        if (num < 1 || num > 9 || frequencia[num]) {
            return 0;
        }
        frequencia[num] = 1;
    }
    return 1;
}
int verifica_linhas(int matriz[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        if (!verifica_unicidade(matriz[i])) {
            return 0;
        }
    }
    return 1;
}
int verifica_colunas(int matriz[SIZE][SIZE]) {
    for (int j = 0; j < SIZE; j++) {
        int coluna[SIZE];
        for (int i = 0; i < SIZE; i++) {
            coluna[i] = matriz[i][j];
        }
        if (!verifica_unicidade(coluna)) {
            return 0;
        }
    }
    return 1;
}
int verifica_subgrades(int matriz[SIZE][SIZE]) {
    for (int linha = 0; linha < SIZE; linha += 3) {
        for (int coluna = 0; coluna < SIZE; coluna += 3) {
            int subgrade[SIZE];
            int k = 0;
            for (int i = linha; i < linha + 3; i++) {
                for (int j = coluna; j < coluna + 3; j++) {
                    subgrade[k++] = matriz[i][j];
                }
            }
            if (!verifica_unicidade(subgrade)) {
                return 0;
            }
        }
    }
    return 1;
}
int eh_sudoku_valido(int matriz[SIZE][SIZE]) {
    return verifica_linhas(matriz) &&
           verifica_colunas(matriz) &&
           verifica_subgrades(matriz);
}
int main() {
    int n;
    scanf("%d", &n);
    for (int instancia = 1; instancia <= n; instancia++) {
        int matriz[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        printf("Instancia %d\n", instancia);
        if (eh_sudoku_valido(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }
    return 0;
}
