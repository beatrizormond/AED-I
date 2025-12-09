#include <stdio.h>
#include <string.h>

#define MAX_ITENS 1000
#define MAX 25

void quicksort(char itens[][MAX], int esq, int dir) {
    int i, j;
    char pivo[MAX];
    char temp[MAX];

    i = esq;
    j = dir;

    strcpy(pivo, itens[(esq + dir) / 2]);

    while (i <= j) {
        while (strcmp(itens[i], pivo) < 0) i++;
        while (strcmp(itens[j], pivo) > 0) j--;

        if (i <= j) {
            strcpy(temp, itens[i]);
            strcpy(itens[i], itens[j]);
            strcpy(itens[j], temp);
            i++;
            j--;
        }
    }

    if (esq < j)
        quicksort(itens, esq, j);
    if (i < dir)
        quicksort(itens, i, dir);
}

int main() {
    int n, qtd, x, i, j, k;
    scanf("%d", &n);
    getchar();

    for(x=0; x<n; x++){
        
        char *palavra;
        char linha[25000];
        char itens[MAX_ITENS][MAX];
        qtd = 0;

        fgets(linha, sizeof(linha), stdin);

        palavra = strtok(linha, " \n");
        while (palavra != NULL) {
            strcpy(itens[qtd], palavra);
            qtd++;
            palavra = strtok(NULL, " \n");
        }

        for (i = 0; i < qtd; i++) {
            if (itens[i][0] == '\0') continue;

            for (j = i + 1; j < qtd; j++) {
                if (strcmp(itens[i], itens[j]) == 0) {
                    itens[j][0] = '\0';
                }
            }
        }

        k = 0;
        for (i = 0; i < qtd; i++) {
            if (itens[i][0] != '\0') {
                if (i != k){
                    strcpy(itens[k], itens[i]);
                }
                k++;
            }
        }
        qtd = k;

        quicksort(itens, 0, qtd - 1);

        for (i = 0; i < qtd; i++) {
            if (i > 0) printf(" ");
            printf("%s", itens[i]);
        }
        printf("\n");
    }

    return 0;
}
