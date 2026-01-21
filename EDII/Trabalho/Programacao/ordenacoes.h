#ifndef ORDENACOES_H
#define ORDENACOES_H

#include "estatisticas.h"

// Algoritmos de ordenação simples [cite: 23]
void bolha(int *vetor, int n, Estatisticas *est);
void bolhaComParada(int *vetor, int n, Estatisticas *est);
void selecaoDireta(int *vetor, int n, Estatisticas *est);
void ordenaBinaria(int *v, int n, Estatisticas *est);
void ordenaTernaria(int *v, int n, Estatisticas *est);
void shellSort(int *vetor, int n, Estatisticas *est);
void ordenaDireta(int *vetor, int n, Estatisticas *est);

// Algoritmos avançados [cite: 23]
void heapSort(int *vetor, int n, Estatisticas *est);
void mergeSortWrapper(int *vetor, int n, Estatisticas *est);

// Variações de Quicksort exigidas [cite: 25, 26, 27, 28]
void quicksortcentro(int *vetor, int n, Estatisticas *est);
void quicksortfim(int *vetor, int n, Estatisticas *est);
void quicksortmediana(int *vetor, int n, Estatisticas *est);

// Algoritmos lineares [cite: 23]
void radixSort(int *vetor, int n, Estatisticas *est);
void bucketSort(int *vetor, int n, Estatisticas *est);

#endif