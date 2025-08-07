//#include <stdio.h>
//#include <stdlib.h>
//#define N 5
//
//typedef struct noLista{
//    float info;
//    struct noLista* prox;
//}NoLista;
//
//typedef struct fila{
//    NoLista* ini;
//    NoLista* fim;
//} Fila;
//
//Fila* criarFila(){
//    Fila* f = (Fila*) malloc(sizeof(Fila));
//    f->ini = NULL;
//    f->fim = NULL;
//    return f;
//}
//
//int estaVazia(Fila* f){
//    return (f->ini==NULL);
//}
//
//void inserir(Fila* f, float v){
//    NoLista* novo = (NoLista*) malloc(sizeof(NoLista));
//    novo->info = v;
//    novo->prox = NULL;
//    
//    if(estaVazia(f)){
//        f->ini = f->fim = novo;
//    }
//    else{
//        NoLista* ult;
//        f->fim->prox = novo;
//        f->fim=novo;
//    }
//        
//}
//
//void imprime(Fila* f){
//    if(!estaVazia(f)){
//        for(NoLista* p = f->ini; p!=NULL; p=p->prox){
//            printf("%.2f ", p->info);
//        }
//    }
//    else
//        printf("Lista Vazia");
//    printf("\n");
//}
//
//float remover(Fila* f){
//    if(!estaVazia(f)){
//        NoLista* temp = f->ini;
//        f->ini = temp->prox;
//        float v = temp ->info;
//        free(temp);
//        
//        if (f->ini->prox==NULL){
//            f->ini = f->fim = NULL;
//        }
//        return v;
//    }
//    else
//        printf("Não ha nada para remover\n");
//}
//void liberarFila(Fila *f){
//    if(!estaVazia(f)){
//        NoLista* aux, *p;
//        for(p=f->ini; p!=NULL; p=aux){
//            aux = p->prox;
//            free(p);
//        }
//        free(f);
//    }
//    else
//        printf("Nao ha nada para liberar");
//    
//}
//
//void furaFila(Fila* f, float v){
//    NoLista* p, *ant=NULL;
//    for(p=f->ini; p->info!=v && p!=NULL; p=p->prox){
//        ant = p;
//    }
//    if(p==NULL){
//        printf("Elemento nao encontrado");
//    }
//    else{
//        if(ant==NULL){
//            printf("Elemento e o primeiro da lista, n tem pq furar a fila \n");
//        }
//        else{
//            ant->prox = p->prox;
//            NoLista* temp = f->ini;
//            f->ini = p;
//            p->prox = temp;
//        }     
//    }
//        
//}
//
//int main() {
//    Fila* fila = criarFila();
//    
//    inserir(fila, 11);
//    inserir(fila, 12);
//    inserir(fila, 40);
//    inserir(fila, 130);
//    
//    imprime(fila);
//    liberarFila(fila);
//    imprime(fila);
//
//
//    
//    return 0;
//};