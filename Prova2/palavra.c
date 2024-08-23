//ALINE MENDONCA MAYERHOFER MANHAES

#include "palavra.h"
#include <string.h>

struct word{
    char* palavra;
    int freq;
};

Word* criaPalavra(char* palavra){
    Word* p = malloc(sizeof(Word));
    p->palavra = strdup(palavra);
    p->freq = 1;

    return p;
}

void incrementaFreq(Word* palavra){
    palavra->freq++;
}

int retornaFrequencia(Word* palavra){
    return palavra->freq;
}

int ordena(const void* p1, const void* p2){
    Word* pal1 = *(Word**) p1;
    Word* pal2 = *(Word**) p2;
    return pal1->freq - pal2->freq;
}

void imprimePalavra(Word* p, FILE* arq){
    fprintf(arq, "%s %d\n", p->palavra, retornaFrequencia(p));
}

int comparaPalavras(char* p1, Word* p){
    return strcmp(p1, p->palavra);
}

void imprimeFreq(Word* p, FILE* arq){
    fprintf(arq, "%s é a palavra de maior frequência (%d)\n", p->palavra, p->freq);
}

void liberaPalavra(Word* p){
    free(p->palavra);
    free(p);
}

void liberaVetor(Word** vetor, int tam){
    for(int i=0; i<tam; i++){
        liberaPalavra(vetor[i]);
    }
    free(vetor);
}

Word** criaVetor(int tam){
    Word** vetor = calloc(tam, sizeof(Word*));
    return vetor;
}