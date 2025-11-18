#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int v;
    struct no *esq, *dir;
} No;

No* criaNo(int v){
    No *n = malloc(sizeof(No));
    n->v = v;
    n->esq = n->dir = NULL;
    return n;
}

No* insere(No *raiz, int v){
    if(raiz == NULL) return criaNo(v);

    if(v < raiz->v) raiz->esq = insere(raiz->esq, v);
    else raiz->dir = insere(raiz->dir, v);

    return raiz;
}

void bfs(No *raiz){
    if(raiz == NULL) return;

    No *fila[600];
    int ini = 0, fim = 0;

    fila[fim++] = raiz;

    int primeiro = 1;

    while(ini < fim){
        No *atual = fila[ini++];

        if(!primeiro) printf(" ");
        printf("%d", atual->v);
        primeiro = 0;

        if(atual->esq) fila[fim++] = atual->esq;
        if(atual->dir) fila[fim++] = atual->dir;
    }
}

void libera(No *raiz){
    if(raiz == NULL) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main(){
    int C, N, x;
    scanf("%d", &C);

    for(int caso = 1; caso <= C; caso++){
        scanf("%d", &N);

        No *raiz = NULL;

        for(int i = 0; i < N; i++){
            scanf("%d", &x);
            raiz = insere(raiz, x);
        }

        printf("Case %d:\n", caso);
        bfs(raiz);
        printf("\n\n");

        libera(raiz);
    }

    return 0;
}
