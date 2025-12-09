#include <stdio.h>
#include <stdlib.h>
#define MAX 10010

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} fila;

void Push(fila *f, int x) {
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->valor = x;
    novo->seg = NULL;
    if (f->fim) f->fim->seg = novo;
    else f->inicio = novo;
    f->fim = novo;
}

int Pop(fila *f) {
    int val;
    if (f->inicio == NULL){
        return -1;
    }
    celula *tmp = f->inicio;
    val = tmp->valor;
    f->inicio = tmp->seg;
    if (f->inicio == NULL){
        f->fim = NULL;
    }
    free(tmp);
    return val;
}

int Inverter(int x) {
    int r = 0;
    while (x > 0) {
        r = r * 10 + (x % 10);
        x /= 10;
    }
    return r;
}

int bfs(int a, int b) {
    int dist[MAX];
    int i;

    for (i = 0; i < MAX; i++){
        dist[i] = -1;
    }

    fila f;
    f.inicio = f.fim = NULL;

    dist[a] = 0;
    Push(&f, a);

    while (f.inicio != NULL) {
        int u, v;
        u = Pop(&f);
        if(u == -1) break;
        if (u == b) return dist[u];

        if (u + 1 < MAX && dist[u + 1] == -1) {
            dist[u + 1] = dist[u] + 1;
            Push(&f, u + 1);
        }

        v = Inverter(u);
        
        if (v < MAX && dist[v] == -1) {
            dist[v] = dist[u] + 1;
            Push(&f, v);
        }
    }
    return -1; 
}

int main() {
    int t, i, a, b;
    
    scanf("%d", &t);
    
    for(i=0; i<t; i++){
        scanf("%d %d", &a, &b);
        printf("%d\n", bfs(a, b));
    }
    
    return 0;
}
