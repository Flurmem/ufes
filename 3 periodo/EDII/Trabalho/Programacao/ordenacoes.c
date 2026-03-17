#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "ordenacoes.h"

// @inicio_bubbleSort
// ============ BUBBLE SORT ============
void bolha(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            est->comparacoes++;

            if (vetor[j] > vetor[j + 1])
            {
                // Realiza a troca
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;

                est->trocas++;
            }
        }
    }
}
// @fim_bubbleSort

// @inicio_bubbleSortComParada
void bolhaComParada(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;
    int mudou = 1;

    while (mudou)
    {
        int j = 1;
        mudou = 0;
        int ultimo_indice_troca = 0;

        while (j < n)
        {
            est->comparacoes++;
            if (vetor[j - 1] > vetor[j])
            {
                int aux = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = aux;

                est->trocas++;
                mudou = 1;
                ultimo_indice_troca = j;
            }
            j = j + 1;
        }
        n = ultimo_indice_troca;
    }
}
// @fim_bubbleSortComParada

// @inicio_selecaoDireta
// ============ SELECAO DIRETA ============
void selecaoDireta(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int menor = i;
        for (int j = i + 1; j < n; j++)
        {
            est->comparacoes++;
            if (vetor[j] < vetor[menor])
            {
                menor = j;
            }
        }

        if (i != menor)
        {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            est->trocas++;
        }
    }
}

// @fim_selecaoDireta

// @inicio_insercaoBinaria
// ============ INSERCAO BINARIA ============
void ordenaBinaria(int *v, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    for (int i = 1; i < n; i++)
    {
        int aux = v[i];
        int esq = 0;
        int dir = i;

        while (esq < dir)
        {
            est->comparacoes++;
            int meio = (esq + dir) / 2;
            if (v[meio] <= aux)
            {
                esq = meio + 1;
            }
            else
            {
                dir = meio;
            }
        }

        for (int j = i; j > esq; j--)
        {
            v[j] = v[j - 1];
            est->trocas++;
        }
        v[esq] = aux;
    }
}

// @fim_insercaoBinaria

//  @inicio_insercaoTernaria

// ============ INSERCAO TERNARIA ============
void ordenaTernaria(int *v, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    for (int i = 1; i < n; i++)
    {
        int aux = v[i];
        int esq = 0;
        int dir = i - 1;

        while (esq <= dir)
        {
            int m1 = esq + (dir - esq) / 3;
            int m2 = dir - (dir - esq) / 3;

            est->comparacoes++;
            if (aux < v[m1])
            {
                dir = m1 - 1;
            }
            else
            {
                est->comparacoes++;
                if (aux > v[m2])
                {
                    esq = m2 + 1;
                }
                else
                {
                    esq = m1 + 1;
                    dir = m2 - 1;
                }
            }
        }

        for (int j = i; j > esq; j--)
        {
            v[j] = v[j - 1];
            est->trocas++;
        }
        v[esq] = aux;
    }
}

//  @fim_insercaoTernaria

//  @inicio_shellSort

// ============ SHELL SORT ============
void shellSort(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    int gap = 1;
    while (gap < n)
    {
        gap = 3 * gap + 1;
    }

    while (gap >= 1)
    {
        for (int i = gap; i < n; i++)
        {
            int aux = vetor[i];
            int j = i - gap;

            while (j >= 0)
            {
                est->comparacoes++;
                if (aux < vetor[j])
                {
                    vetor[j + gap] = vetor[j];
                    est->trocas++;
                    j = j - gap;
                }
                else
                {
                    break;
                }
            }
            vetor[j + gap] = aux;
        }
        gap = gap / 3;
    }
}
//  @fim_shellSort

//  @inicio_insercaoDireta
// ============ INSERCAO DIRETA ============
void ordenaDireta(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    for (int i = 1; i < n; i++)
    {
        int aux = vetor[i];
        int j = i - 1;

        while (j >= 0)
        {
            est->comparacoes++;
            if (aux < vetor[j])
            {
                vetor[j + 1] = vetor[j];
                est->trocas++;
                j = j - 1;
            }
            else
            {
                break;
            }
        }
        vetor[j + 1] = aux;
    }
}
//  @fim_insercaoDireta

//  @inicio_heapSort
// ============ HEAP SORT ============
void criaHeap(int *vetor, int inicio, int final, Estatisticas *est)
{
    int aux = vetor[inicio];
    int j = inicio * 2 + 1;

    while (j <= final)
    {
        if (j < final)
        {
            est->comparacoes++;
            if (vetor[j] < vetor[j + 1])
            {
                j = j + 1;
            }
        }

        est->comparacoes++;
        if (aux < vetor[j])
        {
            vetor[inicio] = vetor[j];
            est->trocas++;
            inicio = j;
            j = 2 * inicio + 1;
        }
        else
        {
            break;
        }
    }
    vetor[inicio] = aux;
}

void heapSort(int *vetor, int n, Estatisticas *est)

{
    est->comparacoes = 0;
    est->trocas = 0;

    for (int i = n / 2 - 1; i >= 0; i--)
    {
        criaHeap(vetor, i, n - 1, est);
    }

    for (int i = n - 1; i > 0; i--)
    {
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        est->trocas++;

        criaHeap(vetor, 0, i - 1, est);
    }
}
//  @fim_heapSort

// @inicio_quickSortCentro
// ============ QUICK SORT - PIVO CENTRO ============
int particaoCentro(int esq, int dir, int vetor[], Estatisticas *est)
{
    int i = esq;
    int j = dir;
    int pivo = vetor[(esq + dir) / 2];

    while (i <= j)
    {
        while (vetor[i] < pivo)
        {
            est->comparacoes++;
            i++;
        }
        est->comparacoes++;

        while (vetor[j] > pivo)
        {
            est->comparacoes++;
            j--;
        }
        est->comparacoes++;

        if (i <= j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            est->trocas++;
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRecursivoCentro(int vetor[], int esq, int dir, Estatisticas *est)
{
    while (esq < dir)
    {
        int p = particaoCentro(esq, dir, vetor, est);

        int tamanhoEsq = (p - 1) - esq;
        int tamanhoDir = dir - p;

        if (tamanhoEsq < tamanhoDir)
        {
            quickSortRecursivoCentro(vetor, esq, p - 1, est);
            esq = p;
        }
        else
        {
            quickSortRecursivoCentro(vetor, p, dir, est);
            dir = p - 1;
        }
    }
}

void quicksortcentro(int vetor[], int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;
    quickSortRecursivoCentro(vetor, 0, n - 1, est);
}
// @fim_quickSortCentro

// @inicio_quickSortFim
// ============ QUICK SORT - PIVO FIM ============
int particaoFim(int esq, int dir, int vetor[], Estatisticas *est)
{
    int i = esq;
    int j = dir - 1;
    int pivo = vetor[dir];

    while (i <= j)
    {
        while (i <= j && vetor[i] < pivo)
        {
            est->comparacoes++;
            i++;
        }
        if (i <= j)
            est->comparacoes++;

        while (i <= j && vetor[j] > pivo)
        {
            est->comparacoes++;
            j--;
        }
        if (i <= j)
            est->comparacoes++;

        if (i <= j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            est->trocas++;
            i++;
            j--;
        }
    }

    int aux = vetor[i];
    vetor[i] = vetor[dir];
    vetor[dir] = aux;
    est->trocas++;

    return i;
}

void quickSortRecursivoFim(int vetor[], int esq, int dir, Estatisticas *est)
{
    while (esq < dir)
    {
        int p = particaoFim(esq, dir, vetor, est);

        if (p - esq < dir - p)
        {
            quickSortRecursivoFim(vetor, esq, p - 1, est);
            esq = p + 1; // Loop trata o lado direito
        }
        else
        {
            quickSortRecursivoFim(vetor, p + 1, dir, est);
            dir = p - 1; // Loop trata o lado esquerdo
        }
    }
}

void quicksortfim(int vetor[], int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;
    if (n > 0)
    {
        quickSortRecursivoFim(vetor, 0, n - 1, est);
    }
}

// @fim_quickSortFim

// @inicio_quickSortMediana
// ============ QUICK SORT - MEDIANA ============
int medianaDe3(int esq, int dir, int vetor[], Estatisticas *est)
{
    int meio = (esq + dir) / 2;

    est->comparacoes++;
    if (vetor[esq] > vetor[meio])
    {
        int aux = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = aux;
        est->trocas++;
    }

    est->comparacoes++;
    if (vetor[meio] > vetor[dir])
    {
        int aux = vetor[meio];
        vetor[meio] = vetor[dir];
        vetor[dir] = aux;
        est->trocas++;
    }

    est->comparacoes++;
    if (vetor[esq] > vetor[meio])
    {
        int aux = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = aux;
        est->trocas++;
    }

    return meio;
}

int particaoMediana(int esq, int dir, int vetor[], Estatisticas *est)
{
    int meio = medianaDe3(esq, dir, vetor, est);
    int pivo = vetor[meio];
    int i = esq;
    int j = dir;

    while (i <= j)
    {
        while (vetor[i] < pivo)
        {
            est->comparacoes++;
            i++;
        }
        est->comparacoes++;

        while (vetor[j] > pivo)
        {
            est->comparacoes++;
            j--;
        }
        est->comparacoes++;

        if (i <= j)
        {
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            est->trocas++;
            i++;
            j--;
        }
    }
    return i;
}

void quickSortRecursivoMediana(int vetor[], int esq, int dir, Estatisticas *est)
{
    while (esq < dir)
    {
        int p = particaoMediana(esq, dir, vetor, est);

        // Calculamos os tamanhos
        int tamanhoEsq = (p - 1) - esq;
        int tamanhoDir = dir - p;

        if (tamanhoEsq < tamanhoDir)
        {
            quickSortRecursivoMediana(vetor, esq, p - 1, est);
            esq = p;
        }
        else
        {
            quickSortRecursivoMediana(vetor, p, dir, est);
            dir = p - 1;
        }
    }
}

void quicksortmediana(int vetor[], int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;
    if (n > 0)
    {
        quickSortRecursivoMediana(vetor, 0, n - 1, est);
    }
}
// @fim_quickSortMediana

// @inicio_mergeSort
// ============ MERGE SORT ============

void intercalar(int vetor[], int inicio, int meio, int final, Estatisticas *est)
{
    int i = inicio;
    int j = meio + 1;
    int k = 0;
    int tamanho = final - inicio + 1;
    int *temp = (int *)malloc(tamanho * sizeof(int));

    while (i <= meio && j <= final)
    {
        est->comparacoes++;
        if (vetor[i] <= vetor[j])
        {
            temp[k] = vetor[i];
            i++;
        }
        else
        {
            temp[k] = vetor[j];
            j++;
        }
        est->trocas++;
        k++;
    }

    while (i <= meio)
    {
        temp[k] = vetor[i];
        i++;
        k++;
        est->trocas++;
    }

    while (j <= final)
    {
        temp[k] = vetor[j];
        j++;
        k++;
        est->trocas++;
    }

    for (i = 0; i < tamanho; i++)
    {
        vetor[inicio + i] = temp[i];
        est->trocas++;
    }

    free(temp);
}

void mergeSort(int vetor[], int inicio, int fim, Estatisticas *est)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergeSort(vetor, inicio, meio, est);
        mergeSort(vetor, meio + 1, fim, est);
        intercalar(vetor, inicio, meio, fim, est);
    }
}

void mergeSortWrapper(int vetor[], int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;
    if (n > 1)
    {
        mergeSort(vetor, 0, n - 1, est);
    }
}
// @fim_mergeSort

// @inicio_radixSort
// ============ RADIX SORT ============
void radixSort(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    // Encontrar o maior número para saber o número de dígitos
    int maior = vetor[0];
    for (int i = 1; i < n; i++)
    {
        est->comparacoes++;
        if (vetor[i] > maior)
            maior = vetor[i];
    }

    // Alocação dinâmica para evitar Stack Overflow com 500k elementos
    int *output = (int *)malloc(n * sizeof(int));
    if (output == NULL)
        return; // Tratamento básico de erro

    for (int exp = 1; maior / exp > 0; exp *= 10)
    {
        int count[10] = {0};

        // Contagem de ocorrências (frequência)
        for (int i = 0; i < n; i++)
        {
            count[(vetor[i] / exp) % 10]++;
        }

        // Posição acumulada (Prefix Sum)
        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
            count[(vetor[i] / exp) % 10]--;
            est->trocas++; // Movimentação para o vetor auxiliar
        }

        // Copiando de volta para o vetor original
        for (int i = 0; i < n; i++)
        {
            vetor[i] = output[i];
            est->trocas++; // Movimentação de volta para o vetor principal
        }
    }

    free(output); // Libera a memória alocada
}
// @fim_radixSort

// @inicio_bucketSort
// ============ BUCKET SORT ============
void bucketSort(int *vetor, int n, Estatisticas *est)
{
    est->comparacoes = 0;
    est->trocas = 0;

    int maior = vetor[0];
    for (int i = 1; i < n; i++)
    {
        est->comparacoes++;
        if (vetor[i] > maior)
        {
            maior = vetor[i];
        }
    }

    int *buckets = (int *)calloc(maior + 1, sizeof(int));

    // Verificação de segurança (caso falte memória RAM)
    if (buckets == NULL)
        return;

    for (int i = 0; i < n; i++)
    {
        buckets[vetor[i]]++;
    }
    int k = 0;
    for (int i = 0; i <= maior; i++)
    {
        // Se o balde i tem elementos, coloca eles de volta no vetor original
        for (int j = 0; j < buckets[i]; j++)
        {
            vetor[k++] = i;
            est->trocas++;
        }
    }

    free(buckets); // Libera a memória alocada
}

// @fim_bucketSort