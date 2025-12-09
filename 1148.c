#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define INFINITO 1000000

int n, e;
int tempo[MAX][MAX];
int dist[MAX];
int visitado[MAX];

void dijkstra(int origem){
    int i, j, u, v, novo, melhor;
    for(i=0; i<n; i++){
        dist[i] = INFINITO;
        visitado[i] = 0;
    }
    dist[origem] = 0;

    for(i=0; i<n; i++){
        u = -1;
        melhor = INFINITO;
        for(j=0; j<n; j++){
            if(visitado[j] == 0 && dist[j] < melhor){
                melhor = dist[j];
                u = j; //atualiza o vertice
            }
        }
        if(u == -1) break;
        visitado[u] = 1;
    
        for(v=0; v<n; v++){
            if(tempo[u][v] < INFINITO && visitado[v] == 0){
                novo = dist[u] + tempo[u][v];
                if(novo < dist[v]){
                    dist[v] = novo;
                }
            }
        }
    }
}

int main(){
    int i, j, x, y, h, o, d, k;

    while(1){
        
        scanf("%d %d", &n, &e);
        if(n==0 && e==0) break;

        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                tempo[i][j] = INFINITO;
            }
        }
        for (i=0; i<e; i++){
            scanf("%d %d %d", &x, &y, &h);
            x--;
            y--;
            
            if(h < tempo[x][y]){
                tempo[x][y] = h;
            }
            if(tempo[y][x] < INFINITO){
                tempo[y][x] = 0;
                tempo[x][y] = 0;
            }
        }

        scanf("%d", &k);
        for(i=0; i<k; i++){
            scanf("%d %d", &o, &d);
            o--;
            d--;
        
            dijkstra(o);
            if(dist[d] >= INFINITO){
                printf("Nao e possivel entregar a carta\n");
            }
            else{
                printf("%d\n", dist[d]);
            }
        }
        printf("\n");
    }

    return 0;
}
