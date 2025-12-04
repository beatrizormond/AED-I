#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
	int conteudo;
	struct cel *seg;
} celula;

void Push(int y, celula *estrutura) {
	celula *nova = malloc(sizeof(celula));

	nova->conteudo = y;
	nova->seg = estrutura->seg;
	estrutura->seg = nova;
}

int Pop(celula *pilha) {
	if(pilha->seg == NULL) {
		return 0;
	}

	celula *lixo;

	lixo = pilha->seg;
    int x = lixo->conteudo;
	pilha->seg = lixo->seg;
	free(lixo);

	return x;
}

void Enfileira(int y, celula *estrutura) {
	celula *nova = malloc(sizeof(celula));
	celula *p = estrutura;

	nova->conteudo = y;
	nova->seg = NULL;

	p = estrutura;

	while(p->seg !=NULL) {
		p = p->seg;
	}

	p->seg = nova;
}

int Desenfileira(celula *estrutura) {
	if(estrutura->seg == NULL) {
		return 0;
	}

	celula *lixo;

	lixo = estrutura->seg;
    int x = lixo->conteudo;
	estrutura->seg = lixo->seg;
	free(lixo);

	return x;
}

void heap_push(int heap[], int *n, int x) {
	int i = (*n);
	heap[i] = x;
	(*n)++;

	while (i > 0) {
		int parent = (i - 1) / 2;

		if (heap[parent] >= heap[i])
			break;

		int tmp = heap[parent];
		heap[parent] = heap[i];
		heap[i] = tmp;

		i = parent;
	}
}

void heapify(int heap[], int i, int n) {
	while (1) {
		int esq = 2*i + 1;
		int dir = 2*i + 2;
		int maior = i;

		if(esq < n && heap[esq] > heap[maior]) {
			maior = esq;
		}
		if(dir < n && heap[dir]> heap[maior]) {
			maior = dir;
		}

		if (maior == i) {
			break;
		}

		int tmp = heap[i];
		heap[i] = heap[maior];
		heap[maior] = tmp;

		i = maior;
	}
}

int heap_pop(int heap[], int *n) {
	if(*n == 0) {
		return -1;
	}
	int max = heap[0];
	heap[0] = heap[*n - 1];
	(*n)--;
	heapify(heap, 0, *n);
	return max;
}

int main() {
	int n, num, x, i, j, p, f, h;
	int queue = 1;
    int stack = 1;
    int Pqueue = 1;

    while (scanf("%d", &n) != EOF) {
        
        int queue = 1;
        int stack = 1;
        int Pqueue = 1;

        celula *pilha = malloc (sizeof(celula));
        pilha->seg = NULL;
        celula *fila = malloc (sizeof(celula));
        fila->seg = NULL;

    int heap[1000];
    int heap_size = 0;

		for (i =0; i<n; i++) {
            
			scanf("%d", &num);
			scanf("%d", &x);

			if(num == 1) {
				Push(x, pilha);
				Enfileira(x, fila);
				heap_push(heap, &heap_size, x);
			}

			else if (num == 2) {
				p = Pop(pilha);
				f = Desenfileira(fila);
				h = heap_pop(heap, &heap_size);

				if (p != x) {
					stack = 0;
				}
				if (f != x) {
					queue = 0;
				}
				if (h != x) {
					Pqueue = 0;
				}
			}
        }
			if (stack + queue + Pqueue == 0) {
				printf("impossible\n");
			}
			else if (stack + queue + Pqueue > 1) {
				printf("not sure\n");
			}
			else if (stack == 1) {
				printf("stack\n");
			}
			else if (queue == 1) {
				printf("queue\n");
			}
			else {
				printf("priority queue\n");
			}
	}

	return 0;
}





