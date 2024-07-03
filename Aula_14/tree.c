#include "tree.h"
#include <stdlib.h>

struct tree{
    void* info;
    Tree* esq;
    Tree* dir;
    void (*imprime)(void*);
};

Tree* criaArvoreVazia(){
    return NULL;
}

Tree* criaArvore(void* info, void (*imprime)(void*)){
    Tree* a = malloc(sizeof(Tree));
    a->info = info;
    a->esq = a->dir = NULL;
    a->imprime = imprime;

    return a;
}

Tree* insereArvore(Tree* a, void* info, void (*imprime)(void*), int (*compara)(void*, void*)){
    if(arvoreVazia(a)) return criaArvore(info, imprime);

    if(compara(info, a->info) == 1) a->dir = insereArvore(a->dir, info, imprime, compara);
    else a->esq = insereArvore(a->esq, info, imprime, compara);

    return a;
}

Tree* removeArvore(Tree* a, void* info, int (*compara)(void*, void*)){
    if(arvoreVazia(a)) return NULL;
    if(compara(info, a->info) == 0){
        if(folha(a)){
            free(a);
            return NULL;
        }
        else if(arvoreVazia(a->dir)){
            Tree* temp = a;
            a = a->esq;
            free(temp);
        }
        else if(arvoreVazia(a->esq)){
            Tree* temp = a;
            a = a->dir;
            free(temp);
        }
        else{
            Tree* mostright = a->esq;
            while(!arvoreVazia(mostright->dir)){
                mostright = mostright->dir;
            }
            void* temp = mostright->info;
            mostright->info = a->info;
            a->info = temp;

            a->esq = removeArvore(a->esq, info, compara);
        }
    }
    else if(compara(info, a->info) == 1) a->dir = removeArvore(a->dir, info, compara);
    else a->esq = removeArvore(a->esq, info, compara);

    return a;
}

void imprimeArvore(Tree* a){
    if(arvoreVazia(a)) return;

    imprimeArvore(a->esq);
    a->imprime(a->info);
    imprimeArvore(a->dir);
}

Tree* liberaArvore(Tree* a){
    if(!arvoreVazia(a)){
        liberaArvore(a->esq);
        liberaArvore(a->dir);

        free(a);
    }
    return NULL;
}

int arvoreVazia(Tree* a){
    return(a == NULL);
}

int arvorePertence(Tree* a, void* info, int (*compara)(void*, void*)){
    if(arvoreVazia(a)) return 0;

    if(compara(info, a->info) == 0) return 1;
    else if(compara(info, a->info) == 1) return arvorePertence(a->dir, info, compara);
    else return arvorePertence(a->esq, info, compara);
}

int folha(Tree* a){
    if(arvoreVazia(a->esq) && arvoreVazia(a->dir)) return 1;
}