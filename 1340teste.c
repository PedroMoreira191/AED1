#include <stdlib.h>
int eh_pilha(int **celula, int n){
    int i, j=n;
    int u=n/2;
    for(i=0; i<u; i++){
        if(celula[i][1]!=celula[j-1][1]) return 0;
        else j--;
    }
    return 1;
}
int eh_fila(int **celula, int n){
    int i, j=n/2;
    int u=n/2;
    for(i=0; i<u; i++){
        if(celula[i][1]!=celula[j][1]) return 0;
        else j++;
    }
    return 1;
}
int eh_fila_prioridade(){
}
int main(){
    int i, j, n;
    scanf("%d", &n);
    int **celula = (int **) malloc(n*sizeof(int*));
    if(celula==NULL) return 1;
    for(i=0; i<n; i++){
        celula[i] = (int *) malloc(2*sizeof(int));
        if(celula[i]==NULL) return 2;
    }
    for(i=0; i<n; i++){
        for(j=0; j<2; j++){
            scanf("%d", &celula[i][j]);
        }
    }
    printf("%d", eh_pilha(celula, n));
    printf("%d", eh_fila(celula, n));
    
    for(i=0; i<n; i++){
        free(celula[i]);
    }
    free(celula);
}
