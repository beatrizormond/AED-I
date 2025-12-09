#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000     
#define WORD 50      

typedef struct nodo {
    char nome[WORD];
    struct nodo *seg;
} nodo;

nodo *hash_table[MAX];

int hash(char *s) {
    int i, h;
    
    h = 0;

    for (i = 0; s[i]; i++)
        h = (h * 31 + s[i]) % MAX;
    return h;
}

int existe(char *s) {
    int h = hash(s);
    nodo *p = hash_table[h];
    while (p != NULL) {
        if (strcmp(p->nome, s) == 0)
            return 1;
        p = p->seg;
    }
    return 0;
}

void insere(char *s) {
    int h = hash(s);

    nodo *n = malloc(sizeof(nodo));
    strcpy(n->nome, s);
    n->seg = hash_table[h];
    hash_table[h] = n;
}

int main() {
    int n, i;
    scanf("%d", &n);

    for (i = 0; i < MAX; i++)
        hash_table[i] = NULL;

    int distintos = 0;

    for (i = 0; i < n; i++) {
        char nome[WORD];
        scanf("%s", nome);

        if (existe(nome) == 0) {
            insere(nome);
            distintos++;
        }
    }

    printf("Falta(m) %d pomekon(s).\n", 151 - distintos);

    return 0;
}
