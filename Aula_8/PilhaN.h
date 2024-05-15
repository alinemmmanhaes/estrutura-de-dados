#ifndef PilhaN_h
#define PilhaN_h

typedef int TipoItem;

#include <stdio.h>

#define MaxTam 1000
#define N 10

typedef struct pilhan PilhaN;

PilhaN* CriaPilhaN();

void PushPilhaN(PilhaN* p, int num, TipoItem* item);

void PopPilhaN(PilhaN* p, int num);

void ImprimePilhaN(PilhaN* p, int num);

void LiberaPilhaN(PilhaN* p);

#endif 