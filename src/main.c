#include <stdio.h>
#include "heap.h"

int main() {
    int n, element;
    scanf("%d", &n); // Lê o tamanho do Min Heap

    Heap* h = NovoHeap(n); // Cria um novo Min Heap com capacidade máxima 'n'

    // Inserir elementos no heap
    for (int i = 0; i < n; i++) {
        scanf("%d", &element);
        Inserir(h, element);
    }

    // Remover elementos do heap e imprimir
    for (int i = 0; i < n; i++) {
        element = Remover(h);
        printf("%d ", element);
    }
    printf("\n"); // Quebra de linha no final da saída

    DeletaHeap(h); // Libera a memória alocada para o heap
    return 0;
}
