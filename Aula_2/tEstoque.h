#ifndef _TESTOQUE_H_
#define _TESTOQUE_H_

#include "tProd.h"
typedef struct tEstoque tEstoque;

tEstoque* CriaEstoque(tProd** prod, int nprod);

float CalculaValor(tEstoque* estoque);

void DesalocaEstoque(tEstoque* estoque);

void ImprimeEstoque(tEstoque* estoque);

int ObtemValorEstoque(tEstoque* e);

#endif