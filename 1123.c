#include <stdio.h>

#define INFINITO 1000000000
#define MAX 260

int viz[MAX][MAX];
int peso[MAX][MAX];
int grau[MAX];
int dist[MAX];
int usado[MAX];

int n, m, c, k;

int dijkstra(int origem, int destino) {
    for (int i = 0; i < n; i++) {
        dist[i] = INFINITO;
        usado[i] = 0;
    }
    dist[origem] = 0;

    while (1) {
        int u = -1;
        int menor = INFINITO;
        for (int i = 0; i < n; i++) {
            if (!usado[i] && dist[i] < menor) {
                menor = dist[i];
                u = i;
            }
        }
        
        if (u == -1) break;
        if (u == destino) break;

        usado[u] = 1;
        for (int i = 0; i < grau[u]; i++) {
            int v = viz[u][i];
            int w = peso[u][i];
            if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }

    return dist[destino];
}

int main() {
    int i, u, v, p;
    int resposta;
    
    while (scanf("%d %d %d %d", &n, &m, &c, &k) == 4) {
        if (n == 0 && m == 0 && c == 0 && k == 0) break;

        
        for (i = 0; i < n; i++) grau[i] = 0;

        for (i = 0; i < m; i++) {
            
            scanf("%d %d %d", &u, &v, &p);

            if (u < c && v < c) {
                if (v == u + 1) {
                    viz[u][grau[u]] = v; peso[u][grau[u]] = p; grau[u]++;
                }
                if (u == v + 1) {
                    viz[v][grau[v]] = u; peso[v][grau[v]] = p; grau[v]++;
                }
            }
            else if (u >= c && v >= c) {
                viz[u][grau[u]] = v; peso[u][grau[u]] = p; grau[u]++;
                viz[v][grau[v]] = u; peso[v][grau[v]] = p; grau[v]++;
            }
            else {
                if (u >= c && v < c) {
                    viz[u][grau[u]] = v; peso[u][grau[u]] = p; grau[u]++;
                } else if (v >= c && u < c) {
                    viz[v][grau[v]] = u; peso[v][grau[v]] = p; grau[v]++;
                }
            }
        }

        resposta = dijkstra(k, c - 1);
        printf("%d\n", resposta);
    }

    return 0;
}
