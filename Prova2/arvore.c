//ALINE MENDONCA MAYERHOFER MANHAES

#include "arvore.h"
#include <string.h>

struct tree{
    Tree* esq;
    Tree* dir;
    Word* palavra;
};

Tree* criaArvore(char* palavra){
    Tree* a = malloc(sizeof(Tree));
    a->palavra = criaPalavra(palavra);
    a->esq = a->dir = NULL;

    return a;
}

Tree* insereArvore(Tree* a, char* palavra){
    if(arvoreVazia(a)){
        return criaArvore(palavra);
    }
    if(comparaPalavras(palavra, a->palavra) == 0){
        incrementaFreq(a->palavra);
    }
    else if(comparaPalavras(palavra, a->palavra) < 0){
        a->esq = insereArvore(a->esq, palavra);
    }
    else if(comparaPalavras(palavra, a->palavra) > 0){
        a->dir = insereArvore(a->dir, palavra);
    }

    return a;
}

Tree* liberaArvore(Tree* a){
    if(arvoreVazia(a)) return NULL;
    liberaArvore(a->esq);
    liberaArvore(a->dir);
    free(a);
    return NULL;
}

int arvoreVazia(Tree* a){
    if(a == NULL){
        return 1;
    }
    return 0;
}

int numeroPalavrasDist(Tree* a){
    int n = 0;
    if(arvoreVazia(a)) return 0;
    n++;
    n += numeroPalavrasDist(a->esq);
    n += numeroPalavrasDist(a->dir);

    return n;
}

int numeroPalavrasTotal(Tree* a){
    int n = 0;
    if(arvoreVazia(a)) return 0;
    n += retornaFrequencia(a->palavra);
    n += numeroPalavrasTotal(a->esq);
    n += numeroPalavrasTotal(a->dir);

    return n;
}

int maiorFrequencia(Tree* a){
    if(arvoreVazia(a)) return 0;

    int n = retornaFrequencia(a->palavra);

    int e = maiorFrequencia(a->esq);
    if(e > n) n = e;

    int d = maiorFrequencia(a->dir);
    if(d > n) n = d;

    return n;
}

int buscaFrequencia(Tree* a, int freq, FILE* arq){
    if(arvoreVazia(a)) return 0;
    if(buscaFrequencia(a->esq, freq, arq)) return 1; 
    //so analisa a proxima palavra se a primeira nao for a de maior freq, assim fica a primeira da ordem alfabetica
    if(retornaFrequencia(a->palavra) == freq){
        imprimeFreq(a->palavra, arq);
        return 1;
    }
    buscaFrequencia(a->dir, freq, arq);
}

void criaVetorArvore(Tree* a, int* index, Word** vet){
    if(arvoreVazia(a)) return;
    criaVetorArvore(a->esq, index, vet);
    vet[*index] = a->palavra;
    (*index)++;
    criaVetorArvore(a->dir, index, vet);
}