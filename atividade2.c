#include <stdio.h>
#include <string.h>

int buscaForcaBruta(char *chave, int m, char *texto, int n){
    for(int i=0; i<(n-m); i++){
        int j=0;
        while(j<m && texto[i+j] == chave[j]){
            // printf("%c, J: %d, M: %d \n \n", chave[j], j+1, m);
            j++;
            if (j == m){
                return 1;
            }
        }
    }
    printf("A string nao foi encontrada \n");
    return 0;
}

int main(){
    char chave[3] = "abc";
    char texto[10] = "abcdefghij";

    // printf("Chave: %d, Texto: %d", strlen(chave), strlen(texto));

    buscaForcaBruta(chave, 3, texto, 10);
    return 0;
}