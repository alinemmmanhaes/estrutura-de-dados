#ifndef Gato_h
#define Gato_h

#include <stdio.h>

typedef struct gato Gato;

Gato* inicGato(char* nome, int tipo);

int obtemCompGato(Gato* cat);

void liberaGato(Gato* cat);

void ImprimeGato(void* c);

void atribuiNivelAgressividadeGato(Gato* cat, int tipo);

#endif