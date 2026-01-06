#include "ordenacoes.h"
#include "gera.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n = 500000; //aqui
    int *vetor = (int *) malloc(sizeof(int) * n);
    if (vetor == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    
    geraNumeros(vetor, n, 3); // 1: aleatoria, 2: crescente, 3: decrescente

    Estatisticas est;
    clock_t inicio, fim;

    printf("Algoritmo: Bolha  \n"); //aqui 1
    printf("Tamanho: %d\n", n);

    inicio = clock();
    bolha(vetor, n, &est); //aqui 2
    fim = clock();

    est.tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto na ordenacao: %.8f segundos\n", est.tempo_execucao);
    printf("Trocas: %lld\n", est.trocas);
    printf("Comparacoes: %lld\n", est.comparacoes);

    salvarArquivo(vetor, n);

    free(vetor);

    return 0;
}  