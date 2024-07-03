#include <stdio.h>
#include "aluno.h"
#include "tree.h"
#include <stdlib.h>

int main(){
    Aluno* gabriel = criaAluno("gabriel", 1);
    Aluno* aline = criaAluno("aline", 2);
    Aluno* eduardo = criaAluno("eduardo", 3);
    Aluno* tales1 = criaAluno("tales", 4);
    Aluno* tales2 = criaAluno("tales", 5);
    Aluno* malu = criaAluno("malu", 6);
    Aluno* raony = criaAluno("malu", 7);
    Aluno* marcela = criaAluno("malu", 0);

    Tree* arvore = criaArvore(tales1, imprimeAluno);
    arvore = insereArvore(arvore, gabriel, imprimeAluno, comparaAluno);
    arvore = insereArvore(arvore, tales2, imprimeAluno, comparaAluno);
    arvore = insereArvore(arvore, aline, imprimeAluno, comparaAluno);
    arvore = insereArvore(arvore, eduardo, imprimeAluno, comparaAluno);
    arvore = insereArvore(arvore, malu, imprimeAluno, comparaAluno);
    imprimeArvore(arvore);

    printf("\naline ta na arvore: %d\n", arvorePertence(arvore, aline, comparaAluno));
    printf("malu ta na arvore: %d\n", arvorePertence(arvore, malu, comparaAluno));
    printf("raony ta na arvore: %d\n", arvorePertence(arvore, raony, comparaAluno));
    printf("marcela ta na arvore: %d\n\n", arvorePertence(arvore, marcela, comparaAluno));

    removeArvore(arvore, tales1, comparaAluno);
    imprimeArvore(arvore);

    arvore = liberaArvore(arvore);
    liberaAluno(gabriel);
    liberaAluno(aline);
    liberaAluno(tales1);
    liberaAluno(tales2);
    liberaAluno(eduardo);
    liberaAluno(malu);
    liberaAluno(marcela);
    liberaAluno(raony);

    return 0;
}