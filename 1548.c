#include <stdio.h>
#include <stdlib.h>

void intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        if (v[i] >= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];

    for (i = p; i < r; i++) v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int compara(int c[], int p[], int m) {
    int qtd = 0;
    for (int j = 0; j < m; j++) {
        if (c[j] == p[j]) qtd++;
    }
    return qtd;
}

int main() {
    int N, M, P[1000], C[1000];

    scanf("%d", &N);  

    for (int t = 0; t < N; t++) {
        scanf("%d", &M);

        for (int j = 0; j < M; j++) {
            scanf("%d", &P[j]);
            C[j] = P[j];
        }

        mergesort(0, M, P); 
        printf("%d\n", compara(C, P, M));
    }

    return 0;
}
