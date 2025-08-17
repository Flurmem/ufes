#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct arvore
{
    int info;
    struct arvore *dir;
    struct arvore *esq;
} Arvore;

Arvore *criarArvoreVazia()
{
    return NULL;
}

Arvore *criarArvore(int c, Arvore *sae, Arvore *sad)
{
    Arvore *a = (Arvore *)malloc(sizeof(Arvore));
    if (a != NULL)
    {
        a->info = c;
        a->esq = sae;
        a->dir = sad;
    }

    return a;
}

int estaVazia(Arvore *arv)
{
    return (arv == NULL);
}

void imprimeArvore(Arvore *arv)
{
    printf("<");
    if (!estaVazia(arv))
    {
        printf("%d", arv->info);
        imprimeArvore(arv->esq);
        imprimeArvore(arv->dir);
    }
    printf(">");
}

Arvore *liberarArv(Arvore *arv)
{
    if (!estaVazia(arv))
    {
        liberarArv(arv->esq);
        liberarArv(arv->dir);
        free(arv);
    }
}

int pertence(Arvore *arv, int c)
{
    if (estaVazia(arv))
    {
        return 0;
    }
    else
    {
        if (arv->info == c)
        {
            return 1;
        }
        else
            return (pertence(arv->esq, c) || pertence(arv->dir, c));
    }
}

int numNos(Arvore *arv)
{
    if (estaVazia(arv))
    {
        return 0;
    }
    else
    {
        return 1 + (numNos(arv->esq) + numNos(arv->dir));
    }
}

int numFolhas(Arvore *arv)
{
    if (arv == NULL)
    {
        return 0;
    }
    if (arv->esq == NULL && arv->dir == NULL)
    {
        return 1;
    }
    else
        return numFolhas(arv->esq) + numFolhas(arv->dir);
}

Arvore *busca(Arvore *a, int v)
{
    if (estaVazia(a))
    {
        return NULL;
    }
    else
    {
        if (a->info == v)
        {
            return a;
        }
        else if (v < a->info)
            return busca(a->esq, v);
        else
            return busca(a->dir, v);
    }
}

Arvore *insere(Arvore *a, int v)
{
    if (estaVazia(a))
    {
        a = (Arvore *)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
        a->esq = insere(a->esq, v);
    else
        a->dir = insere(a->dir, v);
    return a;
}

Arvore *remover(Arvore *a, int v)
{
    if (estaVazia(a))
    {
        return NULL;
    }
    else
    {
        if (v < a->info)
        {
            a->esq = remover(a->esq, v);
        }
        else if (v > a->info)
        {
            a->dir = remover(a->dir, v);
        }
        else
        {
            if (a->esq == NULL && a->dir == NULL)
            {
                free(a);
                a = NULL;
            }
            else if (a->dir == NULL)
            {
                Arvore *t = a;
                a = a->esq;
                free(t);
            }
            else if (a->esq == NULL)
            {
                Arvore *t = a;
                a = a->dir;
                free(t);
            } //                else if(a->esq != NULL & a->dir != NULL)
            else
            {
                Arvore *t = a->esq;
                while (t->dir != NULL)
                {
                    t = t->dir;
                }
                a->info = t->info;
                t->info = v;
                a->esq = remover(a->esq, v);
            }
        }
        return a;
    }
}

int qtdeNum(Arvore *a, int v)
{
    if (estaVazia(a))
    {
        return 0;
    }
    else
    {
        if (a->info == v)
        {
            return 1 + qtdeNum(a->esq, v) + qtdeNum(a->dir, v);
        }
        else
            return qtdeNum(a->esq, v) + qtdeNum(a->dir, v);
    }
}

int compara(Arvore *a, Arvore *b)
{
    if (estaVazia(a) ^ estaVazia(b))
    {
        return 0;
    }
    if (estaVazia(a) && estaVazia(b))
    {
        return 1;
    }
    else
    {
        if (a->info == b->info)
        {
            return compara(a->esq, b->esq) && compara(a->dir, b->dir);
        }
        else
            return 0;
    }
}

Arvore *copia(Arvore *a)
{
    if (estaVazia(a))
    {
        return NULL;
    }
    else
    {
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
        novo->info = a->info;
        novo->esq = copia(a->esq);
        novo->dir = copia(a->dir);

        return novo;
    }
}

int maiorNum(Arvore *a)
{
    if (estaVazia(a))
    {
        return -1;
    }
    int maiorDir = maiorNum(a->dir);
    if (maiorDir > a->info)
    {
        return maiorDir;
    }
    else
        return a->info;

    int maiorEsq = maiorNum(a->esq);
    if (maiorEsq > a->info)
    {
        return maiorEsq;
    }
    else
        return a->info;
    int maior;

    if (maiorDir > maiorEsq)
    {
        maior = maiorDir;
    }
    else
        maior = maiorEsq;
    return maior;
}

// int qtdNumArvTerciaria(Arvore *a){
//     if(estaVazia(a)){
//         return 0;
//     }
//     else
//     return 1 + qtdNumArvTerciaria(a->dir) + qtdNumArvTerciaria(a->esq) + qtdNumArvTerciaria(a->meio);
// }

int main()
{
    //  Nó Raiz
    Arvore *a = NULL;
    Arvore *b = NULL;
    a = insere(a, 5);
    a = insere(a, 6);
    a = insere(a, 44);
    a = insere(a, 344);
    a = insere(a, 56);
    a = insere(a, 343);
    a = insere(a, 77);

    int maior = maiorNum(a);
    printf("O maior num de e: %d", maior);

    // int iguais = compara(a, b);
    // printf("As arvores sao %s, pois o valor deu %d", iguais == 1 ? "iguais" : "diferentes", iguais);

    return 0;
}