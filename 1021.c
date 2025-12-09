#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

typedef struct {
    celula *inicio;
    celula *fim;
} fila;

void Enfileira(fila *f, int x) {
    celula *novo = malloc(sizeof(celula));
    novo->valor = x;
    novo->seg = NULL;

    if (f->fim == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->seg = novo;
        f->fim = novo;
    }
}

int Desenfileira(fila *f) {
    celula *lixo;
    int x;

    lixo = f->inicio;
    x = lixo->valor;

    f->inicio = lixo->seg;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(lixo);
    return x;
}

int main() {
    double valor;
    int total, inteiro, centavos, v, m, i;
    fila f;

    f.inicio = NULL;
    f.fim = NULL;

    scanf("%lf", &valor);

    total = (int)(valor * 100 + 0.5);
    inteiro = total / 100;
    centavos = total % 100;

    int valores[] = {100, 50, 20, 10, 5, 2};
    int moedas[]  = {100, 50, 25, 10, 5, 1};

    for (i = 0; i < 6; i++) {
        Enfileira(&f, valores[i]);
    }

    printf("NOTAS:\n");

    for (i = 0; i < 6; i++) {
        v = Desenfileira(&f);
        printf("%d nota(s) de R$ %d.00\n", inteiro / v, v);
        inteiro %= v;
    }

    // juntar o resto dos reais com os centavos
    centavos += inteiro * 100;

    for (i = 0; i < 6; i++) {
        Enfileira(&f, moedas[i]);
    }

    printf("MOEDAS:\n");

    for (i = 0; i < 6; i++) {
        m = Desenfileira(&f);
        printf("%d moeda(s) de R$ %.2f\n", centavos / m, m / 100.0);
        centavos %= m;
    }

    return 0;
}
