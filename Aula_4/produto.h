#ifndef produto_h
#define produto_h

#include <stdio.h>

typedef struct produto Produto;

Produto* CriaProd(int cod, char* nome, int preco);

int ObtemCodigo(Produto* p);

void ImprimeProd(Produto* p);

void LiberaProd(Produto* p);

#endif