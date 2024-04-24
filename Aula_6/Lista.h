#ifndef lista_h
#define lista_h

#include <stdio.h>

#define CAT 0
#define DOG 1

typedef struct lista Lista;

Lista* CriaLista();

void InsereAnimal(Lista* l, void* p, int tipo);

void RemoveAnimal(Lista* l, void* p);

void LiberaLista(Lista* l);

int ExisteNaLista(Lista* l, void* p);

#endif