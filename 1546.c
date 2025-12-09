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
    int n, k, i;
    //celula feedbacks = malloc(sizeof(celula));

    scanf("%d", &n);

    for (i=0; i<n; i++){
        scanf("%d", &k);

        for (j=0; j<k; j++){
            scanf("%d", &x);

            if(x == 1){
                printf("Rolien\n");
            }
            if(x == 2){
                printf("Naej\n");
            }
            if(x ==3){
                printf("Elehcim");
            }
            if(x == 4){
                printf("Odranoel");
            }
        }

    }



    return 0;
}