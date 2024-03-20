#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tProd.h>

typedef struct tProd{
    float valor;
    char* nome;
}tProd;

tProd* CriaProduto(char* nome, float valor){
    tProd* prod = malloc(sizeof(tProd));
    prod->valor = valor;
    prod->nome = strdup(nome);

    return prod;
}

void DesalocaProduto(tProd* prod){
    free(prod->nome);
    free(prod);
}

void ImprimeProduto(tProd* prod){
    printf("%s, valor unitário: %.2f, ", prod->nome, prod->valor);
}

int ComparaNome(tProd* prod, char* nome){
    return !strcmp(prod->nome, nome);
}

float ObtemPrecoProd(tProd* prod){
    return prod->valor;
}