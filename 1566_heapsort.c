#include <stdio.h>
#include <stdlib.h>

void heapify(int *v, int n, int i){
    int maior = i;           // raiz
    int esq = 2*i + 1;       // filho esquerdo
    int dir = 2*i + 2;       // filho direito

    // se o filho da esquerda é maior que a raiz
    if(esq < n && v[esq] > v[maior])
        maior = esq;

    // se o filho da direita é maior que o maior atual
    if(dir < n && v[dir] > v[maior])
        maior = dir;

    // se a raiz não é o maior, troca
    if(maior != i){
        int temp = v[i];
        v[i] = v[maior];
        v[maior] = temp;

        heapify(v, n, maior);   // reorganiza o heap
    }
}

void heapSort(int *v, int n){
    // monta o heap (max-heap)
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(v, n, i);

    // extrai elementos e coloca no final do vetor
    for(int i = n-1; i > 0; i--){
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        heapify(v, i, 0);
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

        heapSort(h, N);

        for(int i = 0; i < N; i++){
            printf("%d", h[i]);
            if(i < N-1) printf(" ");
        }
        printf("\n");

        free(h);
    }
    return 0;
}
