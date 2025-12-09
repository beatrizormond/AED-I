#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int primeiro = 1;

void Pre(arvore r){
    if(r != NULL){
        if (!primeiro) printf(" ");
        printf("%c", r->chave);
        primeiro = 0;
        Pre(r->esq);
        Pre(r->dir);
    }
}

void In(arvore r){
    if(r != NULL){
        In(r->esq);
        if (!primeiro) printf(" ");
        printf("%c", r->chave);
        primeiro = 0;
        In(r->dir);
    }
}

void Pos(arvore r){
    if(r!= NULL){
        Pos(r->esq);
        Pos(r->dir);
        if (!primeiro) printf(" ");
        printf("%c", r->chave);
        primeiro = 0;
    }
}

int busca(arvore r, int x) {
    while (r) {
        if (x < r->chave) {
            r = r->esq;
        }
        else if (x > r->chave) {
            r = r->dir;
        }
        else return 1;
    }
    return 0;
}


int main (){
    char entrada[30];
    char termo;
    arvore r = NULL;

    while(scanf("%s", entrada) != EOF){
        

        if(strcmp(entrada, "I") == 0){
            scanf(" %c", &termo);
            nodo *novo = malloc(sizeof(nodo));
            novo->chave = termo;
            novo->dir = NULL;
            novo->esq = NULL;
            Insere(&r, novo);
        }

        else if (strcmp(entrada,"P") == 0){
            scanf(" %c", &termo);
            if(busca(r, termo) == 0){
                printf("%c nao existe\n", termo);
            }
            else {
                printf("%c existe\n", termo);
           }
        }
        
        else if (strcmp(entrada, "PREFIXA") == 0){
            primeiro = 1;
            Pre(r);
            printf("\n");
        }
        else if (strcmp(entrada, "INFIXA") == 0){
            primeiro = 1;
            In(r);
            printf("\n");
        }
        else if (strcmp(entrada, "POSFIXA") == 0){
            primeiro = 1;
            Pos(r);
            printf("\n");
        }
    
    }
    return 0;
}