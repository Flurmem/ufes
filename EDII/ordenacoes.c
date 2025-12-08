#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

// ============ BUBBLE SORT ============
void bolha(int *vetor, int n){
    clock_t inicio = clock();
    long comparacoes = 0;
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            comparacoes++;
            if(vetor[j] > vetor[j+1]){
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    }
    
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Bubble Sort ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

void bolhaComParada(int *vetor, int n){
    clock_t inicio = clock();
    long comparacoes = 0;
    int mudou = 1;
    
    while (mudou){
        int j=1;
        mudou = 0;
        int indice = 0;
        while (j<n){
            comparacoes++;
            if(vetor[j-1]>vetor[j]) {
                int aux = vetor[j-1];
                vetor[j-1] = vetor[j];
                vetor[j] = aux;
                mudou = 1;
            }
            indice = j;
            j = j+1;
        }
        n = indice;
    }
    
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Bubble Sort com Parada ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

// ============ SELECAO DIRETA ============
void selecaoDireta(int *vetor, int n){
    clock_t inicio = clock();
    long comparacoes = 0;
    for(int i = 0; i<n-1; i++){
        int menor = i;
        for (int j=i+1; j<n; j++){
            comparacoes++;
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
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Selecao Direta ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

// ============ INSERCAO BINARIA ============
void ordenaBinaria(int *v, int n){
    clock_t inicio = clock();
    long comparacoes = 0;
    for(int i=0; i<n; i++){
        int aux = v[i];
        int esq = 0;
        int dir = i;
        while(esq<dir){
            comparacoes++;
            int meio = (esq+dir)/2;
            if (v[meio] <= aux){
                esq = meio + 1;
            }
            else dir = meio;
        }
    
    for(int j=i; j>esq; j--){
        v[j] = v[j-1];
    }
    v[esq] = aux;
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Insercao Binaria ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

// ============ INSERCAO TERNARIA ============
void ordenaTernaria(int *v, int n){
    clock_t inicio = clock();
    long comparacoes = 0;
    for(int i=0; i<n; i++){
        int aux = v[i];
        int esq = 0;
        int dir = i;
        while(esq<dir){
            comparacoes++;
            int m1 = (esq+dir)/3;
            int m2 = 2*(esq+dir)/3;

            if (aux < v[m1]){
                dir = m1 - 1;
            }
            else if (aux >= v[m1] && aux < v[m2]){
                esq = m1 + 1;
                dir = m2 - 1;
            }
            else {
                esq = m2 + 1;
            }
        }
    
    for(int j=i; j>esq; j--){
        v[j] = v[j-1];
    }
    v[esq] = aux;
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Insercao Ternaria ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

// ============ SHELL SORT ============
void shellSort(int *vetor, int n){
    clock_t inicio = clock();
    long comparacoes = 0;

    int gap = 1;
    while ( gap < n){
        gap = 3*gap + 1;
    }
    while (gap>=1){
        for(int i = gap; i<n; i++){
            int aux = vetor[i];
            int j = i - gap;
            while (j>=0 && aux < vetor[j]){
                comparacoes++;
                vetor[j+gap] = vetor[j];
                j = j - gap;
            }
            vetor[j+gap] = aux;
        }
        gap = gap/3;
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Shell Sort ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

// ============ INSERCAO DIRETA ============
void ordenaDireta(int *vetor, int n){
    clock_t inicio = clock();
    long comparacoes = 0;
    for(int i=1; i<n; i++){
        int aux = vetor[i];
        int j=i-1;
        while((j>=0) && aux<vetor[j]){
            comparacoes++;
            vetor[j+1] = vetor[j];
            j=j-1;
        }
        vetor[j+1]=aux;
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Insercao Direta ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
    printf("Comparacoes: %ld\n", comparacoes);
}

// ============ HEAP SORT ============
void criaHeap(int *vetor, int inicio, int final){
    int aux = vetor[inicio];
    int j = inicio*2 + 1;
    while(j<=final){
        if(j<final){
            if(vetor[j]<vetor[j+1]){
                j=j+1;
            }
        }
        if(aux<vetor[j]){
            vetor[inicio] = vetor[j];
            inicio = j;
            j=2*inicio+1;
        }
        else break;
    }
    vetor[inicio] = aux;
}

void heapSort(int *vetor, int n){
    clock_t inicio = clock();
    for(int i = n/2 - 1; i >= 0; i--){
        criaHeap(vetor, i, n-1);
    }
    
    for(int i = n-1; i > 0; i--){
        int aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        criaHeap(vetor, 0, i-1);
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Heap Sort ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ QUICK SORT - PIVO CENTRO ============
int particao(int esq, int dir, int vetor[]){
    int i = esq;
    int j = dir;
    int pivo = vetor[(i+j)/2];

    while(i<=j){
        while(vetor[i]<pivo && i<dir){
            i++;
        }
        while(vetor[j]>pivo && j>esq){
            j--;
        }
        if(i<=j){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++; j--;
        }
    }
    return i;
}

void quickSort(int vetor[], int esq, int dir){
    if(esq < dir){
        int p = particao(esq, dir, vetor);
        quickSort(vetor, esq, p-1);
        quickSort(vetor, p, dir);
    }
}

void quicksort(int vetor[], int n){
    clock_t inicio = clock();
    quickSort(vetor, 0, n-1);
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Quick Sort (Pivo Centro) ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ QUICK SORT - PIVO CENTRO (variante) ============
int particaoCentro(int esq, int dir, int vetor[]){
    int i = esq;
    int j = dir;
    int meio = (esq + dir) / 2;
    int pivo = vetor[meio];

    while(i<=j){
        while(vetor[i]<pivo && i<dir) i++;
        while(vetor[j]>pivo && j>esq) j--;
        if(i<=j){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++; j--;
        }
    }
    return i;
}

void quickSortCentro(int vetor[], int esq, int dir){
    if(esq < dir){
        int p = particaoCentro(esq, dir, vetor);
        quickSortCentro(vetor, esq, p-1);
        quickSortCentro(vetor, p, dir);
    }
}

void quicksortcentro(int vetor[], int n){
    clock_t inicio = clock();
    quickSortCentro(vetor, 0, n-1);
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Quick Sort Centro ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ QUICK SORT - PIVO FIM ============
int particaoFim(int esq, int dir, int vetor[]){
    int i = esq;
    int j = dir - 1;
    int pivo = vetor[dir];

    while(i<=j){
        while(vetor[i]<pivo && i<dir) i++;
        while(vetor[j]>pivo && j>=esq) j--;
        if(i<=j){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++; j--;
        }
    }
    int aux = vetor[i];
    vetor[i] = vetor[dir];
    vetor[dir] = aux;
    return i;
}

void quickSortFim(int vetor[], int esq, int dir){
    if(esq < dir){
        int p = particaoFim(esq, dir, vetor);
        quickSortFim(vetor, esq, p-1);
        quickSortFim(vetor, p+1, dir);
    }
}

void quicksortfim(int vetor[], int n){
    clock_t inicio = clock();
    quickSortFim(vetor, 0, n-1);
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Quick Sort Fim ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ QUICK SORT - MEDIANA ============
int medianaDe3(int esq, int dir, int vetor[]){
    int meio = (esq + dir) / 2;
    
    if(vetor[esq] > vetor[meio]){
        int aux = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = aux;
    }
    if(vetor[meio] > vetor[dir]){
        int aux = vetor[meio];
        vetor[meio] = vetor[dir];
        vetor[dir] = aux;
    }
    if(vetor[esq] > vetor[meio]){
        int aux = vetor[esq];
        vetor[esq] = vetor[meio];
        vetor[meio] = aux;
    }
    
    return meio;
}

int particaoMediana(int esq, int dir, int vetor[]){
    int meio = medianaDe3(esq, dir, vetor);
    int pivo = vetor[meio];
    int i = esq;
    int j = dir;

    while(i<=j){
        while(vetor[i]<pivo && i<dir) i++;
        while(vetor[j]>pivo && j>esq) j--;
        if(i<=j){
            int aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++; j--;
        }
    }
    return i;
}

void quickSortMediana(int vetor[], int esq, int dir){
    if(esq < dir){
        int p = particaoMediana(esq, dir, vetor);
        quickSortMediana(vetor, esq, p-1);
        quickSortMediana(vetor, p, dir);
    }
}

void quicksortmediana(int vetor[], int n){
    clock_t inicio = clock();
    quickSortMediana(vetor, 0, n-1);
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Quick Sort Mediana ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ MERGE SORT ============
void intercalar(int vetor[], int inicio, int meio, int final){
    int i = inicio; int j = meio + 1; int k=0;
    int tamanho = final - inicio + 1;
    int temp[tamanho];
    while( i <=meio || j<=final){
        if ( i == meio + 1 || (j<=final && vetor[j] < vetor[i])){
            temp[k] = vetor[j];
            j++;
            k++;
        }
        else{
            temp[k] = vetor[i];
            i++;
            k++;
        }
    }
    for (i=inicio; i<=final; i++){
        vetor[i] = temp[i-inicio];
    }
}

void mergeSort(int vetor[], int inicio, int fim){
    if (inicio< fim){
        int meio = (inicio+fim)/2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        intercalar(vetor, inicio, meio, fim);
    }
}

void mergeSortWrapper(int vetor[], int n){
    clock_t inicio = clock();
    mergeSort(vetor, 0, n-1);
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Merge Sort ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ RADIX SORT ============
void radixSort(int *vetor, int n){
    clock_t inicio = clock();
    int maior = vetor[0];
    for(int i = 1; i < n; i++){
        if(vetor[i] > maior) maior = vetor[i];
    }
    
    for(int exp = 1; maior / exp > 0; exp *= 10){
        int output[n];
        int count[10] = {0};
        
        for(int i = 0; i < n; i++){
            count[(vetor[i] / exp) % 10]++;
        }
        
        for(int i = 1; i < 10; i++){
            count[i] += count[i-1];
        }
        
        for(int i = n-1; i >= 0; i--){
            output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
            count[(vetor[i] / exp) % 10]--;
        }
        
        for(int i = 0; i < n; i++){
            vetor[i] = output[i];
        }
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Radix Sort ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}

// ============ BUCKET SORT ============
void bucketSort(int *vetor, int n){
    clock_t inicio = clock();
    int maior = vetor[0];
    for(int i = 1; i < n; i++){
        if(vetor[i] > maior) maior = vetor[i];
    }
    
    int buckets[maior + 1];
    for(int i = 0; i <= maior; i++){
        buckets[i] = 0;
    }
    
    for(int i = 0; i < n; i++){
        buckets[vetor[i]]++;
    }
    
    int k = 0;
    for(int i = 0; i <= maior; i++){
        for(int j = 0; j < buckets[i]; j++){
            vetor[k++] = i;
        }
    }
    double tempo = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("\n=== Bucket Sort ===\n");
    printf("Tempo: %.6f segundos\n", tempo);
}
