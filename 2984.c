#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char data;
    struct cel *seg;
} celula;

void Push(celula **topo, char c) {
    celula *novo = (celula*) malloc(sizeof(celula));
    novo->data = c;
    novo->seg = *topo;
    *topo = novo;
}

void Pop(celula **topo) {
    if (*topo != NULL) {
        celula *lixo = *topo;
        *topo = (*topo)->seg;
        free(lixo);
    }
}

int Tamanho(celula *topo) {
    int contador = 0;
    while (topo != NULL) {
        contador++;
        topo = topo->seg;
    }
    return contador;
}

int main() {
    int i, pendentes;
    char str[100005];

    if (scanf("%s", str) != 1) return 0;

    celula *topo = NULL;

    int n = strlen(str);

    for (i = 0; i < n; i++) {
        if (str[i] == '(') {
            Push(&topo, '(');
        } else if (str[i] == ')') {
            if (topo != NULL) {
                Pop(&topo);
            }
        }
    }

    pendentes = Tamanho(topo);

    if (pendentes == 0) {
        printf("Partiu RU!\n");
    } else {
        printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
    }

    while (topo != NULL) {
        Pop(&topo);
    }

    return 0;
}
