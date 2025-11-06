#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no* esq;
    struct no* dir;    
} No;


typedef struct {
    No *raiz;
}Arv;

void esquerda(No *no,int valor){
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


void direita(No *no, int valor){
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

void insere(Arv *arv, int valor){
    if(arv->raiz == NULL){
        No *novo = (No*) malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        arv->raiz = novo;
    }
    else {
        if (valor < arv->raiz->valor){
            esquerda(arv->raiz, valor);
        }
        else {
            direita(arv->raiz, valor);
        }
    }
}

void imprime(No *raiz){
    if(raiz != NULL){
        imprime(raiz->esq);
        printf("%d ", raiz->valor);
        imprime(raiz->dir);
    }
}

void libera(No *raiz){
    if(raiz == NULL)return;
    libera(raiz->esq);
    libera(raiz->dir);
    free(raiz);
}

int main (){
    Arv T;
    T.raiz = NULL;
    int n;
    int i;

    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        Arv T;
        T.raiz = NULL;
       
        int h;
        scanf("%d", &h);
        
        for(int j = 0; j<h; j++){
            int num;
            scanf("%d", &num);
            insere(&T, num);
        }

        imprime(T.raiz);    
        printf("\b\n");
        libera(T.raiz);
    }
    return 0;
}
