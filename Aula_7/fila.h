#ifndef fila_h
#define fila_h

#include <stdio.h>
#include "amostra.h"

//Tipo opaco que define a fila para testagem
typedef struct fila Fila;

//Cria uma nova fila
Fila* CriaFila();

void insereAmostra(Fila* fila, Amostra* a);

void inserePreferencial(Fila* fila, Amostra* a);

Amostra* removeAmostra(Fila* fila);

//Imprime os dados da fila
void imprimefila(Fila* fila);

//libera todoas os dados alocados para a fila
void liberafila(Fila* fila);

int temAmostraFila(Fila* f);

#endif