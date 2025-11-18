#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char valor;
    struct no* esq;
    struct no* dir;    
} No;

typedef struct {
    No *raiz;
} Arv;

void esquerda(No *no, char valor){
    if(no->esq == NULL){
        No *novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        no->esq = novo;
    } else {
        if(valor < no->esq->valor)
            esquerda(no->esq, valor);
        else
            direita(no->esq, valor);
    }
}

void direita(No *no, char valor){
    if(no->dir == NULL){
        No *novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        no->dir = novo;
    } else {
        if(valor >= no->dir->valor)
            direita(no->dir, valor);
        else
            esquerda(no->dir, valor);
    }
}

void insere(Arv *arv, char valor){
    if(arv->raiz == NULL){
        No *novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        arv->raiz = novo;
    } else {
        if(valor < arv->raiz->valor)
            esquerda(arv->raiz, valor);
        else
            direita(arv->raiz, valor);
    }
}

int busca(No *raiz, char letra){
    if(raiz == NULL) return 0;
    if(raiz->valor == letra) return 1;
    return busca(raiz->esq, letra) || busca(raiz->dir, letra);
}

void inAux(No *raiz, int *primeiro){
    if(raiz != NULL){
        inAux(raiz->esq, primeiro);
        if(!(*primeiro)) printf(" ");
        printf("%c", raiz->valor);
        *primeiro = 0;
        inAux(raiz->dir, primeiro);
    }
}

void in(No *raiz){
    int primeiro = 1;
    inAux(raiz, &primeiro);
}

void preAux(No *raiz, int *primeiro){
    if(raiz != NULL){
        if(!(*primeiro)) printf(" ");
        printf("%c", raiz->valor);
        *primeiro = 0;
        preAux(raiz->esq, primeiro);
        preAux(raiz->dir, primeiro);
    }
}

void pre(No *raiz){
    int primeiro = 1;
    preAux(raiz, &primeiro);
}

void posAux(No *raiz, int *primeiro){
    if(raiz != NULL){
        posAux(raiz->esq, primeiro);
        posAux(raiz->dir, primeiro);
        if(!(*primeiro)) printf(" ");
        printf("%c", raiz->valor);
        *primeiro = 0;
    }
}

void pos(No *raiz){
    int primeiro = 1;
    posAux(raiz, &primeiro);
}

void libera(No *raiz){
    if(raiz == NULL) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main(){
    Arv T;
    T.raiz = NULL;
    char s[20], letra;

    while(scanf("%s", s) != EOF){

        if(strcmp(s, "I") == 0){
            scanf(" %c", &letra);
            insere(&T, letra);
        }

        else if(strcmp(s, "P") == 0){
            scanf(" %c", &letra);
            if(busca(T.raiz, letra))
                printf("%c existe\n", letra);
            else
                printf("%c nao existe\n", letra);
        }

        else if(strcmp(s, "INFIXA") == 0){
            in(T.raiz);
            printf("\n");
        }

        else if(strcmp(s, "PREFIXA") == 0){
            pre(T.raiz);
            printf("\n");
        }

        else if(strcmp(s, "POSFIXA") == 0){
            pos(T.raiz);
            printf("\n");
        }
    }

    libera(T.raiz);
    return 0;
}
