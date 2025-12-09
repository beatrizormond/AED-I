#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    char conteudo;
    struct cel *seg;
} celula;

void Push(celula **topo, char x){
    celula *novo = malloc(sizeof(celula));

    novo->conteudo = x;
    novo->seg = *topo;
    *topo = novo;
}

char Pop(celula **topo){
    celula *lixo;
    char x;

    lixo = *topo;
    x = lixo->conteudo;
    *topo = lixo->seg;
    free(lixo);

    return x;
}

char top(celula *topo){
    if (topo != NULL){
        return topo->conteudo;
    }
    else{
        return '\0';
    }
}

int precedencia(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

int associacao(char x) {
    return x == '^';              
}

int main (){
    int n, i, j;
    char str[1000];
    char x;
    celula *pilha;
    
    scanf("%d", &n);

    for(i=0; i<n; i++){

        scanf("%s", str);

        pilha = NULL;

        for(j=0; str[j] != 0; j++){
            
            x = str[j];
            
            if(x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z' || x >= '0' && x <= '9'){
                printf("%c", x);
            }
            
            else if(x == '('){
                Push(&pilha, x);
            }
            else if(x == ')'){
                while (top(pilha) != '('){
                    printf("%c", Pop(&pilha));
                }
                Pop(&pilha);
            }
            else {
                while (pilha != NULL && top(pilha) != '(' && (precedencia(top(pilha)) > precedencia(x) || (precedencia(top(pilha)) == precedencia(x) && associacao(x) == 0))){
                    printf("%c", Pop(&pilha));
                }
                Push(&pilha, x);
            }
        }
        while (pilha != NULL){
            printf("%c", Pop(&pilha));
        }
        printf("\n");
    }

    return 0;
}