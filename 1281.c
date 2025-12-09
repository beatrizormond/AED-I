#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char item[100];
    float preco;
    struct cel *seg;
} celula;

void Inserir(celula *lista, char item[], float preco){
    celula *novo = malloc(sizeof(celula));

    strcpy(novo->item, item);
    novo->preco = preco;
    novo->seg = lista->seg;
    lista->seg = novo;    
}

float Busca(celula *lista, char item[]){
    celula *p;
    p = lista->seg;

    while(p != NULL){
        if(strcmp(p->item, item) == 0){
            return p->preco;
        }
        p = p->seg;
    }
    return 0.0;
}

void Limpa(celula *lista){
    celula *p, *lixo;

    p = lista->seg;

    while(p != NULL){
        lixo = p;
        p = p->seg;
        free(lixo);
    }

    lista->seg = NULL;
}

int main (){
    int n, m, p, i, j, qtd;
    float preco, total;
    char item[100];

    celula *lista = malloc(sizeof(celula));
    lista->seg = NULL;

    scanf("%d", &n);

    for (i=0; i<n; i++){
        Limpa(lista);
        total = 0;

        scanf("%d", &m);

        for (j=0; j<m; j++){
            scanf("%s %f", item, &preco);
            Inserir(lista, item, preco);
        }

        scanf("%d", &p);

        for (j=0; j<p; j++){
            scanf("%s %d", item, &qtd);

            preco = Busca(lista, item);
            total += preco * qtd;
        }

        printf("R$ %.2f\n", total);
    }
    free(lista);

    return 0;
}