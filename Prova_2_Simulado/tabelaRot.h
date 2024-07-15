#ifndef tabelaRot_h
#define tabelaRot_h

#include <stdio.h>

typedef struct tabela Tabela;

typedef struct hash Hash;

Hash* criaHash(int t);

void insereTabela(int dest, int nxthop, Hash* hash);

int buscaRot(int dest, Hash* hash);

void liberaHash(Hash* hash);

#endif