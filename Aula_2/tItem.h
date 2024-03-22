#ifndef _TITEM_H_
#define _TITEM_H_

#include "tProd.h"
typedef struct tItem tItem;

tItem* CriaItem(tProd* prod, int qtd);

void DesalocaItem(tItem* item);

void ImprimeItem(tItem* item);

tItem** LeItens(tProd** prod, int qtdprod, int qtditens);

float ObtemValorItem(tItem* item);

#endif