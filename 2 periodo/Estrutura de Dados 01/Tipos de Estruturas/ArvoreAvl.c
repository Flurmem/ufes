//#include <stdio.h>
//#include <stdlib.h>
//#include <ctype.h>
//
//typedef struct arvore {
//    int info;
//    int fatBal;
//    struct arvore* dir;
//    struct arvore* esq;
//} Arvore;
//
//Arvore* criarArvoreVazia() {
//    return NULL;
//
//}
//
//void rotacaoRR(arvore** L){
//    Arvore *temp;
//    int fat = (*L)->fatBal;
//    
//    temp = (*L);
//    (*L) = temp->esq;
//    temp->esq = (*L)->dir;
//    (*L)->dir = temp;
//    
//    if(fat==-2){
//        if*=((*L)->fatBal==-1){
//            (*L)->fatBal = temp->fatBal = 0;
//        }
//        else{
//            temp->fatBal = -1;
//            (*L)->fatBal = 1;
//        }
//    }
//    else{
//        if((*L)->fatBal ==0){
//            
//            (*L)->fatBal = 1;
//            temp->fatBal = 0;
//        }
//        else{
//            (*L)->fatBal =0;
//            temp->fatBal =0;
//        }
//    }
//}
//
//void rotacaoLR(arvore** L){
//    Arvore *temp;
//    int fat = (*L)->fatBal;
//    
//    temp = (*L);
//    (*L) = temp->dir;
//    temp->dir = (*L)->esq;
//    (*L)->esq = temp;
//    
//    if(fat==2){
//        if*=((*L)->fatBal==1){
//            (*L)->fatBal = temp->fatBal = 0;
//        }
//        else{
//            temp->fatBal = -1;
//            (*L)->fatBal = 1;
//        }
//    }
//    else{
//        if((*L)->fatBal ==0){
//            
//            (*L)->fatBal = -1;
//            temp->fatBal = 0;
//        }
//        else{
//            (*L)->fatBal =0;
//            temp->fatBal =0;
//        }
//    }
//}
//
//Arvore* criarArvore(int c, Arvore* sae, Arvore* sad) {
//    Arvore* a = (Arvore*) malloc(sizeof (Arvore));
//    if (a != NULL) {
//        a->info = c;
//        a->esq = sae;
//        a->dir = sad;
//    }
//
//    return a;
//}
//
//int estaVazia(Arvore* arv) {
//    return (arv == NULL);
//}
//
//void imprimeArvore(Arvore* arv) {
//    printf("<");
//    if (!estaVazia(arv)) {
//        printf("%d\n", arv->info);
//        imprimeArvore(arv->esq);
//        imprimeArvore(arv->dir);
//    }
//    printf(">");
//}
//
//Arvore* liberarArv(Arvore* arv) {
//    if (!estaVazia(arv)) {
//        liberarArv(arv->esq);
//        liberarArv(arv->dir);
//        free(arv);
//    }
//}
//
//int pertence(Arvore* arv, int c) {
//    if (estaVazia(arv)) {
//        return 0;
//    } else {
//        if (arv->info == c) {
//            return 1;
//        } else
//            return (pertence(arv->esq, c) || pertence(arv->dir, c));
//    }
//}
//
//int numNos(Arvore* arv) {
//    if (estaVazia(arv)) {
//        return 0;
//    } else {
//        return 1 + (numNos(arv->esq) + numNos(arv->dir));
//    }
//
//}
//
//Arvore* busca(Arvore* a, int v) {
//    if (estaVazia(a)) {
//        return NULL;
//    } else {
//        if (a->info == v) {
//            return a;
//        } else if (v < a->info)
//            return busca(a->esq, v);
//        else
//            return busca(a->dir, v);
//
//    }
//}
//
//Arvore* insere(Arvore* a, int v) {
//    if (estaVazia(a)) {
//        a = (Arvore*) malloc(sizeof (Arvore));
//        a->info = v;
//        a->esq = a->dir = NULL;
//    } else
//        if (v < a->info)
//        a->esq = insere(a->esq, v);
//    else
//        a->dir = insere(a->dir, v);
//    return a;
//}
//
//Arvore* remover(Arvore* a, int v) {
//    if (estaVazia(a)) {
//        return NULL;
//    } else {
//        if (v < a->info) {
//            a->esq = remover(a->esq, v);
//        } else
//            if (v > a->info) {
//            a->dir = remover(a->dir, v);
//        } else {
//            if (a->esq == NULL && a->dir == NULL) {
//                free(a);
//                a = NULL;
//            } else if (a->dir == NULL) {
//                Arvore* t = a;
//                a = a->esq;
//                free(t);
//            } else if (a->esq == NULL) {
//                Arvore* t = a;
//                a = a->dir;
//                free(t);
//            }//                else if(a->esq != NULL & a->dir != NULL)
//            else {
//                Arvore *t = a->esq;
//                while (t->dir != NULL) {
//                    t = t->dir;
//                }
//                a->info = t->info;
//                t->info = v;
//                a->esq = remover(a->esq, v);
//            }
//        }
//        return a;
//    }
//
//}
//
//int main() {
//    //  Nó Raiz 
//    Arvore* a = NULL;
//    a = insere(a, 9);
//    a = insere(a, 8);
//    a = insere(a, 7);
//    a = insere(a, 6);
//    a = insere(a, 1);
//    a = insere(a, 2);
//    a = insere(a, 3);
//    a = insere(a, 4);
//    a = insere(a, 5);
//    imprimeArvore(a);
//    printf("\n\n\n");, 
//    
//    a = remover(a, 6);
//    a = remover(a, 8);
//
//    imprimeArvore(a);
//    return 0;
//}