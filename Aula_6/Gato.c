#include <string.h>
#include <stdlib.h>
#include "Gato.h"

struct gato{
    char* nome;
    int comportamento;
};

Gato* inicGato(char* nome, int tipo){
    Gato* cat = malloc(sizeof(Gato));
    cat->nome = strdup(nome);
    cat->comportamento = tipo;

    return cat;
}

int obtemCompGato(Gato* cat){
    return cat->comportamento;
}

void liberaGato(Gato* cat){
    free(cat->nome);
    free(cat);
}

void ImprimeGato(void* c){
    Gato* cat = (Gato*)c;
    printf("Gato %s\n", cat->nome);
}

void atribuiNivelAgressividadeGato(Gato* cat, int tipo){
    cat->comportamento = tipo;
}