#include "stdio.h"

int main (){
    int N=0, x[10000];
    int posicao = 0, menor, *p;
    
    p = x;
    
    while(N<1 || N>10000){
        scanf("%d", &N);
    }
    
    for(int i=0; i<N; i++){
        scanf("%d", &*p);
        p++;
    }
    
    p = x;
    menor = *p;
    
    for(int i=0; i<N; i++){
        
        if(*p<menor){
          menor = *p;
          posicao = i;
        } 
        p++;
    }
    printf("Menor valor: %d\nPosicao: %d\n", menor, posicao);
}
