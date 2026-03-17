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
//void insereElemento(NoLista** l, int v){
//    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
//    if(novo!=NULL){
//        novo->info = v;
//        novo -> prox = *l;
//        *l = novo;
//    }
//    else
//        printf("N foi possivel alocar espaco");
//}
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
//void removeElemento(NoLista** l, int v){
//    NoLista* ant = NULL;
//    NoLista* p = *l;
//    
//    for(p; (p!=NULL && p->info != v); p=p->prox){
//        ant = p;
//    }
//    
//    if(p == NULL){
//        printf("Elemento nao encontrado");
//    }
//    else
//        if(ant==NULL){
//            *l=p->prox;
//        }
//        else
//            ant->prox = p->prox;
//
//    free(p);
//}
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
//NoLista* ultimo(NoLista** l){
//    if(!estaVazia(l)){
//        NoLista* p;
//        for(p = *l; p->prox != NULL; p=p->prox);
//        return p;
//    }
//    else
//        return NULL;
//}
//int main(){
//    NoLista* lista;
//    criarLista(&lista);
//    
//    insereElemento(&lista, 10);
//    insereElemento(&lista, 1);
//    
////  "busca" retorna um ponteiro para o endereço 
//    NoLista* elemento = busca(&lista, 5);
//    printf("%d", ultimo(&lista));
//    
//    imprime(&lista);
//    return 0;
//}