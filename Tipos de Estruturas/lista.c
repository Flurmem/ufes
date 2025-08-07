//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAX 10
//
//typedef struct lista{
//    int itens[MAX];
//    int n;
//}Lista;
//
//Lista* criarLista(){
//    Lista* l = (Lista*) malloc(sizeof(Lista));
//    
//    if(l != NULL){
//        l->n= 0;
//        return l;
//    }
//    else
//        printf("N foi possivel alocar espaço");
//}
//
////int estaVazia(Lista *l){
////    return(l->n == 0);
////}
////
////int estaCheia(Lista *l){
////    return(l->n == MAX);
////}
//
//void inserirElemento(Lista* l, int v){
//    if(!estaCheia(l)){
//        l->itens[l->n] = v;
//        l->n++;
//    }
//    else
//        printf("Lista Cheia!\n");
//}
//
////void imprime(Lista* l){
////    if(!estaVazia(l)){s
////        for(int i=0; i<l->n; i++){
////            printf("%d ", l->itens[i]);
////        }
////        printf("\n");
////    }
////    else
////        printf("Lista Vazia \n");
////}
//
//void removeElemento(Lista* l, int pos){
//    if( (pos>=1) && (pos<=(l->n)) ){
//        for(int x=pos; x<l->n; x++){
//            l->itens[x-1] = l->itens[x];
//        }
//        l->n--;
//    }
//    else
//        printf("Insira uma posicao valida \n");
//}
