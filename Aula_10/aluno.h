#ifndef aluno_h
#define aluno_h

#include <stdio.h>

typedef struct aluno Aluno;

Aluno* criaAluno(char* nome, int mat);

void imprimeAluno(Aluno* a);

Aluno* liberaAluno(Aluno* a);

int verificaNome(Aluno* a, char* nome);

#endif