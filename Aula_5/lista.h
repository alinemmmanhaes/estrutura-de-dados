#ifndef lista_h
#define lista_h

#include <stdio.h>
#include "produto.h"

typedef struct cel Cel;

typedef Cel Lista;

Lista* CriaLista();

Lista* InsereProd(Lista* l, Produto* p);

Lista* RetiraProd(Lista* l, int cod);

void ImprimeLista(Lista* l);

void LiberaLista(Lista* l);

#endif