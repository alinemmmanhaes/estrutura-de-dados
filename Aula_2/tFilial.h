#ifndef _TFILIAL_H_
#define _TFILIAL_H_

#include "tProd.h"
typedef struct tFilial tFilial;

tFilial* CriaFilial(char* nome, tProd** p, int qtdp);

void DesalocaFilial(tFilial* f);

void ImprimeFilial(tFilial* f);

int FilialObtemValor(tFilial* f);

#endif