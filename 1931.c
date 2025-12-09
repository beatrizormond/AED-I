#include <stdio.h>
#include <stdlib.h>

#define MAX 10050
#define INFINITO 1000000000

typedef struct cel {
    int v;
    int w;
    struct cel *seg;
} celula;

celula *adj[MAX];
int dist[MAX][2];

typedef struct {
    int d;      
    int v;      
    int p;      
} item;

item heap[2 * MAX];
int heap_size;

void heap_troca(int i, int j) {
    item aux = heap[i];
    heap[i] = heap[j];
    heap[j] = aux;
}

void heap_push(int d, int v, int p) {
    int i = heap_size++;
    heap[i].d = d;
    heap[i].v = v;
    heap[i].p = p;

    while (i > 0) {
        int pai = (i - 1) / 2;
        if (heap[pai].d <= heap[i].d) break;
        heap_troca(i, pai);
        i = pai;
    }
}

item heap_pop() {
    item ret = heap[0];
    heap_size--;

    heap[0] = heap[heap_size];

    int i = 0;

    while (1) {
        int e = 2 * i + 1;
        int d = 2 * i + 2;
        int menor = i;

        if (e < heap_size && heap[e].d < heap[menor].d)
            menor = e;
        if (d < heap_size && heap[d].d < heap[menor].d)
            menor = d;

        if (menor == i) break;
        heap_troca(i, menor);
        i = menor;
    }

    return ret;
}


int dijkstra(int c) {
    int i, d, u, p, v, w, np;

    for (i = 1; i <= c; i++) {
        dist[i][0] = dist[i][1] = INFINITO;
    }

    heap_size = 0;

    dist[1][0] = 0;
    heap_push(0, 1, 0);

    while (heap_size > 0) {
        item x = heap_pop();
        d = x.d;
        u = x.v;
        p = x.p;

        if (d > dist[u][p]) continue;
        if (u == c && p == 0) break;

        celula *ptr = adj[u];
        while (ptr != NULL) {
            v = ptr->v;
            w = ptr->w;
            np = p ^ 1;

            if (dist[v][np] > dist[u][p] + w) {
                dist[v][np] = dist[u][p] + w;
                heap_push(dist[v][np], v, np);
            }

            ptr = ptr->seg;
        }
    }

    if (dist[c][0] == INFINITO) {
        return -1;
    } else {
        return dist[c][0];
    }
}

int main() {
    int c, V;
    int resposta;

    while (scanf("%d %d", &c, &V) == 2) {
        if (c == 0 && V == 0) break;

        for (int i = 1; i <= c; i++)
            adj[i] = NULL;

        for (int i = 0; i < V; i++) {
            int a, b, g;
            scanf("%d %d %d", &a, &b, &g);

            celula *n1 = malloc(sizeof(celula));
            n1->v = b; n1->w = g; n1->seg = adj[a];
            adj[a] = n1;

            celula *n2 = malloc(sizeof(celula));
            n2->v = a; n2->w = g; n2->seg = adj[b];
            adj[b] = n2;
        }

        resposta = dijkstra(c);
        printf("%d\n", resposta);
    }

    return 0;
}

