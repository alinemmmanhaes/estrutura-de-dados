#ifndef lista_h
#define lista_h

#include <stdio.h>
#include "produto.h"

typedef struct lista Lista;

Lista* CriaLista();

void InsereInicioProd(Lista* l, Produto* p);

void InsereFimProd(Lista* l, Produto* p);

void RetiraProd(Lista* l, int cod);

void ImprimeLista(Lista* l);

void LiberaLista(Lista* l);

#endif