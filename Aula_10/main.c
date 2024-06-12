#include <stdio.h>
#include "aluno.h"
#include "tree.h"
#include <stdlib.h>

int main(){
    Aluno* gabriel = criaAluno("gabriel", 1);
    Aluno* aline = criaAluno("aline", 2);
    Aluno* tales1 = criaAluno("tales", 4);
    Aluno* tales2 = criaAluno("tales", 5);
    Aluno* eduardo = criaAluno("eduardo", 3);
    Aluno* malu = criaAluno("malu", 6);

    Tree* arvore = criaArvore(gabriel,
                        criaArvore(aline, 
                            criaArvore(tales1, 
                                criaArvoreVazia(), 
                                criaArvoreVazia()),
                            criaArvore(tales2, 
                                criaArvoreVazia(), 
                                criaArvoreVazia())), 
                        criaArvore(eduardo, 
                            criaArvoreVazia(), 
                            criaArvoreVazia()));

    imprimeArvore(arvore);

    printf("\nfolhas: %d\n", numeroFolhas(arvore));
    printf("altura: %d\n", alturaArvore(arvore));
    printf("numero de tales: %d\n", ocorrenciasNome(arvore, "tales"));
    printf("aline ta na arvore: %d\n", arvorePertence(arvore, aline));
    printf("malu ta na arvore: %d\n", arvorePertence(arvore, malu));

    arvore = liberaArvore(arvore);
    liberaAluno(gabriel);
    liberaAluno(aline);
    liberaAluno(tales1);
    liberaAluno(tales2);
    liberaAluno(eduardo);
    liberaAluno(malu);

    return 0;
}