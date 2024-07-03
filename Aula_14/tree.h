#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct tree Tree;

Tree* criaArvoreVazia();

Tree* criaArvore(void* info, void (*imprime)(void*));

Tree* insereArvore(Tree* a, void* info, void (*imprime)(void*), int (*compara)(void*, void*));

Tree* removeArvore(Tree* a, void* info, int (*compara)(void*, void*));

void imprimeArvore(Tree* a);

Tree* liberaArvore(Tree* a);

int arvoreVazia(Tree* a);

int arvorePertence(Tree* a, void* info, int (*compara)(void*, void*));

int folha(Tree* a);

#endif