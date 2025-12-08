#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int n){
    int i, j, min, aux;

    for(i = 0; i < n-1; i++){
        min = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[min])
                min = j;
        }
        if(min != i){
            aux = v[i];
            v[i] = v[min];
            v[min] = aux;
        }
    }
}

int main(){
    int NC, N;

    scanf("%d", &NC);

    while(NC--){
        scanf("%d", &N);

        int *h = (int*) malloc(N * sizeof(int));
        if(!h) return 0;

        for(int i = 0; i < N; i++)
            scanf("%d", &h[i]);

        selectionSort(h, N);

        for(int i = 0; i < N; i++){
            printf("%d", h[i]);
            if(i < N-1) printf(" ");
        }
        printf("\n");

        free(h);
    }

    return 0;
}
