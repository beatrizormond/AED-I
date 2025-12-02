#include <stdio.h>
#include <stdlib.h>

int Quick (int inicio, int fim, int fila[]){
    int pivo, j, k, t;
    pivo = fila[fim];
    j = inicio;

    for (k = inicio; k < fim; k++){
        if (fila[k] <= pivo){
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }

    }
    fila[fim] = fila[j];
    fila[j] = pivo;
    return j;
}

int QuickSort (int inicio, int fim, int fila[]){
    int j;
    int 
    if (inicio > fim){
        j = Quick(inicio, fim, fila);
        QuickSort(inicio, j-1, fila);
        QuickSort(j+1, fim, fila);
    }
    }
}
typedef struct cel{
    int conteudo;
    struct cel *seg;
} celula

void Enfileira(int nota, celula *fila, celula *incio, celula *fim){
    celula *novo;
    novo = malloc(sizeof(celula));

    novo->conteudo = nota;
    novo->seg = NULL;

    if (inicio == fim == NULL){
        inicio = novo;
        fim = novo;
    }
    else {
        fil->seg = novo;
        fim = novo;
    }
}


int main(){
int n, i, m, nota,;
celula *fila = malloc(sizeof(celula));
celula *inicio = NULL;
celula *fim = NULL;

scanf("%d", &n);

for (i=0; i<n; i++){
    scanf("%d", &m);

    for (j=0; j<m; j++){
        scanf("%d", &nota);
        fila[j] = nota;
    }
    Quicksort(0, m-1, fila);    
    }

    for(k=0; k<m; k++){
        printf("%d ", fila[k]);
}

    return 0;
}