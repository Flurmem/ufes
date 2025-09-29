#include <stdio.h>

int buscaBinariaRec(int *vetor, int chave, int esq, int dir){
    int meio = (esq + dir) /2;
    
    if (esq > dir){
        return -1;
    }
    else if (vetor[meio] == chave){
        return meio;
    }
    else if (vetor[meio] > chave){
        return buscaBinariaRec(vetor, chave, esq, meio-1);
    }
    else 
        return buscaBinariaRec(vetor, chave, meio+1, dir);
}

// int busca(int *vetor, int chave, int tamanho) {
//     int esq = -1;
//     int dir = tamanho;
// 	while (esq<=dir) {
// 		int meio = (dir+esq)/2;

// 		if (chave<vetor[meio]) {
// 			dir = meio -1;
// 		}
// 		else if (chave>vetor[meio] +1) {
// 			esq = meio + 1;
// 		}

// 		else
// 			return vetor[meio];
// 	}
	
// 	return -1;
// }

int main()
{
	int tamanho = 5;
	int vetor[5] = {1,2,3,4,5};
	int chave = 4;
    int valor = buscaBinariaRec(vetor, chave, 0, tamanho);
    printf("AAAAA: %d", valor);

	return 0;
}


