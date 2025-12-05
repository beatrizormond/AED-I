#include <stdio.h>
#include <stdlib.h>


int QuickCresc (int inicio, int fim, int v[]){
    int pivo, j, k, t;
    pivo = v[fim];
    j = inicio;

    for (k = inicio; k < fim; k++){
        if (v[k] <= pivo){
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
        v[fim] = v[j];
        v[j] = pivo;
        return j;
    
}

int QuickDec (int inicio, int fim, int v[]){
    int pivo, j, k, t;
    pivo = v[fim];
    j = inicio;

    for (k = inicio; k < fim; k++){
        if (v[k] >= pivo){
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
        v[fim] = v[j];
        v[j] = pivo;
        return j;
    
}


void OrdenaPar (int inicio, int fim, int v[]){
    int j;
    if (inicio < fim){
        j = QuickCresc(inicio, fim, v);
        OrdenaPar(inicio, j-1, v);
        OrdenaPar(j+1, fim, v);
    }
}

void OrdenaImpar (int inicio, int fim, int v[]){
    int j;
    if (inicio < fim){
        j = QuickDec(inicio, fim, v);
        OrdenaImpar(inicio, j-1, v);
        OrdenaImpar(j+1, fim, v);
    }
}

int main (){
    int n, x, i;
    int *impar, *par;
    int ip = 0, ii = 0;

    scanf("%d", &n);

    impar = malloc(n * sizeof(int));
    par = malloc(n * sizeof(int));

    for (i=0; i<n; i++){
        scanf("%d", &x);
        if(x % 2 == 0){
            par[ip++] = x;
        }
        else {
            impar[ii++] = x;
        }
    }

    if (ip > 0){
        OrdenaPar(0, ip - 1, par);
    }
    if (ii > 0){
        OrdenaImpar(0, ii - 1, impar);
    }

    for (i = 0; i<ip; i++){
        printf("%d\n", par[i]);
    }
    for (i = 0; i < ii; i++){
        printf("%d\n", impar[i]);
    }

    return 0;
}