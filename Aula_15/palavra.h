#ifndef palavra_h
#define palavra_h

#include <stdio.h>

typedef struct palavra Palavra;

Palavra* criaPalavra(char* word);

char* retornaPalavra(Palavra* p);

void incrementaFreq(Palavra* p);

void liberaPalavra(Palavra* p);

void imprimePalavra(Palavra* p);

int comparaPalavras(const void* p1, const void* p2);

#endif