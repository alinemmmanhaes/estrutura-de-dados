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

void imprimeAluno(void* a){
    Aluno* aluno = (Aluno*) a;
    printf("Aluno %s: %d\n", aluno->nome, aluno->mat);
}

Aluno* liberaAluno(Aluno* a){
    free(a->nome);
    free(a);
}

int comparaAluno(void* info1, void* info2){
    Aluno* aluno1 = (Aluno*) info1;
    Aluno* aluno2 = (Aluno*) info2;

    if(aluno1->mat == aluno2->mat) return 0;
    if(aluno1->mat > aluno2->mat) return 1;
    if(aluno1->mat < aluno2->mat) return -1;
}