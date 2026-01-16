#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

// 1: aleatoria, 2: crescente, 3: decrescente

void geraNumeros(int tam, int ordem)
{
    FILE *f;
    char arquivo[50];
    sprintf(arquivo, "Origem/input_%d_%d.txt", ordem, tam);
    int i;

    f = fopen(arquivo, "r");
    if (f == NULL){ // Arquivo nao foi encontrado, pode criar normalmente
        int *vetor = (int *)malloc(tam * sizeof(int));
        if (ordem == 1)
        {
            for (i = 0; i < tam; i++)
            {
                vetor[i] = rand() % 1000000;
            }
        }
        else if (ordem == 2)
        {
            for (i = 0; i < tam; i++)
            {
                vetor[i] = i;
            }
        }
        else if (ordem == 3)
        {
            for (i = 0; i < tam; i++)
            {
                vetor[i] = tam - i;
            }
        }
        salvarArquivo(vetor, "Origem/input", ordem, tam);
        free(vetor);
    }
    else // Arquivo ja existe, nao precisa criar
    {
        fclose(f);
    }
}
