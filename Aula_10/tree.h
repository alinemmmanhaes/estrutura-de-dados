#ifndef tree_h
#define tree_h

#include <stdio.h>
#include "aluno.h"

typedef struct tree Tree;

Tree* criaArvoreVazia();

Tree* criaArvore(Aluno* aluno, Tree* dir, Tree* esq);

void imprimeArvore(Tree* a);

Tree* liberaArvore(Tree* a);

int arvoreVazia(Tree* a);

int arvorePertence(Tree* a, Aluno* aluno);

int numeroFolhas(Tree* a);

int ocorrenciasNome(Tree* a , char* nome);

int alturaArvore(Tree* a);

#endif