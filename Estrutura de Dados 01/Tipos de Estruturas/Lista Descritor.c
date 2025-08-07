//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct noLista{
//    int info;
//    struct noLista* prox;
//}NoLista;
//
//typedef struct descritor{
//    NoLista *prim;
//    NoLista *ult;
//    int n;
//}Descritor;
//
//void criarLista(Descritor* l){
//    l->prim = l->ult = NULL;
//    l->n = 0;
//}
//
//int estaVazia(Descritor *l){
//    return (l->n==0);
//}
//
//void insereNoInicio(Descritor* l, int v){
//    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
//    if(novo!= NULL){
//    
//        novo->info = v;
//        
////      faz apontar para o que será o antigo primeiro elemento;
//        novo->prox = l->prim;
////      faz o primeiro elemento receber o novo
//        l->prim= novo;
//        
//        if(l->ult == NULL){
//            l->ult = novo;
//        }        
//        l->n++;
//    }
//    else
//        printf("Nao foi possivel alocar");
//    
//}
//
//void insereNoFinal(Descritor* l, int v){
//    NoLista* novo= (NoLista*) malloc(sizeof(NoLista));
//    if (novo!= NULL){
//        novo -> info = v;
//        novo ->prox = NULL;
//        
//        if(!estaVazia(l)){
//            l->ult->prox = novo;
//        }
//        else
//            l->prim = novo;
//        
//        l->ult = novo;
//        l->n++;
//    }
//    else
//        printf("Nao foi possivel alocar memoria");
//}
//
//void imprime(Descritor* l){
//    if(!estaVazia(l)){
//        for(NoLista* p = l->prim; p!=NULL; p=p->prox){
//            printf("%d ", p->info);
//        }
//    }
//
//    else
//        printf("Lista vazia");
//    printf("\n");
//      
//}
//
//void removeElemento(Descritor* l, int v){
//    NoLista* p, *ant=NULL;
//    for(p = l->prim; p!=NULL && p->info!=v; p=p->prox){
//        ant = p;
//    }
//    
//    if(p==NULL){
//        printf("Percorreu tudo e n achou o elemento");
//    }
//    else{
//        
////      Se o elemento a remover for o unico da lista, entao o ant sera NULL, pq definimos como NULL na primeira linha da funcao
//        if(ant==NULL){
//            l->prim = p->prox;
//            
////          Agora como nao ha elementos na lista, prim e ult apontarão para NULL
//            if(l->prim == NULL){
//                l->ult = NULL;
//            }
//        }
//        else{
////          Atualizando o ponteiro do anterior para receber o elemento apontado por p. 
//            ant->prox = p->prox;
////          Após receber o ponteiro do elemento p, se o ponteiro apontar para NULL, entao ant sera o novo elemento ult da lista
//            if(ant->prox ==NULL){
//                l->ult = ant;
//            }
//        }
//        free(p);
//        l->n--;
//    }
//}
//
//
//void libera(Descritor* l){
//    NoLista* p, *temp;
//    for(p = l->prim; p!=NULL; p=temp){
//        temp = p->prox; 
//        free(p);
//    }
//    l->prim=l->ult=NULL;
//    l->n=0;
//}
//
//NoLista* busca(Descritor* l, int v){
//    NoLista* p;
//    for(p=l->prim; p!=NULL && p->info!= v; p=p->prox){
//        if(p->info==v){
//            return p;
//        }
//        else
//            return NULL;
//        
//    }
//}
//
//int main(){
//    Descritor lista;
//    criarLista(&lista);
//    
//    insereNoInicio(&lista, 1);
//    insereNoInicio(&lista, 2);
//    insereNoInicio(&lista, 3);
//    insereNoInicio(&lista, 4);
//    insereNoInicio(&lista, 9898);
//    
//    imprime(&lista);
//  
//    NoLista* elementoEncontrado = busca(&lista, 2);
//    
//    printf("Elemento buscado: %d \n", elementoEncontrado->info);
//    imprime(&lista);
//    
//    return 0;
//}