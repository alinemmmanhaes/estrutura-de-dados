#ifndef PilhaDupla_h
#define PilhaDupla_h

typedef int TipoItem;

#include <stdio.h>

#define MaxTam 1000

typedef struct pilhadupla PilhaDupla;

PilhaDupla* CriaPilhaDupla();

void PushPilha(PilhaDupla* p, int num, TipoItem* item);

void PopPilha(PilhaDupla* p, int num);

void ImprimePilha(PilhaDupla* p, int num);

void LiberaPilha(PilhaDupla* p);

#endif 