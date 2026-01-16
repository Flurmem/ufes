#include "ordenacoes.h"
#include "gera.h"
#include "utils.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int tamanhos[] = {10000, 100000, 500000};

    // Geração dos arquivos de entrada
    for (int i = 1; i <= 3; i++)
    {                               // para cada tipo de ordem
        for (int t = 0; t < 3; t++) // para cada tamanho
        {
            geraNumeros(tamanhos[t], i);
        }
    }

    // Testes de ordenação, para cada tipo de ordem e tamanho
    // for (int x=0; x<3; x++){ // para cada tamanho

    for (int o = 1; o <= 3; o++)
    { // para cada tipo de ordem

        int *vetorOriginal = (int *)malloc(tamanhos[0] * sizeof(int));
        if (vetorOriginal == NULL)
        {
            printf("Erro de memoria para tamanho %d\n", tamanhos[0]);
            exit(1);
        }

        lerArquivo("Origem/input", o, tamanhos[0], vetorOriginal); // lê o arquivo original de cada tamanho e ordem, colocando num ponteiro

        testar("bolha", vetorOriginal, tamanhos[0], o);
        // testar("bolhaComParada", vetorOriginal, o, tamanhos[x]);
        // testar("selecaoDireta", vetorOriginal, o, tamanhos[x]);
        // testar("ordenaBinaria", vetorOriginal, o, tamanhos[x]);
        // testar("ordenaTernaria", vetorOriginal, o, tamanhos[x]);
        // testar("shellSort", vetorOriginal, o, tamanhos[x]);
        // testar("ordenaDireta", vetorOriginal, o, tamanhos[x]);

        // testar("heapSort", vetorOriginal, o, tamanhos[x]);
        // testar("mergeSortWrapper", vetorOriginal, o, tamanhos[x]);

        // testar("quicksortcentro", vetorOriginal, o, tamanhos[x]);
        // testar("quicksortfim", vetorOriginal, o, tamanhos[x]);
        // testar("quicksortmediana", vetorOriginal, o, tamanhos[x]);

        // testar("radixSort", vetorOriginal, o, tamanhos[x]);
        // testar("bucketSort", vetorOriginal, o, tamanhos[x]);
    }
    // }

    return 0;
}