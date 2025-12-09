#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} celula;

void Push(celula **topo, int x){
    celula *novo = malloc(sizeof(celula));

    novo->conteudo = x;
    novo->seg = *topo;
    *topo = novo;
}

int Pop(celula **topo){
    celula *lixo;
    int x;

    lixo = *topo;
    x = lixo->conteudo;
    *topo = lixo->seg;
    free(lixo);

    return x;
}

int top(celula *topo){
    if (topo != NULL){
        return topo->conteudo;
    }
    else{
        return -1;
    }
}

void Limpa(celula **topo){
    while(*topo != NULL){
        Pop(topo);
    }
}

int Testa(int seq[], int n){
    celula *pilha = NULL;
    int seguinte = 1;
    int i = 0;

    while (i<n){
        if(top(pilha) == seq[i]){
            Pop(&pilha);
            i++;
        }
        else if (seguinte <= n){
            Push(&pilha, seguinte);
            seguinte++;
        }
        else{
            Limpa(&pilha);
            return 0;
        }
    }
    
    Limpa(&pilha);
    return 1;
}

int main (){
    int n, num, i;
    int seq[1000];
    
    while (1){
        scanf("%d", &n);
        if(n == 0){
            return 0;
        }
        
        while(1){
            scanf("%d", &seq[0]);

            if(seq[0] == 0){
                printf("\n");
                break;
            }
            
            for (i=1; i<n; i++){
                scanf("%d", &seq[i]);
            }
            if(Testa(seq, n)){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        
        }
    }

    return 0;
}