#include <stdlib.h>
int eh_pilha(int *entra, int *sai, int n){
    int i, j=n/2;
    int u=n/2;
    for(i=0; i<u; i++){
        if(entra[i] != sai[j-1]) return 0;
        else j--;
    }
    return 1;
}
int eh_fila(int *entra, int *sai, int n){
    int i, u=n/2;
    for(i=0; i<u; i++){
        if(entra[i] != sai[i]) return 0;
    }
    return 1;
}
int eh_fila_prioridade(int  *entra , int *sai, int n, int g){
    int i, j;
    int *ordenado = (int *) malloc((n/2)*sizeof(int));
    if(ordenado==NULL) return -1;
    for(i=0; i<n/2; i++){
        ordenado[i] = entra[i];
    }
    for(i=0; i<n/2-1; i++){
        for(j=i+1; j<n/2; j++){
            if(ordenado[i] < ordenado[j]){
                int temp = ordenado[i];
                ordenado[i] = ordenado[j];
                ordenado[j] = temp;
            }
        }
    }
    for(i=0; i<g-1; i++){
        if(sai[i]==ordenado[i]) continue;
        else return 0;
    }
    free(ordenado);
    return 1;
}
int entra_e_sai(int **celula, int n){
    int j=0;
    int *entra = (int *) malloc(n*sizeof(int));
    int *sai = (int *) malloc(n*sizeof(int));
    if(entra==NULL || sai==NULL) return -1;
    for(int i=0; i<n; i++){
        if(celula[i][0]==1) entra[i] = celula[i][1];
        else sai[j++] = celula[i][1];
    }
    if(eh_pilha(entra, sai, n) && eh_fila(entra, sai, n) && eh_fila_prioridade(entra, sai, n, j)) printf("not sure\n");
    else if(eh_pilha(entra, sai, n) && eh_fila(entra, sai, n)) printf("not sure\n");
    else if(eh_pilha(entra, sai, n) && eh_fila_prioridade(entra, sai, n, j)) printf("not sure\n");
    else if(eh_fila(entra, sai, n) && eh_fila_prioridade(entra, sai, n, j)) printf("not sure\n");
    else if(eh_pilha(entra, sai, n)) printf("stack\n");
    else if(eh_fila(entra, sai, n)) printf("queue\n");
    else if(eh_fila_prioridade(entra, sai, n, j)) printf("priority queue\n");
    else printf("impossible\n");
    free(entra);
    free(sai);
    return 0;
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
    entra_e_sai(celula, n);
    
    for(i=0; i<n; i++){
        free(celula[i]);
    }
    free(celula);
    return 0;
}
