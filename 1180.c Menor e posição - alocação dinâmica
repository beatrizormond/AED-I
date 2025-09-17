#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p, *menor;
    int *n = (int *) malloc(sizeof(int));
    int *posicao = (int *) malloc(sizeof(int));
    
    scanf("%d", n); 
    
    int *x = (int *) malloc((*n) * sizeof(int));
    
    if (x == NULL || n == NULL || posicao == NULL) {
        return 1;
    }
    
    p = x; 
    menor = x;
    *posicao = 0;

    if (*n >= 1 && *n <= 1000){
        for (p = x; p < x + *n; p++){
            scanf("%d", p);
        }
        for (p = x + 1; p < x + *n; p++){
            if (*p < *menor){
                menor = p;
                *posicao = p - x;  
            }
        }
    }
    else {
        return 1;
    }

    printf("Menor valor: %d\n", *menor);
    printf("Posicao: %d", *posicao);

    free(x);
    free(n);
    free(posicao);
    

    return 0;
}
