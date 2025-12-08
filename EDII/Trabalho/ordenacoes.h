#ifndef ORDENACOES_H
#define ORDENACOES_H

// Algoritmos de ordenação simples
void bolha(int *vetor, int n);
void bolhaComParada(int *vetor, int n);
void selecaoDireta(int *vetor, int n);
void ordenaBinaria(int *v, int n);
void ordenaTernaria(int *v, int n);
void shellSort(int *vetor, int n);
void ordenaDireta(int *vetor, int n);

// Algoritmos de ordenação avançados
void heapSort(int *vetor, int n);
void criaHeap(int *vetor, int inicio, int final);

// Quicksort - versões
void quickSort(int vetor[], int esq, int dir);
void quicksort(int vetor[], int n);
int particaoCentro(int esq, int dir, int vetor[]);
void quickSortCentro(int vetor[], int esq, int dir);
void quicksortcentro(int vetor[], int n);
int particaoFim(int esq, int dir, int vetor[]);
void quickSortFim(int vetor[], int esq, int dir);
void quicksortfim(int vetor[], int n);
int medianaDe3(int esq, int dir, int vetor[]);
int particaoMediana(int esq, int dir, int vetor[]);
void quickSortMediana(int vetor[], int esq, int dir);
void quicksortmediana(int vetor[], int n);
int particao(int esq, int dir, int vetor[]);

// Merge Sort
void mergeSort(int vetor[], int inicio, int fim);
void intercalar(int vetor[], int inicio, int meio, int final);

// Algoritmos de ordenação linear
void radixSort(int *vetor, int n);
void bucketSort(int *vetor, int n);

#endif
