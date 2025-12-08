#include <stdio.h>

int main(){
    int N;

    while(scanf("%d", &N), N != 0){
        while(1){
            int desejado[1000];
            scanf("%d", &desejado[0]);

            if(desejado[0] == 0){     // fim do bloco
                printf("\n");
                break;
            }

            for(int i=1; i<N; i++) 
                scanf("%d", &desejado[i]);

            int stack[1000], topo = -1;
            int proximo = 1;          // próximo vagão que chega
            int ok = 1;

            for(int i = 0; i < N; i++){
                while(proximo <= N && (topo == -1 || stack[topo] != desejado[i])){
                    stack[++topo] = proximo++;  // empilha (entra na estação)
                }

                if(stack[topo] == desejado[i])  // se o topo é o que eu quero
                    topo--;                     // desempilha (vai p/ B)
                else{
                    ok = 0;                     // impossível
                    break;
                }
            }

            if(ok) printf("Yes\n");
            else   printf("No\n");
        }
    }
    return 0;
}
