#ifndef UTILS_H
#define UTILS_H

#include "ordenacoes.h"
void imprimeVetor(int vetor[], int tam);
void salvarArquivo(int *vetor,char saida[], int ordem, int n) ;
void lerArquivo(char origem[], int ordem, int n, int *vetor);
void testar(void (*funcaoOrdenacao)(int*, int, Estatisticas*), char algoritmo[], int *vetorOriginal, int n, int ordem);
void salvarRelatorio(char algoritmo[], int n, int ordem, Estatisticas est);

#endif