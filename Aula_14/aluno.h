#ifndef aluno_h
#define aluno_h

#include <stdio.h>

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int mat);

void imprimeAluno(void* a);

Aluno* liberaAluno(Aluno* a);

int comparaAluno(void* info1, void* info2);

#endif