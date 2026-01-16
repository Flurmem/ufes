#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "utils.h"

//1: aleatoria, 2: crescente, 3: decrescente

void geraNumeros(int tam, int ordem){
    int i;
    int *vetor = (int*)malloc(tam * sizeof(int));
    if (ordem == 1){
        for(i=0; i<tam; i++){
            vetor[i] = rand() % 1000000; 
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
    salvarArquivo(vetor,"Origem/input", ordem, tam);
}

