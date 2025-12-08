#include "ordenacoes.h"
#include "gera.h"
#include <stdio.h>

int main()
{
    int vetor[5];
    int n = 5; 

    geraNumeros(vetor, n, 1);
    imprimeVetor(vetor, n);
    radixSort(vetor, n);
    imprimeVetor(vetor, n);

    return 0;
} 