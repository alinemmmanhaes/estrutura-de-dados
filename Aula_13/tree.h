#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "aluno.h"

typedef struct tree Tree;

Tree* criaArvoreVazia();

Tree* criaArvore(Aluno* aluno);

Tree* insereArvore(Tree* a, Aluno* aluno);

Tree* removeArvore(Tree* a, int mat);

void imprimeArvore(Tree* a);

Tree* liberaArvore(Tree* a);

int arvoreVazia(Tree* a);

int arvorePertence(Tree* a, Aluno* aluno);

int folha(Tree* a);

#endif