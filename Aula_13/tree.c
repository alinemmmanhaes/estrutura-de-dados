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

Tree* criaArvore(Aluno* aluno){
    Tree* a = malloc(sizeof(Tree));
    a->aluno = aluno;
    a->esq = a->dir = NULL;

    return a;
}

Tree* insereArvore(Tree* a, Aluno* aluno){
    if(arvoreVazia(a)) return criaArvore(aluno);

    if(retornaMatricula(aluno) > retornaMatricula(a->aluno)) a->dir = insereArvore(a->dir, aluno);
    else a->esq = insereArvore(a->esq, aluno);

    return a;
}

Tree* removeArvore(Tree* a, int mat){
    if(arvoreVazia(a)) return NULL;
    if(verificaMatricula(a->aluno, mat)){
        if(folha(a)){
            free(a);
            return NULL;
        }
        else if(arvoreVazia(a->dir)){
            Tree* temp = a;
            a = a->esq;
            free(temp);
        }
        else if(arvoreVazia(a->esq)){
            Tree* temp = a;
            a = a->dir;
            free(temp);
        }
        else{
            Tree* mostright = a->esq;
            while(!arvoreVazia(mostright->dir)){
                mostright = mostright->dir;
            }
            Aluno* temp = mostright->aluno;
            mostright->aluno = a->aluno;
            a->aluno = temp;

            a->esq = removeArvore(a->esq, mat);
        }
    }
    else if(mat > retornaMatricula(a->aluno)) a->dir = removeArvore(a->dir, mat);
    else a->esq = removeArvore(a->esq, mat);

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

        free(a);
    }
    return NULL;
}

int arvoreVazia(Tree* a){
    return(a == NULL);
}

int arvorePertence(Tree* a, Aluno* aluno){
    if(arvoreVazia(a)) return 0;

    if(retornaMatricula(aluno) == retornaMatricula(a->aluno)) return 1;
    else if(retornaMatricula(aluno) > retornaMatricula(a->aluno)) return arvorePertence(a->dir, aluno);
    else return arvorePertence(a->esq, aluno);
}

int folha(Tree* a){
    if(arvoreVazia(a->esq) && arvoreVazia(a->dir)) return 1;
}