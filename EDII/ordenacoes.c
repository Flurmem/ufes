#include <stdio.h>
#include <math.h>

void ordenaBinaria(int *v, int n){
    for(int i=0; i<n; i++){
        int aux = v[i];
        int esq = 0;
        int dir = i;
        while(esq<dir){
            int meio = (esq+dir)/2;
            if (v[meio] <= aux){
                esq = meio + 1;
            }
            else dir = meio;
        }
    
    for(int j=i; j>esq; j--){
        v[j] = v[j-1];
    }
    v[dir] = aux;
    }
}

void ordenaTernaria(int *v, int n){
    for(int i=0; i<n; i++){
        int aux = v[i];
        int esq = 0;
        int dir = i;
        while(esq<dir){

            int m1 = (esq+dir)/3;
            int m2 = 2*(esq+dir)/3;

            if (aux >= v[m1]){
                esq = m1 + 1;
            }
            else if (aux >= v[m1] && aux <= v[m2]){
                esq = m1 + 1; dir = m2 - 1;
            }
            else dir = m2 - 1;
        }
    
    for(int j=i; j>esq; j--){
        v[j] = v[j-1];
    }
    v[dir] = aux;
    }
}

void ordenaBolhaParada(int *vetor, int n){
    int mudou = 1;
    int indice = n-1;
    
    while (mudou){
        int j=1;
        mudou = 0;
        while (j<n){
            if(vetor[j-1]>vetor[j]) {
                int aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
                mudou = 1;
            }
            indice = j;
            j = j+1;
        }
        n=indice;
    }
}

void ordenaDireta(int *vetor, int n){
    for(int i=1; i<n; i++){
        int aux = vetor[i];
        int j=i-1;
        while((j>=0) && aux<vetor[j]){
            vetor[j+1] = vetor[j];
            j=j-1;
        }
            vetor[j+1]=aux;
    }
}

void shellSort(int *vetor, int n){

    int gap = 1;
    while ( gap < n){
        gap = 3*gap + 1;
    }
    while (gap>=1){
        for(int i = gap; i<n; i++){
            int aux = vetor[i];
            int j = i - gap;
            while (j>=0 && aux < vetor[j]){
                vetor[j+gap] = vetor[j];
                j = j - gap;
            }
            vetor[j+gap] = aux;
        }
        gap = gap/3;
    }
    
}

void selectionSort(int *vetor, int n){
    for(int i = 0; i<n-1; i++){
        int menor = i;
        for (int j=i+1; j<n; j++){
            if (vetor[j] < vetor[menor]){
                menor = j;
            }
        }
        if(i!=menor){
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

int main()
{
    int vetor[] = {5,4,3,1,7,2};

    for (int i=0; i<6; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    selectionSort(vetor, 6);

    for (int i=0; i<6; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}