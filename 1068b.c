#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel* seg;
} celula;

void push(celula **topo, int x) {
    celula *p = (celula*) malloc(sizeof(celula));
    p->valor = x;
    p->seg = *topo;
    *topo = p;
}

int pop(celula **topo) {
    if (*topo == NULL) return -1;
    celula *p = *topo;
    int x = p->valor;
    *topo = p->seg;
    free(p);
    return x;
}

void libera(celula **topo) {
    celula *p;
    while (*topo != NULL) {
        p = *topo;
        *topo = p->seg;
        free(p);
    }
}

int main() {
    char exp[1001];
    
    // laco para ler todas chamadas
    while (fgets(exp, sizeof(exp), stdin)) {
        celula *topo = NULL;
        int erro = 0;
        
        for (int i = 0; exp[i] != '\0'; i++) {
            if (exp[i] == '(') {
                push(&topo, 1);
            } else if (exp[i] == ')') {
                if (pop(&topo) == -1) {
                    erro = 1;
                    break;
                }
            }
        }

        if (erro || topo != NULL) {
            printf("incorrect\n");
        } else {
            printf("correct\n");
        }

        libera(&topo);
    }

    return 0;
}
