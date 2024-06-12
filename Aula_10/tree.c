#include "tree.h"
#include <stdlib.h>

struct tree{
    Aluno* aluno;
    Tree* esq;
    Tree* dir;
};

Tree* criaArvoreVazia(){
    return NULL;
}

Tree* criaArvore(Aluno* aluno, Tree* esq, Tree* dir){
    Tree* a = malloc(sizeof(Tree));
    a->aluno = aluno;
    a->esq = esq;
    a->dir = dir;

    return a;
}

void imprimeArvore(Tree* a){
    if(arvoreVazia(a)) return;

    imprimeArvore(a->esq);
    imprimeAluno(a->aluno);
    imprimeArvore(a->dir);
}

Tree* liberaArvore(Tree* a){
    if(!arvoreVazia(a)){
        liberaArvore(a->esq);
        liberaArvore(a->dir);

        //liberaAluno(a->aluno);
        free(a);
    }
    return NULL;
}

int arvoreVazia(Tree* a){
    return(a == NULL);
}

int arvorePertence(Tree* a, Aluno* aluno){
    if(arvoreVazia(a)) return 0;

    return(a->aluno == aluno || arvorePertence(a->esq, aluno) || arvorePertence(a->dir, aluno));
}

int numeroFolhas(Tree* a){
    int n = 0;
    if(arvoreVazia(a->esq) && arvoreVazia(a->dir)) return 1;

    if(!arvoreVazia(a->esq)) n += numeroFolhas(a->esq);
    if(!arvoreVazia(a->dir)) n += numeroFolhas(a->dir);

    return n;
}

int ocorrenciasNome(Tree* a , char* nome){
    int n = 0;
    if(arvoreVazia(a)) return 0;

    if(!arvoreVazia(a->esq)) n += ocorrenciasNome(a->esq, nome);
    if(!arvoreVazia(a->dir)) n += ocorrenciasNome(a->dir, nome);

    if(verificaNome(a->aluno, nome)) n+= 1;

    return n;
}

int alturaArvore(Tree* a){
    int n1 = 0, n2 = 0;
    if(arvoreVazia(a)) return 0;

    if(arvoreVazia(a->esq) && arvoreVazia(a->dir)) return 0;

    n1 = 1 + alturaArvore(a->esq);
    n2 = 1 + alturaArvore(a->dir);

    return (n1>n2)?n1:n2;
}