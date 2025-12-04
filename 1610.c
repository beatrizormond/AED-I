#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
	int v;
	struct nodo *seg;
} nodo;

int ciclo;
int cor[10010];
nodo *adj[10010]; //cada posiC'C#o do vetor terC! uma lista encadeada

void AdicionaAresta(int a, int b) {
	nodo *novo = malloc(sizeof(nodo));
	novo->v = b;
	novo->seg = adj[a];
	adj[a] = novo;
}


void dfs(int u) {
	cor[u] = 1; //cinza - visitando
	int v;
	nodo *p = adj[u];

	while (p != NULL) {
		int v = p->v;

		if(cor[v] == 1) {
			ciclo = 1;
			return;
		}

		if (cor[v] == 0) {
			dfs(v);
			if(ciclo) {
				return;
			}
		}

		p = p->seg;
	}

	cor[u] = 2; //preto - visitado
}


int main() {
	int t, n, m, a, b, i, j;
    
    scanf("%d", &t);

	for(i=0; i<t; i++) {
		scanf("%d %d", &n, &m);

		for (j = 1; j<=n; j++) {
			adj[j] = NULL;
			cor[j] = 0;
		}

		ciclo = 0;


		for(j=0; j<m; j++) {
			scanf("%d %d", &a, &b);
			AdicionaAresta(a, b);
		}

		for (j=1; j<=n; j++) {
			if (cor[j] == 0) {
				dfs(j);
				if (ciclo) {
					break;
				}
			}
		}
		if (ciclo) {
			printf("SIM\n");
		}
		else {
			printf("NAO\n");
		}

	}

	return 0;
}
