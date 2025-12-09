#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void Inserir(celula **lista, int x) {
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->valor = x;
    novo->seg = *lista;
    *lista = novo;
}

void Troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int Quick(int inicio, int fim, int v[]) {
    int i, j;
    int pivo = v[fim];
    
    i = inicio - 1;
    
    for (j = inicio; j < fim; j++) {
        if (v[j] <= pivo) {
            i++;
            Troca(&v[i], &v[j]);
        }
    }
    Troca(&v[i+1], &v[fim]);
    return i+1;
}

void QuickSort (int inicio, int fim, int v[]){
    int j;
    if (inicio < fim){
        j = Quick(inicio, fim, v);
        QuickSort(inicio, j-1, v);
        QuickSort(j+1, fim, v);
    }
}

int main() {
    int n, i, atual, contador;
    int *valores;
    scanf("%d", &n);

    celula *lista = NULL;

    for (i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        Inserir(&lista, x);
    }

    valores = (int*) malloc(n * sizeof(int));
    celula *p = lista;
    for (int i = 0; i < n; i++) {
        valores[i] = p->valor;
        p = p->seg;
    }

    QuickSort(0, n-1, valores);

    atual = valores[0];
    contador = 1;

    for (i = 1; i < n; i++) {
        if (valores[i] == atual) {
            contador++;
        } else {
            printf("%d aparece %d vez(es)\n", atual, contador);
            atual = valores[i];
            contador = 1;
        }
    }
    
    printf("%d aparece %d vez(es)\n", atual, contador);

    
    while (lista != NULL) {
        celula *aux = lista;
        lista = lista->seg;
        free(aux);
    }
    free(valores);

    return 0;
}
