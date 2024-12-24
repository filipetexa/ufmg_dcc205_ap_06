#include "../include/heap.h"
#include <stdlib.h>
#include <stdio.h>

Heap* NovoHeap(int maxsize) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->tamanho = 0;
    h->dados = (int*)malloc(maxsize * sizeof(int));
    return h;
}

void DeletaHeap(Heap* h) {
    free(h->dados);
    free(h);
}

void Inserir(Heap* h, int x) {
    h->dados[h->tamanho] = x;
    h->tamanho++;
    HeapifyPorCima(h, h->tamanho - 1);
}

int Remover(Heap* h) {
    if (h->tamanho == 0) return -1; // ou algum outro código de erro
    int min = h->dados[0];
    h->dados[0] = h->dados[h->tamanho - 1];
    h->tamanho--;
    HeapifyPorBaixo(h, 0);
    return min;
}

int Vazio(Heap* h) {
    return h->tamanho == 0;
}

int GetAncestral(Heap* h, int posicao) {
    if (posicao == 0) return -1;
    return (posicao - 1) / 2;
}

int GetSucessorEsq(Heap* h, int posicao) {
    int left = 2 * posicao + 1;
    return left < h->tamanho ? left : -1;
}

int GetSucessorDir(Heap* h, int posicao) {
    int right = 2 * posicao + 2;
    return right < h->tamanho ? right : -1;
}

void HeapifyPorBaixo(Heap* h, int posicao) {
    int left = GetSucessorEsq(h, posicao);
    int right = GetSucessorDir(h, posicao);
    int smallest = posicao;

    if (left != -1 && h->dados[left] < h->dados[smallest]) {
        smallest = left;
    }

    if (right != -1 && h->dados[right] < h->dados[smallest]) {
        smallest = right;
    }

    if (smallest != posicao) {
        // Troca os elementos
        int temp = h->dados[posicao];
        h->dados[posicao] = h->dados[smallest];
        h->dados[smallest] = temp;

        // Heapify por baixo recursivo
        HeapifyPorBaixo(h, smallest);
    }
}

void HeapifyPorCima(Heap* h, int posicao) {
    while (posicao != 0 && h->dados[GetAncestral(h, posicao)] > h->dados[posicao]) {
        int parent_idx = GetAncestral(h, posicao);

        // Troca os elementos
        int temp = h->dados[posicao];
        h->dados[posicao] = h->dados[parent_idx];
        h->dados[parent_idx] = temp;

        // Move up
        posicao = parent_idx;
    }
}
