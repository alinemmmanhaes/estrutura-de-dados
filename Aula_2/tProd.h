#ifndef _TPROD_H_
#define _TPROD_H_

typedef struct tProd tProd;

tProd* CriaProduto(char* nome, float valor);

void DesalocaProduto(tProd* prod);

void ImprimeProduto(tProd* prod);

int ComparaNome(tProd* prod, char* nome);

float ObtemPrecoProd(tProd* prod);

#endif