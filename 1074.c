#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} celula;

void Inserir (int y, celula *lista){
    celula *nova = malloc(sizeof(celula));
    
    nova->conteudo = y;
    nova->seg = lista->seg;
    lista->seg = nova;
}

int Remover (celula *lista){
    celula *lixo;
    int x;

    if(lista->seg == NULL){
        return 0;
    }

    lixo = lista->seg;
    x = lixo->conteudo;
    lista->seg = lixo->seg;
    free(lixo);
    
    return x;
}


int main (){
    int n, x, i;
    celula *lista = malloc(sizeof(celula));
    lista->seg = NULL;

    scanf("%d", &n);

    for (i=0; i<n; i++){
        scanf("%d", &x);
        
        Inserir(x, lista);
        
        x = Remover(lista);
        
        if(x > 0 && x % 2 == 0){
            printf("EVEN POSITIVE\n", x);
        }
        if(x < 0 && x % 2 == 0){
            printf("EVEN NEGATIVE\n", x);
        }
        if(x > 0 && x % 2 != 0){
            printf("ODD POSITIVE\n", x);
        }
        if(x < 0 && x % 2 != 0){
            printf("ODD NEGATIVE\n", x);
        }
        if(x == 0){
            printf("NULL\n", x);
        }
    }

    return 0;
}