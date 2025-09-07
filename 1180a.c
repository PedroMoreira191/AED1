#include "stdio.h"

int main (){
    int N=0, x[10000];
    int posicao, menor;
    
    while(N<1 || N>10000){
        scanf("%d", &N);
    }
    
    for(int i=0; i<N; i++){
        scanf("%d", &x[i]);
    }
    
    menor = x[0];
    
    for(int i=0; i<N; i++){
        
        if(x[i]<menor){
          menor = x[i];
          posicao = i;
        }  
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
}
