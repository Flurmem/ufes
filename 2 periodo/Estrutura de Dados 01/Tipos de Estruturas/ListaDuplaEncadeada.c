///*
// * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
// * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct noLista{
//    int info;
//    struct noLista* prox;
//    struct noLista* ant;
//}NoLista;
//
//void criarLista(NoLista** l){
//    *l=NULL;
//}
//
//int estaVazia(NoLista** l){
//    return (*l == NULL);
//}
//
//void inserirElemento (NoLista** l, int v) {
//	NoLista* novo = (NoLista*) malloc (sizeof(NoLista));
//	if (novo != NULL) {
//		novo -> info = v;
//		novo -> ant = NULL;
//
//            if (!estaVazia(l)) {
//                    novo->prox = l->prox;
////                    l -> ant = novo;
////                    l->prox = novo;
//            }
//            else {
//                    novo->prox = NULL;
//
//            }
//                l->prox = novo;
//}
//	else {
//		printf("Nao foi possivel alocar espaco!");
//	}
//}
//
//
//void imprime(NoLista** l){
//    if(!estaVazia(l)){
//        for(NoLista *p = *l; p!=NULL; p=p->prox){
//            printf("%d ", p->info);
//        }
//        printf("\n");
//    }
//    else
//        printf("Lista Vazia!");
//}
//
//int qtdElementos(NoLista** l){
//        if(!estaVazia(l)){
//            int contador = 0;
//            for(NoLista *p = *l; p!=NULL; p=p->prox){
//                contador++;
//            }
//            return contador;
//    }
//        else
//            return 0;
//}
//
//NoLista* busca(NoLista** l, int v){
//    for(NoLista* p =*l; p!=NULL; p=p->prox){
//        if(p->info == v){
//            return p;
//        }
//    }
//    return NULL;
//}
//
//void removerElemento(NoLista** l, int v){
//    NoLista* p = NULL;
//    for(p = *l; p != NULL && p->info != v; p = p->prox);
//	
//    if(p == NULL){
//        printf("Elemento não encontrado!\n");
//    }
//    else
//    {
//        if(p->ant != NULL){
//            p->ant->prox = p->prox;
//    }
//    if(p->prox != NULL){
//            p->prox->ant = p->ant;
//    }
//    free(p);
//    }
//}
//
//
//void libera(NoLista** l){
//    NoLista* p, *temp;
//    for(p=*l; p!=NULL; p=temp){
//        temp=p->prox;
//        free(p);
//    }
//    *l=NULL;
//}
//void InsereOrdenado(NoLista** l, int v){
//    NoLista* p, *ant=NULL;
//    
//    for(p=*l; p!=NULL&&p->info<v; p=p->prox){
//        NoLista* novo=(NoLista*) malloc(sizeof(NoLista));
//        
//        if(novo!=NULL){
//            novo->info=v;
//            
//            if(ant==NULL){
//                novo->prox = *l;
//                *l = novo;
//            }
//            else{
//                novo->prox=p;
//                ant->prox=novo;
//            }
//        }
//        else
//            printf("Nao foi possivel alocar espaco");
//    }
//}
//
//NoLista* ultimoElemento (NoLista** l) {
//	if (!estaVazia(l)) {
//            NoLista* p;
//            for (p = *l; p -> prox != NULL; p = p -> prox);
//            return p;
//        }
//        else {
//                printf("Lista vazia");
//                return NULL;
//        }
//}
//
//void ImprimeListaOrdemInversa(NoLista** l){
//	if(!estaVazia(l)){
//		NoLista *p = ultimoElemento(l);
//		for(p; p->ant != NULL; p = p->ant)
//			printf("%d", p->info);
//}
//	else
//		printf("LISTA VAZIA");
//}
//
//
//int main(){
//    NoLista* lista;
//    criarLista(&lista);
//    
//    inserirElemento(&lista, 10);
//    inserirElemento(&lista, 1);
//    imprime(&lista);
//    imprimeListaOrdemInversa(&lista);
//    
////  "busca" retorna um ponteiro para o endereço 
//    NoLista* elemento = busca(&lista, 5);
//    printf("%d", ultimoElemento(&lista));
//    
//    imprime(&lista);
//    return 0;
//};