#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//1: aleatoria, 2: crescente, 3: decrescente

void geraNumeros(int vetor[], int tam, int ordem){
    int i;
    if (ordem == 1){
        for(i=0; i<tam; i++){
            vetor[i] = rand() % 500000; 
        }
    }
    else if (ordem == 2){
        for(i=0; i<tam; i++){
            vetor[i] = i;
        }
    }
    else if (ordem == 3){
        for(i=0; i<tam; i++){
            vetor[i] = tam-i;
        }
    }
}

void imprimeVetor(int vetor[], int tam){
    int i;
    printf("\nInicio do vetor:\n");
    for(i = 0; i < tam; i++){
        printf("%d\n", vetor[i]);
    }
    printf("Fim do vetor.\n\n");
}

void salvarArquivo(int *vetor, int n) {
    FILE *f = fopen("saida.txt", "w");
    if (f == NULL) {
        printf("Erro ao criar o arquivo saida.txt\n");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d\n", vetor[i]); // O \n garante "um por linha"
    }
    
    fclose(f);
}