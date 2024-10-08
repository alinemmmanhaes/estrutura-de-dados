#include <string.h>
#include <stdlib.h>
#include "Cachorro.h"

struct cachorro{
    char* nome;
    int comportamento;
};

Cachorro* inicCachorro(char* nome, int tipo){
    Cachorro* dog = malloc(sizeof(Cachorro));
    dog->nome = strdup(nome);
    dog->comportamento = tipo;

    return dog;
}

int obtemCompCachorro(Cachorro* dog){
    return dog->comportamento;
}

void liberaCachorro(Cachorro* dog){
    free(dog->nome);
    free(dog);
}

void ImprimeCachorro(void* d){
    Cachorro* dog = (Cachorro*) d;
    printf("Cachorro %s\n", dog->nome);
}

void atribuiNivelAgressividadeCachorro(Cachorro* dog, int tipo){
    dog->comportamento = tipo;
}