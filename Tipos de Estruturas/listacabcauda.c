//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct noLista{
//    int info;
//    struct noLista* prox;
//}NoLista;
//
//typedef struct lista{
//    NoLista *cab;
//    NoLista *cau;
//}Lista;
//
//void criarLista(Lista *l){
//    l->cab = (NoLista*) malloc(sizeof(NoLista));
//    l->cau = (NoLista*) malloc(sizeof(NoLista));
//    
//    l->cab->prox = l->cau;
//    l->cau->prox = NULL;
//}
//
//int estaVazia(Lista* l){
//    return (l->cab->prox == l->cau);
//}
//
//void inserirElementoInicio(Lista* l, int v){
//    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
//
//    if(novo != NULL){
//        novo->info = v;
//        novo->prox = l->cab->prox;
//        l->cab->prox = novo;
//}   
//    else
//        printf("Nao foi possivel alocar espaco");
//}
//
//void inserirElementoFim(Lista* l, int v){;
//    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
//
//    if (novo!=NULL){
//        novo->info = v;
//        
//        if (!estaVazia(l)){
//            NoLista* ant;
//            for(ant = l->cab->prox; ant->prox != l->cau; ant=ant->prox);
//            ant->prox = novo;
//        }
//        else
//            l->cab->prox = novo;
//        
//        
//        novo->prox = l->cau;
//    }
//    else
//        printf("nao foi possivel alocar espaco");
//}
//    
//void imprime(Lista* l){
//    NoLista* p;
//    if(!estaVazia(l)){
//        for (p=l->cab->prox; p != l->cau; p=p->prox){
//            printf("%d ", p->info);
//        }
//    }
//    else
//        printf("Erro ao imprimir: Lista Vazia");
//    printf("\n\n");
//    
//}
//
//void removerElemento(Lista* l, int v){
//    NoLista *ant, *p;
//    for(p = l->cab->prox; p->prox!=NULL && p->info !=v; p=p->prox){
//        ant = p;
//    }
//    
////  Verificando se p é igual a NULL;
//    if (p==l->cau){
//        printf("Elemento nao encontrado");
//    }
//    else
//        ant->prox = p->prox;
//        free(p);
//}
//
//void liberarLista(Lista *l){
//    if(!estaVazia(l)){
//        for(NoLista *p = l->cab->prox; p!=l->cau; p=l->cab->prox){
//            l->cab->prox = p->prox;
//            free(p);
//        }
//        printf("Lista liberada \n");
//    }
//    else
//        printf("Lista ja esta vazia \n");
//    
//}
//
//int main(){
//    Lista lista;
//    criarLista(&lista);
//    inserirElementoInicio(&lista, 5);
//    inserirElementoInicio(&lista, 3);
//    inserirElementoFim(&lista, 6);
//    imprime(&lista);
//    liberarLista(&lista);
//    imprime(&lista);
//    
//    inserirElementoFim(&lista, 6);
//    inserirElementoFim(&lista, 7);
//    imprime(&lista);
//    
//    return 0;
//}