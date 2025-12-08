#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int inicio, int meio, int fim){
    int i = inicio, j = meio + 1, k = 0;
    int tam = fim - inicio + 1;

    int *aux = (int*) malloc(tam * sizeof(int));

    while(i <= meio && j <= fim){
        if(v[i] < v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }

    while(i <= meio) aux[k++] = v[i++];
    while(j <= fim) aux[k++] = v[j++];

    for(i = inicio, k = 0; i <= fim; i++, k++)
        v[i] = aux[k];

    free(aux);
}

void mergeSort(int *v, int inicio, int fim){
    if(inicio < fim){
        int meio = (inicio + fim) / 2;
        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}

int main(){
    int NC, N;
    scanf("%d", &NC);

    while(NC--){
        scanf("%d", &N);

        int *h = (int*) malloc(N * sizeof(int));

        for(int i = 0; i < N; i++)
            scanf("%d", &h[i]);

        mergeSort(h, 0, N-1);

        for(int i = 0; i < N; i++){
            printf("%d", h[i]);
            if(i < N-1) printf(" ");
        }
        printf("\n");

        free(h);
    }
    return 0;
}
