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

void esquerda(No *no,char valor){
    if(no->esq == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->esq = novo;
    }
    else{
        if(valor < no->esq->valor){
            esquerda(no->esq, valor);
        }
        else{
            direita(no->esq, valor);
        }
    }
}

void direita(No *no, char valor){
    if(no->dir == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        no->dir = novo;
    }
    else{
        if(valor >= no->dir->valor){
            direita(no->dir, valor);
        }
        else{
            esquerda(no->dir, valor);
        }
    }
}

void insere(Arv *arv, char valor){
    if(arv->raiz == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        arv->raiz = novo;
    }
    else {
        if(valor < arv->raiz->valor)
            esquerda(arv->raiz, valor);
        else
            direita(arv->raiz, valor);
    }
}

int busca(No *raiz, char letra){
    if(raiz == NULL) return 0;

    if(raiz->valor == letra)
        return 1;

    return busca(raiz->esq, letra) || busca(raiz->dir, letra);
}

void in(No *raiz){
    if(raiz != NULL){
        in(raiz->esq);
        printf("%c ", raiz->valor);
        in(raiz->dir);
    }
}

void pre(No *raiz){
    if(raiz != NULL){
        printf("%c ", raiz->valor);
        pre(raiz->esq);
        pre(raiz->dir);
    }
}

void pos(No *raiz){
    if(raiz != NULL){
        pos(raiz->esq);
        pos(raiz->dir);
        printf("%c ", raiz->valor);
    }
}

void libera(No *raiz){
    if(raiz == NULL) return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main (){
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
