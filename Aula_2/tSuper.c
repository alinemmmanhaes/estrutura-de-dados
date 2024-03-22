#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tFilial.h"
#include "tSuper.h"

typedef struct tSuper{
    char* nome;
    float valor;
    int nfiliais;
    tFilial** filial;
}tSuper;

tSuper* CriaSuper(char* nome, tProd** prod, int nprod){
    char nomef[100];
    tSuper* s = malloc(sizeof(tSuper));
    s->nome = strdup(nome);
    s->valor = 0;

    printf("Quantas filiais? ");
    scanf("%d%*c", &s->nfiliais);
    s->filial = malloc(s->nfiliais*sizeof(tFilial*));

    for(int i=0; i<s->nfiliais; i++){
        printf("Qual o nome da filial %d? ", i+1);
        scanf("%[^\n]%*c", nomef);
        s->filial[i] = CriaFilial(nomef, prod, nprod);
        s->valor += FilialObtemValor(s->filial[i]);
    }

    return s;
}

void DesalocaSuper(tSuper* s){
    free(s->nome);
    for(int i=0; i<s->nfiliais; i++){
        DesalocaFilial(s->filial[i]);
    }
    free(s->filial);
    free(s);
}

void ImprimeSuper(tSuper* s){
    printf("Nome: %s, Estoque Total: %.2f\n", s->nome, s->valor);
    for(int i=0; i<s->nfiliais; i++){
        ImprimeFilial(s->filial[i]);
    }
}