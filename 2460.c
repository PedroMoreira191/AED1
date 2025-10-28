#include <stdlib.h>
#include <stdio.h>

typedef struct cel{
    int valor;
    struct cel* seg;
} celula;

celula *c = NULL, *f = NULL;


void coloca(celula **c, celula **f, int x){
    celula *p = (celula*) malloc(sizeof(celula));
    
    p->valor = x;
    p->seg = NULL;
    if(*f == NULL) *c = *f = p;
    else {
        (*f)->seg = p;
        *f = p;
    }
    

}

int tira(celula **c, celula **f, int x){
    celula *p, *ant = NULL;
    p = *c;
    while(p != NULL && p->valor != x){
        ant = p;
        p = p->seg;
    }
    
    if(p == NULL) return 0;
    
    if(ant == NULL){
        *c = p->seg;
        if(*c == NULL) *f = NULL;

    }
    else {
        ant->seg = p->seg;
        if(p == *f) *f = ant;
    }
    free(p);

    return 0;
}

void mostra(celula *c){
    while(c != NULL){
        printf("%d", c->valor);
        if (c->seg != NULL) printf(" ");
        c = c->seg;
    }
    printf("\n");
}


int main () {
    int n, m;

    int h;

    scanf("%d", &n);
    for(int i = 1; i<=n; i++){
        scanf("%d", &h);
        coloca(&c, &f, h);
    }

    int k;

    scanf("%d", &m);
    for(int j = 0; j<m; j++){
        scanf("%d", &k);
        tira(&c, &f, k);
    }

    mostra(c);
}   
