#include "ordenacoes.h"
#include "gera.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int n = 500000;
    int *vetor = (int *) malloc(sizeof(int) * n);
    if (vetor == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    
    geraNumeros(vetor, n, 1);

    Estatisticas est;
    clock_t inicio, fim;

    inicio = clock();
    bolha(vetor, n, &est);
    fim = clock();

    est.tempo_execucao = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo gasto na ordenacao: %.8f segundos\n", est.tempo_execucao);

    return 0;
}  