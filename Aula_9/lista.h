#ifndef lista_h
#define lista_h

#include <stdio.h>

typedef struct cel Cel;

typedef Cel Lista;

Lista* criaLista();

Lista* insere(Lista* l, int i);

Lista* retira(Lista* l, int cod);

void imprimeLista(Lista* l);

Lista* liberaLista(Lista* l);

#endif