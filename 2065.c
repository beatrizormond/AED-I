#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    long long tempoAtual;
    long long tempoItem;
    int id;
    struct cel *seg;
} celula;

void Inserir (celula *lista, celula *novo){
    celula *p = lista;

    while (p->seg != NULL){
        if (p->seg->tempoAtual > novo->tempoAtual){
            break;
        }
        if(p->seg->tempoAtual == novo->tempoAtual && p->seg->id > novo->id){
            break;
        }
        p = p->seg;
    }
    novo->seg = p->seg;
    p->seg = novo;
}

celula* Remover (celula *lista){ //função retorna um ponteiro para celula
    celula *lixo;
    
    if(lista->seg == NULL){
        return NULL;
    }

    lixo = lista->seg;
    lista->seg = lixo->seg;

    return lixo;
}

int main (){
    int n, m, i;
    long long c;
    long long resposta = 0;
    celula *lista = malloc(sizeof(celula));
    lista->seg = NULL;

    scanf("%d %d", &n, &m);

    for(i=0; i<n; i++){

        celula *novo = malloc(sizeof(celula));

        scanf("%lld", &novo->tempoItem);

        novo->tempoAtual = 0;
        novo->id = i;
        novo->seg = NULL;

        Inserir(lista, novo);
    }

    for(i=0; i<m; i++){

        scanf("%lld", &c);

        celula *caixa = Remover(lista);

        caixa->tempoAtual += caixa->tempoItem * c;

        if(caixa->tempoAtual > resposta){
            resposta = caixa->tempoAtual;
        }

        Inserir(lista, caixa);
    }

    printf("%lld\n", resposta);

    return 0;
}
