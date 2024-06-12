#include <stdlib.h>
#include <string.h>
#include "aluno.h"

struct aluno{
    char* nome;
    int mat;
};

Aluno* criaAluno(char* nome, int mat){
    Aluno* a = malloc(sizeof(Aluno));
    a->nome = strdup(nome);
    a->mat = mat;

    return a;
}

void imprimeAluno(Aluno* a){
    printf("Aluno %s: %d\n", a->nome, a->mat);
}

Aluno* liberaAluno(Aluno* a){
    free(a->nome);
    free(a);
}

int verificaNome(Aluno* a, char* nome){
    return !(strcmp(a->nome, nome));
}