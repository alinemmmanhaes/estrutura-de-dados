#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tEstoque.h>
#include <tFilial.h>

typedef struct tFilial{
    char* nome;
    tEstoque* estoque;
}tFilial;

tFilial* CriaFilial(char* nome, tProd** p, int qtdp){
    tFilial* f = malloc(sizeof(tFilial));
    f->nome = strdup(nome);
    f->estoque = CriaEstoque(p, qtdp);
    return f;
}

void DesalocaFilial(tFilial* f){
    free(f->nome);
    DesalocaEstoque(f->estoque);
    free(f);
}

void ImprimeFilial(tFilial* f){
    printf("\tFilial: %s\n", f->nome);
    ImprimeEstoque(f->estoque);
}