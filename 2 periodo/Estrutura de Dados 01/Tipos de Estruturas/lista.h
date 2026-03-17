/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/file.h to edit this template
 */

/* 
 * File:   lista.h
 * Author: Pedro.vargas
 *
 * Created on 26 de Maio de 2025, 15:03
 */

#ifndef lista_h
#define lista_h
#endif

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct lista{
    int itens[MAX];
    int n;
}Lista;

Lista* criarLista();

int estaVazia(Lista *l);

int estaCheia(Lista *l);

void inserirElemento(Lista* l, int v);



void removeElemento(Lista* l, int pos);
