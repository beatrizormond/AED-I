#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int conteudo;
    struct cel *seg;
} celula;

void Enfileira(int y, celula **inicio, celula **fim){
    celula *novo;
    novo = malloc(sizeof(celula));

    novo->conteudo = y;
    novo->seg = NULL;

    if (*inicio == NULL){
        *inicio = novo;
        *fim = novo;
    }
    else {
        (*fim)->seg = novo;
        *fim = novo;
    }
}

void Desenfileira(celula **inicio, celula **fim, int x){
    celula *p = *inicio;
    celula *ant;

    ant = NULL;
    while (p != NULL && p->conteudo != x){
        ant = p;
        p = p->seg;
    }
    if(p == NULL){
        return;
    }
    if(ant == NULL){
        *inicio = p->seg;
        if(*inicio == NULL){
            *fim = NULL;
        }
        else{
            ant->seg = p->seg;
            if(p == *fim){
                *fim = ant;
            }
        }
    }
    free(p);
}

int main(){
    int n, m, i, id, id2, j;
    celula *fila;
    celula *p;
    celula *inicio = NULL;
    celula *fim = NULL;

    scanf("%d", &n);
    fila = malloc (n * sizeof(celula));

    for (i = 0; i < n; i++){
        if (n >= 1 && n <= 5000){
            scanf("%d", &id);
            Enfileira(id, &inicio, &fim);
        }
    }
    
    scanf("%d", &m);
    for (j = 0; j < m; j++){
        if (m >= 1 && m <= 5000 && m < n){
            scanf("%d", &id2);
            Desenfileira(&inicio, &fim, id2);
        }     
    }
     
    int primeiro = 1;
    for (p = inicio; p != NULL; p = p->seg){
        if(primeiro){
            printf("%d", p->conteudo);
            primeiro = 0;
        }
        else{
            printf(" %d", p->conteudo);
        }
    }
        
    return 0;
}