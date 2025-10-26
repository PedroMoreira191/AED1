#include <stdio.h>
#include <string.h>

int main() {
    char exp[1001];
    
    // Lê todas as expressões até o final da entrada
    while (fgets(exp, sizeof(exp), stdin)) {
        int pilha[1000];  // vetor para simular a pilha
        int topo = -1;    // -1 indica pilha vazia
        int erro = 0;

        for (int i = 0; exp[i] != '\0'; i++) {
            if (exp[i] == '(') {
                // push
                pilha[++topo] = 1;
            } else if (exp[i] == ')') {
                if (topo == -1) {
                    erro = 1;  // parêntese fechando sem abrir
                    break;
                } else {
                    // pop
                    topo--;
                }
            }
        }

        if (erro || topo != -1) {
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }
    }

    return 0;
}
