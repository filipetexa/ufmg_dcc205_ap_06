# ufmg_dcc205_ap_06

Este projeto implementa um Min Heap em C como parte da disciplina de Algoritmos e Estruturas de Dados. O objetivo é desenvolver um programa que lê uma série de números, insere-os em um Min Heap, e então os remove em ordem crescente, imprimindo cada número.

## Estrutura do Projeto

O projeto consiste nos seguintes arquivos:
- `heap.h`: Cabeçalho que define o Tipo Abstrato de Dados (TAD) para o Min Heap.
- `heap.c`: Implementação das funções do TAD Heap.
- `main.c`: Arquivo principal que lê os dados de entrada, utiliza o Min Heap para processá-los e imprime os resultados.

## Compilação e Execução

### Pré-Requisitos

Certifique-se de que você tem um compilador C instalado no seu sistema, como o GCC.

### Compilar o Projeto

Para compilar o projeto, você pode usar o seguinte comando no terminal:

```bash
gcc -o heap_program heap.c main.c
