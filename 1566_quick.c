#include <stdio.h>
#include <stdlib.h>

int separa(int p, int r, int v[]){
    int c = v[r];
    int j = p;

    for(int k = p; k < r; k++){
        if(v[k] <= c){
            int t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }

    int t = v[j];
    v[j] = v[r];
    v[r] = t;

    return j;
}

void quicksort(int p, int r, int v[]){
    if(p < r){
        int j = separa(p, r, v);
        quicksort(p, j - 1, v);
        quicksort(j + 1, r, v);
    }
}

int main (){
    int NC, N;

    scanf("%d", &NC);
    while(NC--){
        
        scanf("%d", &N);
        int *h = malloc(N * sizeof(int));

        for(int j = 0; j < N; j++){
            scanf("%d", &h[j]);
        }

        quicksort(0, N - 1, h);

        for(int j = 0; j < N; j++){
            if(j) printf(" ");
            printf("%d", h[j]);
        }
        printf("\n");

        free(h);
    }
}
