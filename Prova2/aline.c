//ALINE MENDONCA MAYERHOFER MANHAES

#include "arvore.h"
#include <stdio.h>
#include <stdlib.h>
#include "palavra.h"

int main(){
    FILE* entrada = fopen("entrada.txt", "r");
    char palavra[1000];
    fscanf(entrada, "%s", palavra);
    Tree* arvore = criaArvore(palavra);

    while(fscanf(entrada, "%s", palavra) == 1){
        insereArvore(arvore, palavra);
    }
    fclose(entrada);

    int tamVetor = numeroPalavrasDist(arvore);
    Word** vetor = criaVetor(tamVetor);
    
    int index = 0;
    criaVetorArvore(arvore, &index, vetor);
    qsort(vetor, tamVetor, sizeof(Word*), ordena);

    FILE* saida = fopen("saida.txt", "w");
    for(int i=0; i<tamVetor; i++){
        imprimePalavra(vetor[i], saida);
    }
    fprintf(saida, "------------------------\n");
    fprintf(saida, "%d palavras distintas encontradas\n", numeroPalavrasDist(arvore));
    fprintf(saida, "%d palavras no total\n", numeroPalavrasTotal(arvore));
    buscaFrequencia(arvore, maiorFrequencia(arvore), saida);
    fclose(saida);

    liberaArvore(arvore);
    liberaVetor(vetor, tamVetor);

    return 0;
}