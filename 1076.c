#include <stdio.h>
#include <stdlib.h>
#define MAX 1010

int v, a;
int grafo[MAX][MAX];
int cor[MAX];
int contador; 


void dfs(int u) {
	cor[u] = 1; //cinza - visitando
	int w;
    for(w=0; w<v; w++){
        if(grafo[u][w] == 1 && cor[w] == 0){
            contador++;
            dfs(w);
        }
    }
}

int main() {
	int t, i, j, u, f, inicio;
    
    scanf("%d", &t);

	for(i=0; i<t; i++) {
		scanf("%d %d %d", &inicio, &v, &a);
        
        for (int i = 0; i < v; i++) {
            cor[i] = 0;
            for (int j = 0; j < v; j++) {
                grafo[i][j] = 0;
            }
        }
        contador = 0;

        for (int i = 0; i < a; i++) {
            scanf("%d %d", &u, &f);
            grafo[u][f] = 1;
            grafo[f][u] = 1; 
        }

        dfs(inicio);

        printf("%d\n", contador * 2);
    }

    return 0;
}

