#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <string.h>
#include <windows.h> 
#include <locale.h>

#include "ordenacoes.h"

void imprimeVetor(int vetor[], int tam)
{
    int i;
    printf("\nInicio do vetor:\n");
    for (i = 0; i < tam; i++)
    {
        printf("%d\n", vetor[i]);
    }
    printf("Fim do vetor.\n\n");
}

void salvarArquivo(int *vetor, char saida[], int ordem, int n)
{
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s_%d_%d.txt", saida, ordem, n);
    FILE *f = fopen(nomeArquivo, "w");
    if (f == NULL)
    {
        printf("Erro ao criar o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d\n", vetor[i]);
    }

    fclose(f);
}

void lerArquivo(char origem[], int ordem, int n, int *vetor)
{
    char nomeArquivo[50];
    sprintf(nomeArquivo, "%s_%d_%d.txt", origem, ordem, n);
    FILE *f = fopen(nomeArquivo, "r");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fscanf(f, "%d", &vetor[i]);
    }

    fclose(f);
}

void salvarRelatorio(char algoritmo[], int n, int ordem, Estatisticas est)
{
    setlocale(LC_NUMERIC, "Portuguese");
    char nomeArquivo[] = "resultado.csv";
    int arquivoExiste = 0;

    // Verifica se o arquivo já existe para decidir se escreve o cabeçalho
    FILE *f_check = fopen(nomeArquivo, "r");
    if (f_check != NULL)
    {
        arquivoExiste = 1;
        fclose(f_check);
    }

    FILE *f = fopen(nomeArquivo, "a");
    if (f == NULL)
    {
        printf("Erro ao abrir o relatorio.\n");
        return;
    }

    if (!arquivoExiste)
    {
        fprintf(f, "Algoritmo;Tamanho;Ordem;Comparacoes;Trocas;Tempo(s)\n");
    }

    fprintf(f, "%s;%d;%d;%lld;%lld;%.9f\n", algoritmo, n, ordem, est.comparacoes, est.trocas, est.tempo_execucao);

    fclose(f);
}

void testar(void (*funcaoOrdenacao)(int*, int, Estatisticas*), char algoritmo[], int *vetorOriginal, int n, int ordem)
{
    Estatisticas est;

    // 1. CÓPIA DE SEGURANÇA (Crucial!)
    int *vetorCopia = (int *)malloc(n * sizeof(int));
    memcpy(vetorCopia, vetorOriginal, n * sizeof(int));

    // 2. EXECUÇÃO
    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    
    QueryPerformanceFrequency(&frequency); // Pega a frequência do processador
    QueryPerformanceCounter(&start);       // Inicia cronômetro preciso

    funcaoOrdenacao(vetorCopia, n, &est); // Executa a função de ordenação passada como parâmetro

    QueryPerformanceCounter(&end);
    est.tempo_execucao = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("| %-15s | %-8d | %-2d | C: %-12lld | T: %-12lld | %fs |\n",
           algoritmo, n, ordem, est.comparacoes, est.trocas, est.tempo_execucao);

    // 4. SALVAR NO EXCEL (CSV)
    salvarRelatorio(algoritmo, n, ordem, est);

    // -----------------------------

    // Salvar o arquivo ordenado (opcional, se quiser manter)
    char caminho[100];
    sprintf(caminho, "Saidas/%s", algoritmo);
    salvarArquivo(vetorCopia, caminho, ordem, n);

    free(vetorCopia);
}
