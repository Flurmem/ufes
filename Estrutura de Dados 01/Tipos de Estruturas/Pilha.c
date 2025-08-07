///*
// * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
// * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#define MAX 10
//
//typedef struct noLista {
//    float info;
//    struct noLista* prox;
//} NoLista;
//
//typedef struct pilha {
//    NoLista* topo;
//} Pilha;
//
//Pilha* criarPilha() {
//    Pilha* p = (Pilha*) malloc(sizeof (Pilha));
//    p->topo = NULL;
//    return p;
//}
//
//int estaVazia(Pilha* p) {
//    return (p->topo == NULL);
//}
//
//void push(Pilha* p, float v) {
//    NoLista* novo = (NoLista*) malloc(sizeof (NoLista));
//    novo->info = v;
//    if (novo != NULL) {
//        novo->prox = p->topo;
//        p->topo = novo;
//    } else
//        printf("Espaco nao alocado");
//}
//
//NoLista* pop(Pilha* p) {
//    if (!estaVazia(p)) {
//        NoLista* l = p->topo;
//        p->topo = l->prox;
//
//        float v = l->info;
//
//        free(l);
//
//        return v;
//
//    } else
//        printf("Lista vazia\n");
//    return NULL;
//}
//
//void imprime(Pilha* p) {
//    printf("Pilha \n");
//    for (NoLista* i = p->topo; i != NULL; i = i->prox) {
//        printf("%.0f ", i->info);
//    }
//    printf("\n");
//}
//
//void liberarPilha(Pilha* p) {
//    NoLista *l, *aux;
//    for (l = p->topo; l != NULL; l = aux, aux = l->prox) {
//        aux = l;
//        free(l);
//    }
//    free(p);
//}
//
//int main() {
//    Pilha* pilha = criarPilha();
//    push(pilha, 2);
//    push(pilha, 3);
//    imprime(pilha);
//
//    return 0;
//};