//ALINE MENDONCA MAYERHOFER MANHAES

#ifndef arvore_h
#define arvore_h

#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"

typedef struct tree Tree;

Tree* criaArvore(char* palavra);

Tree* insereArvore(Tree* a, char* palavra);

Tree* liberaArvore(Tree* a);

int arvoreVazia(Tree* a);

int numeroPalavrasDist(Tree* a);

int numeroPalavrasTotal(Tree* a);

int maiorFrequencia(Tree* a);

int buscaFrequencia(Tree* a, int freq, FILE* arq);

void criaVetorArvore(Tree* a, int* index, Word** vet);

#endif