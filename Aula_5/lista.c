#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "lista.h"

typedef Cel Lista;

struct cel{
    Produto* prod;
    Cel* ant, *prox;
};

Lista* CriaLista(){
    Lista* l = NULL;

    return l;
}

Lista* InsereProd(Lista* l, Produto* p){
    Cel* c = malloc(sizeof(Cel));
    c->prod = p;
    c->prox = l;
    c->ant = NULL;

    if(l == NULL){
        return c;
    }
    c->prox->ant = c;
    return c;
}

Lista* RetiraProd(Lista* l, int cod){
    Cel* c = l;
    for(c = l; c!=NULL; c = c->prox){
        if(ObtemCodigo(c->prod) == cod){
            break;
        }
    }

    if(c == NULL){
        return l;
    }

    if(c != l){
        c->ant->prox = c->prox;
    }
    else{
        l = l->prox;
    }
    if(c->prox){
        c->prox->ant = c->ant;
    }
    free(c);
    return l;
}

void ImprimeLista(Lista* l){
    Cel* c = l;
    printf("Lista:\n");
    while(c){
        ImprimeProd(c->prod);
        c = c->prox;
    }
}

void LiberaLista(Lista* l){
    Cel* aux = l;
    while(aux){
        l = aux;
        aux = l->prox;
        free(l);
    }
}