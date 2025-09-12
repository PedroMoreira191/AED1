#include <stdio.h>
#include <stdlib.h>

int main (){
    int *x;
    int tamanho=0, posicao=0, menor=0;
    
    do{
        scanf("%d", &tamanho);
    }
    while(tamanho<0 || tamanho>10000);
    
    x = (int *) malloc(tamanho * sizeof(int));
    if(x==NULL) return 1;
    
    for(int i=0; i<tamanho; i++){
        scanf("%d", &x[i]);
    }
    
    menor = x[0];
    
    for(int i=0; i<tamanho; i++){
        if(x[i]<menor){
        menor = x[i];
        posicao = i;
        }
    }
   
    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
    
    free(x);
    
    return 0;
}
