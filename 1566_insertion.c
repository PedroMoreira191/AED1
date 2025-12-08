#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *v, int n){
    int i, j, aux;
    for(i = 1; i < n; i++){
        aux = v[i];
        j = i - 1;
        while(j >= 0 && v[j] > aux){
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = aux;
    }
}

int main(){
    int NC, N;

    scanf("%d", &NC);

    while(NC--){
        scanf("%d", &N);

        int *h = (int*) malloc(N * sizeof(int));
        if(h == NULL) return 0;

        for(int i = 0; i < N; i++)
            scanf("%d", &h[i]);

        insertionSort(h, N);

        for(int i = 0; i < N; i++){
            printf("%d", h[i]);
            if(i < N-1) printf(" ");
        }
        printf("\n");

        free(h);
    }

    return 0;
}
