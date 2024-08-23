//ALINE MENDONCA MAYERHOFER MANHAES

#ifndef palavra_h
#define palavra_h

#include <stdio.h>
#include <stdlib.h>

typedef struct word Word;

Word* criaPalavra(char* palavra);

void incrementaFreq(Word* palavra);

int retornaFrequencia(Word* palavra);

int ordena(const void* p1, const void* p2);

void imprimePalavra(Word* p, FILE* arq);

int comparaPalavras(char* p1, Word* p);

void imprimeFreq(Word* p, FILE* arq);

void liberaPalavra(Word* p);

void liberaVetor(Word** p, int tam);

Word** criaVetor(int tam);

#endif