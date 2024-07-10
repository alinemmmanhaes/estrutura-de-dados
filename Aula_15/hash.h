#ifndef hash_h
#define hash_h

#include "palavra.h"

typedef struct cel Cel;

typedef struct hash Hash;

int hashFunction(char* palavra, int tam);

Hash* criaHash(int tam);

void insereHash(Hash* hash, char* palavra);

void liberaHash(Hash* hash);

void imprime(Hash* hash);

void imprimeOrdenado(Hash* hash);

#endif