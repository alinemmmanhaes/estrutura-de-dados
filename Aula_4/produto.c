#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

struct produto{
    int cod;
    char* nome;
    int preco;
};

Produto* CriaProd(int cod, char* nome, int preco){
    Produto* p = malloc(sizeof(Produto));
    p->cod = cod;
    p->nome = strdup(nome);
    p->preco = preco;

    return p;
}

int ObtemCodigo(Produto* p){
    return p->cod;
}

void ImprimeProd(Produto* p){
    printf("Produto %s (%d): R$%d\n", p->nome, p->cod, p->preco);
}

void LiberaProd(Produto* p){
    free(p->nome);
    free(p);
}