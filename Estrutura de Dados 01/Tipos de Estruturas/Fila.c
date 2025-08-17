#include <stdio.h>
#include <stdlib.h>
#define N 5

typedef struct noLista
{
    float info;
    struct noLista *prox;
} NoLista;

typedef struct fila
{
    NoLista *ini;
    NoLista *fim;
} Fila;

Fila *criarFila()
{
    Fila *f = (Fila *)malloc(sizeof(Fila));
    f->ini = NULL;
    f->fim = NULL;
    return f;
}

int estaVazia(Fila *f)
{
    return (f->ini == NULL);
}

void inserir(Fila *f, float v)
{
    NoLista *novo = (NoLista *)malloc(sizeof(NoLista));
    novo->info = v;
    novo->prox = NULL;

    if (estaVazia(f))
    {
        f->ini = f->fim = novo;
    }
    else
    {
        NoLista *ult;
        f->fim->prox = novo;
        f->fim = novo;
    }
}

void imprime(Fila *f)
{
    if (!estaVazia(f))
    {
        for (NoLista *p = f->ini; p != NULL; p = p->prox)
        {
            printf("%.2f ", p->info);
        }
    }
    else
        printf("Lista Vazia");
    printf("\n");
}

float remover(Fila *f)
{
    if (!estaVazia(f))
    {
        NoLista *temp = f->ini;
        f->ini = temp->prox;
        float v = temp->info;
        free(temp);

        if (f->ini->prox == NULL)
        {
            f->ini = f->fim = NULL;
        }
        return v;
    }
    else
        printf("Não ha nada para remover\n");
}
void liberarFila(Fila *f)
{
    if (!estaVazia(f))
    {
        NoLista *aux, *p;
        for (p = f->ini; p != NULL; p = aux)
        {
            aux = p->prox;
            free(p);
        }
        free(f);
    }
    else
        printf("Nao ha nada para liberar");
}

int maiorFila(Fila *f)
{
    float maior = 0;
    for (NoLista *p = f->ini; p != NULL; p = p->prox)
    {
        if ((p->info) > maior)
        {
            maior = p->info;
        }
    }
    return maior;
}

void furaFila(Fila *f, float v)
{
    NoLista *p, *ant = NULL;
    for (p = f->ini; p->info != v && p != NULL; p = p->prox)
    {
        ant = p;
    }
    if (p == NULL)
    {
        printf("Elemento nao encontrado");
    }
    else
    {
        if (ant == NULL)
        {
            printf("Elemento e o primeiro da lista, n tem pq furar a fila \n");
        }
        else
        {
            ant->prox = p->prox;
            NoLista *temp = f->ini;
            f->ini = p;
            p->prox = temp;
        }
    }
}

void combinaFilas(Fila *f, Fila *f1, Fila *f2)
{
    if (estaVazia(f1) && estaVazia(f2))
    {
        return;
    }
    if (estaVazia(f1))
    {
        f->ini = f2->ini;
        f->fim = f2->fim;
    }
    if (estaVazia(f2))
    {
        f->ini = f1->ini;
        f->fim = f1->fim;
    }

    for (NoLista *p1 = f1->ini, *p2 = f2->ini;
         p1 != NULL || p2 != NULL;
         p1 = p1->prox, p2 = p2->prox)
    {
        inserir(f, p1->info);
        inserir(f, p2->info);
    }
}

void combinarFilasRecursiva(Fila *f, Fila *f1, Fila *f2)
{
    if (estaVazia(f1) && estaVazia(f2))
    {
        return;
    }

    if (!estaVazia(f1))
    {
        inserir(f, f1->ini->info);
    }

    if (!estaVazia(f2))
    {
        inserir(f, f2->ini->info);
    }

    Fila *tempf1, *tempf2;
    tempf1 = (Fila *)malloc(sizeof(Fila));
    tempf2 = (Fila *)malloc(sizeof(Fila));
    tempf1->ini = f1->ini->prox;
    tempf2->ini = f2->ini->prox;
    combinarFilasRecursiva(f, tempf1, tempf2);
    free(tempf1);
    free(tempf2);

    // if (f1->ini->prox == NULL && f2->ini->prox == NULL)
    // {
    //     inserir(f, f1->ini->info);
    //     inserir(f, f2->ini->info);
    //     return;
    // }

    // else if (f1->ini->prox == NULL)
    // {
    //     inserir(f, f1->ini->info);
    //     return;
    // }

    // else if (f2->ini->prox == NULL) {
    //     inserir(f, f2->ini->info);
    //     return;
    // }
    // inserir(f, f1->ini->info);
    // inserir(f, f2->ini->info);

    // Fila *tempf1, *tempf2;
    // tempf1 = (Fila *)malloc(sizeof(Fila));
    // tempf2 = (Fila *)malloc(sizeof(Fila));

    // tempf1->ini = f1->ini->prox;
    // tempf2->ini = f2->ini->prox;
    // combinarFilasRecursiva(f, tempf1, tempf2);
    // free(tempf1);
    // free(tempf2);
}

int main()
{
    Fila *fila = criarFila();
    Fila *fila2 = criarFila();
    Fila *fila3 = criarFila();

    inserir(fila, 11);
    inserir(fila, 12);

    inserir(fila2, 40);
    inserir(fila2, 50);

    imprime(fila);
    imprime(fila2);

    combinarFilasRecursiva(fila3, fila, fila2);
    printf("\n\nFila nova: ");
    imprime(fila3);

    return 0;
};