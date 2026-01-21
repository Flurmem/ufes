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
    for (int x = 0; x < 3; x++){ // para cada tamanho

        for (int o = 1; o <= 3; o++) // para cada tipo de ordem

        {
            int *vetorOriginal = (int *)malloc(tamanhos[x] * sizeof(int));
            if (vetorOriginal == NULL)
            {
                printf("Erro de memoria para tamanho %d\n", tamanhos[x]);
                exit(1);
            } 

            lerArquivo("Origem/input", o, tamanhos[x], vetorOriginal); // lê o arquivo original de cada tamanho e ordem, colocando num ponteiro

            testar(bolha, "bolha", vetorOriginal, tamanhos[x], o);
            testar(bolhaComParada, "bolhaComParada", vetorOriginal, tamanhos[x], o);
            testar(selecaoDireta, "selecaoDireta", vetorOriginal, tamanhos[x], o);
            testar(ordenaBinaria, "ordenaBinaria", vetorOriginal, tamanhos[x], o);
            testar(ordenaTernaria, "ordenaTernaria", vetorOriginal, tamanhos[x], o);
            testar(shellSort, "shellSort", vetorOriginal, tamanhos[x], o);
            testar(ordenaDireta, "ordenaDireta", vetorOriginal, tamanhos[x], o);

            testar(heapSort, "heapSort", vetorOriginal, tamanhos[x], o);
            testar(mergeSortWrapper, "mergeSortWrapper", vetorOriginal, tamanhos[x], o);

            testar(quicksortcentro, "quicksortcentro", vetorOriginal, tamanhos[x], o);
            testar(quicksortfim, "quicksortfim", vetorOriginal, tamanhos[x], o);
            testar(quicksortmediana, "quicksortmediana", vetorOriginal, tamanhos[x], o);

            testar(radixSort, "radixSort", vetorOriginal, tamanhos[x], o);
            testar(bucketSort, "bucketSort", vetorOriginal, tamanhos[x], o);

            free(vetorOriginal);
        }
    }

    return 0;
}