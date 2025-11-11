#include <stdio.h>
#include <stdlib.h>

struct cel {
    int conteudo;
    int chave;
    struct cel *dir;
    struct cel *esq;
};

typedef struct cel nodo;
typedef nodo *arvore;

void Insere(arvore *r, nodo *novo){
    nodo *f, *p;
    if (*r == NULL){
        *r = novo;
        (*r)->dir = NULL;
        (*r)->esq = NULL;
        return;
    }
    
    f = *r;
    
    while (f!= NULL){
        p = f;
        if (f->chave > novo->chave){
            f = f->esq;
        }
        else{
            f = f->dir;
        }
    }
    if (p->chave > novo->chave){
        p->esq = novo;
    }
    else {
        p->dir = novo;
    }
}

void In(arvore r, int n){
    static char buffer[10*3000000];
    int pos = 0;
    buffer[0] = '\0';

    nodo **p = malloc(n * sizeof(nodo*));
    nodo *x;
    int t = 0;
    x = r;
    while (x != NULL || t > 0){
        if(x != NULL){
            p[t++] = x;
            x = x->esq;
        }
        else {
            x = p[--t];
            pos += sprintf(buffer + pos, " %d", x->chave);
            x = x->dir;
        }
    }
    if (pos > 0){
        fwrite(buffer + 1, sizeof(char), pos - 1, stdout);
    }
    printf("\n");
    free(p);
}

int main (){
    int NC, n, h, i, j;
    arvore r = NULL;

    scanf("%d", &NC);

    if(NC < 100){
        for(i=0; i<NC; i++){
            r = NULL;
            scanf("%d", &n);
            if (n > 1 && n <=3000000){
                nodo *memoria = malloc(n * sizeof(nodo));
                for (j=0; j<n; j++){
                    scanf("%d", &h);
                    if(h>= 10 && h <= 230){
                        nodo *novo = &memoria[j];
                        novo->chave = h;
                        novo->esq = NULL;
                        novo->dir = NULL;
                        Insere(&r, novo);
                    }
                }
            In(r, n);
            free(memoria);
            }
        }
    }

    return 0;
}
