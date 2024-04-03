#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "lista.h"

typedef struct cel Cel;

struct lista{
    Cel* first;
    Cel* last;
};

struct cel{
    Produto* prod;
    Cel* next;
};

Lista* CriaLista(){
    Lista* l = malloc(sizeof(Lista));
    l->first = l->last = NULL;

    return l;
}

void InsereInicioProd(Lista* l, Produto* p){
    Cel* c = malloc(sizeof(Cel));
    c->prod = p;
    c->next = l->first;

    if(!l->first){
        l->last = c;
    }

    l->first = c;
}

void InsereFimProd(Lista* l, Produto* p){
    Cel* c = malloc(sizeof(Cel));
    c->prod = p;
    c->next = NULL;

    if(!l->first){
        l->first = c;
    }
    if(l->last){
        l->last->next = c;  
    }
    l->last = c;
}

void RetiraProd(Lista* l, int cod){
    Cel* ant = NULL, *c = l->first;
    while(c){
        if(ObtemCodigo(c->prod) == cod){
            break;
        }
        ant = c;
        c = c->next;
    }

    if(!c){
        printf("Não há nenhum produto com esse código\n");
        return;
    }

    if(l->first == l->last){
        l->first = l->last = NULL;
    }
    else if(!ant){
        l->first = c->next;
    }
    else if(!c->next){
        l->last = ant;
        if(ant){
            ant->next = NULL;
        }
    }
    else if(ant && c->next){
        ant->next = c->next;
    }
    free(c);
}

void ImprimeLista(Lista* l){
    Cel* c = l->first;
    printf("Lista:\n");
    while(c){
        ImprimeProd(c->prod);
        c = c->next;
    }
}

void LiberaLista(Lista* l){
    Cel* c = l->first;
    Cel* aux = l->first;
    while(aux){
        c = aux;
        aux = c->next;
        free(c);
    }
    free(l);
}