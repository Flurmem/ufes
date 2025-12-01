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
    int comparacoes = 0;

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
    printf("N comparacoes: %d", comparacoes);
}

void selectionSort(int *vetor, int n){
    int comparacoes = 0;
    for(int i = 0; i<n-1; i++){
        int menor = i;
        for (int j=i+1; j<n; j++){
            if (vetor[j] < vetor[menor]){
                comparacoes++;
                menor = j;
            }
        }
        if(i!=menor){
            comparacoes++;
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
    printf("N comparacoes: %d", comparacoes);
}

// void criaHeap(int *vetor, int inicio, int final){
//     int aux = v[inicio];
//     int j = inicio*2 + 1;[
//         while(j<=final){
//             if(j<final){
//                 if(v[j]<v[j+1]){
//                     j=j+1;
//                 }
//             }
//             if(aux<v[j]){
//                 v[inicio] = v[j];
//                 inicio = j;
//                 j=2*inicio+1;
//             }
//         }
//     ]
// }

// void heapSort(int *vetor, int n){

// }

// void particao(int esq, int dir, int vetor[]){
//     int i = esq;
//     int j = dir;
//     int pivo = vetor[(i+j)/2];

//     while(i<=j){
//         while(vetor[i]<pivo && i<dir){
//             i++;
//         }
//         while(vetor[j]>pivo && j>esq){
//             j--;
//         }
//         if(i<=j){
//             int aux = vetor[i];
//             vetor[i] = vetor[j];
//             vetor[j] = aux;
//             i++; j--;
//             // 4 7 6 2 3 8
//             // i = 1, j=4; aux = 7, [1] = [4](3), [4]() = [aux]
//         }
//     }
// }

// void quicksort(int vetor[], int n){
//     int i, j;
//     particao(0, n-1, i, j);

//     if(j > esq){
//         quickSort(vetor, esq, j);
//     }
//     if(i < dir){
//         quickSort(vetor, i, dir);
//     }
// }

void intercalar(int vetor[], int inicio, int meio, int final){
    int i = inicio; int j = meio + 1; int k=0;
    int tamanho = final - inicio + 1;
    int temp[tamanho];
    while( i <=meio || j<=final){

        if ( i == meio + 1 || (vetor[j] < vetor[i] && j!=final+1)){
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

int main()
{
    int vetor[] = {5,4,3,1,7,2};

    for (int i=0; i<6; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    mergeSort(vetor,0, 5);

    for (int i=0; i<6; i++){
        printf("%d ", vetor[i]);
    }

    return 0;
}