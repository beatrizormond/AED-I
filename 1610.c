#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int V;
    struct nodo *seg;
};

typedef struct {
    int V; //número de vértices
    int 

} grafo;

grafo * criaGrafo(int V){

}

int ExisteLoop(grafo *g){
    int V[g->V];
    int i;

    for (i=0; i<g->V; i++){
        V[i] = 0;
    }

    for(i = 0; i<g->V; i++){
        if(V[i] == 0){
            if(dfs(g, i, V)){
                return 1;
            }
        }
    }
    return 0;
}

int dfs(grafo *g, int u, int V[]){
    V[u] = 1;
    int v;

    for(v = 0; v < g->V; v++){
        if (g->matriz[u][v] == 1){
            
            if(V[v] == 1){
                return 1;
            }
            if(V[v] == 0){
                if(dfs(g, v, V)){
                    return 1;
                }
            }
        }
    }

    V[u] = 2;
    return 0;
}


int main(){
    int t, n, m, a, b, i, j;
    t = 100;
    
    for(i=0; i<t; i++){
        scanf("%d %d", &n, &m);
        grafo *g = criaGrafo(n);
        
        if(n>= 2 && n<=10000 && m>=1 && m<=30000){
            for(j=0; j<m; j++){
                scanf("%d %d", &a, &b);
                if((a>=1) && (b<=n || a!=b)){
                        g->matriz[a-1][b-1] = 1;
                }
            }
        }
        
        if(ExisteLoop(g) == 1){
            printf("SIM\n");
        }
        else{
            printf("NAO\n");
        }
    }
    
    return 0;
}



//Função para criar grafo usando matriz de adjacência
grafo * criaGrafo(int V){
    int i, j;
    grafo *g = malloc(sizeof(grafo));
    g->V = V;

    g->matriz = malloc(V*sizeof(int*));

    for(i = 0; i<V; i++){
        g->matriz[i] = malloc(V*sizeof(int));
        for (j=0; j<V; j++){
            g->matriz[i][j] = 0;
        }
    }
    return g;
}
