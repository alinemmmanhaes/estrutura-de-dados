#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tProd{
    int valor;
    char* nome;
}tProd;

typedef struct tItem{
    int qtd;
    tProd* prod;
}tItem;

typedef struct tEstoque{
    int valor;
    int nitens;
    tItem** item;
}tEstoque;

typedef struct tFilial{
    char* nome;
    tEstoque* estoque;
}tFilial;

typedef struct tSuper{
    char* nome;
    int valor;
    int nfiliais;
    tFilial** filial;
}tSuper;

