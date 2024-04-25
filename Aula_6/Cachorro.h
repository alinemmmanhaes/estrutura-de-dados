#ifndef Cachorro_h
#define Cachorro_h

#include <stdio.h>

typedef struct cachorro Cachorro;

Cachorro* inicCachorro(char* nome, int tipo);

int obtemCompCachorro(Cachorro* dog);

void liberaCachorro(Cachorro* dog);

void ImprimeCachorro(void* d);

void atribuiNivelAgressividadeCachorro(Cachorro* dog, int tipo);

#endif