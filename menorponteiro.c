#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, n, posicao;
    int *p, *x;

    scanf("%d", &n);

    x = (int *) malloc(n * sizeof(int));
    
    p = &x[0];
    int menor = *p;

    if (n >= 1 && n <= 1000){
        for (i=0; i<n; i++){
            scanf("%d", &(x[i]));
        }
        for (i=1; i<n; i++){
            p = &(x[i]);
            if (*p < menor){
                menor = *p;
                posicao = (&x[i] - x); 
            }
        }
    }
    else {
        return 1;
    }

    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d", posicao);

    free(x);

    return 0;
}