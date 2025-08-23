/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.c to edit this template
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct noLista
{
    float info;
    struct noLista *prox;
} NoLista;

typedef struct pilha
{
    NoLista *topo;
} Pilha;

Pilha *criarPilha()
{
    Pilha *p = (Pilha *)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

int estaVazia(Pilha *p)
{
    return (p->topo == NULL);
}

void push(Pilha *p, float v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    novo->info = v;
    if (novo != NULL)
    {
        novo->prox = p->topo;
        p->topo = novo;
    }
    else
        printf("Espaco nao alocado");
}

float pop(Pilha *p)
{
    if (!estaVazia(p))
    {
        NoLista *l = p->topo;
        p->topo = l->prox;

        float v = l->info;

        free(l);

        return v;
    }
    else
        printf("Lista vazia\n");
}

void imprime(Pilha *p)
{
    for (NoLista *i = p->topo; i != NULL; i = i->prox)
    {
        printf("%.0f ", i->info);
    }
    printf("\n");
}

void liberarPilha(Pilha *p)
{
    if (!estaVazia(p))
    {
        NoLista *l, *aux;
        for (l = p->topo; l != NULL; l = aux)
        {
            aux = l->prox;
            free(l);
        }
        free(p);
        printf("Lista liberada");
    }
    else
        printf("Lista Vazia \n");
}

void concatenaPilhas(Pilha *p1, Pilha *p2)
{
    if (estaVazia(p2))
    {
        return;
    }
    if (estaVazia(p1))
    {
        p1->topo=p2->topo;
        return;
    }
    if (p1 == p2)
    {
        return;
    }
    NoLista *temp, *ultP2;
    temp = p1->topo;

    for (ultP2 = p2->topo; ultP2->prox != NULL; ultP2 = ultP2->prox)
        ;

    p1->topo = p2->topo;
    ultP2->prox = temp;
}

void concatenaRecursiva(Pilha *p1, Pilha *p2)
{
    if(estaVazia(p2)){
        return;
    }
    if(estaVazia(p1)){
        p1->topo=p2->topo;
        p2->topo=NULL;
        return;
    }
    NoLista* primeiroP2 = p2->topo;
    p2->topo = p2->topo->prox;

    concatenaRecursiva(p1, p2);
    primeiroP2->prox = p1->topo;
    p1->topo = primeiroP2;
}

int diferentes(Pilha *p1, Pilha *p2){
    if(p1==NULL && p2 == NULL){
        return 0;
    }

    else if (p1!=NULL && p2!=NULL){
        NoLista *a1 = NULL, *a2 = NULL;
        for(a1 = p1->topo, a2=p2->topo; a1!=NULL && a2!= NULL; a1=a1->prox, a2=a2->prox){
            if(a1->info!=a2->info){
                return 1;
            }   
        }
        if(a1==NULL && a2 == NULL){
            return 0;
        }
        else return 1;
    }
}

int main()
{
    Pilha *pilha = criarPilha();
    push(pilha, 2);
    push(pilha, 3);
    imprime(pilha);

    Pilha *pilha2 = criarPilha();

    imprime(pilha2);

    int ediferente = diferentes(pilha, pilha2);
    printf("As pilhas sao diferentes: %d", ediferente);

    return 0;
};