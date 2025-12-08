#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//1: aleatoria, 2: crescente, 3: decrescente

int geraNumeros(int vetor[], int tam, int ordem){
    int i;
    if (ordem == 1){
        for(i=0; i<tam; i++){
            vetor[i] = rand();
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
    printf("Inicio do vetor:\n");
    for(i = 0; i < tam; i++){
        printf("%d\n", vetor[i]);
    }
    printf("Fim do vetor.\n\n");
}
