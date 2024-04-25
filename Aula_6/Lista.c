#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Cachorro.h"
#include "Gato.h"

typedef struct cel Cel;

struct lista{
    Cel* first;
    Cel* last;
};

struct cel{
    void* animal;
    int tipo;
    imprimir funcImprime;
    Cel* prox;
    Cel* ant;
};

Lista* CriaLista(){
    Lista* l = malloc(sizeof(Lista));
    l->first = l->last = NULL;

    return l;
}

void InsereAnimal(Lista* l, void* animal, int tipo, imprimir funcimp){
    Cel* cel = malloc(sizeof(Cel));

    cel->animal = animal;
    cel->tipo = tipo;
    cel->funcImprime = funcimp;

    cel->ant = l->last;
    cel->prox = NULL;

    if(l->first == NULL){
        l->first = cel;
    }

    if(l->last){
        l->last->prox = cel;
    }
    
    l->last = cel;
}

void RemoveAnimal(Lista* l, void* p){
    Cel* cel = NULL;
    for(cel = l->first; cel; cel = cel->prox){
        if(cel->animal == p){
            break;
        }
    }

    if(cel == NULL){
        return;
    }

    if(cel->prox == NULL){
        l->last = cel->ant;
    }
    if(cel->ant == NULL){
        l->first = cel->prox;
    }

    if(cel->ant){
        cel->ant->prox = cel->prox;
    }
    if(cel->prox){
        cel->prox->ant = cel->ant;
    }

    free(cel);
}

void LiberaLista(Lista* l){
    Cel* cel = l->first;
    Cel* aux = l->first;

    while(aux){
        cel = aux;
        aux = cel->prox;
        free(cel);
    }
    free(l);
}

int ExisteNaLista(Lista* l, void* p){
    Cel* c = l->first;
    while(c){
        if(c->animal == p){
            return 1;
            printf("achei");
        }
        c = c->prox;
    }

    return 0;
}

void ImprimeLista(Lista* l){
    Cel* c = l->first;
    while (c){
        c->funcImprime(c->animal);
        c = c->prox;
    }
}

float CalculaLista(Lista* l){
    float receita = 0;
    Cel* c = l->first;
    while (c){
        if(c->tipo == DOG){
            receita += 40;
            if(obtemCompCachorro(c->animal) == 1){ //1 = bravo
                receita += 5;
            }
        }
        else if(c->tipo == CAT){
            receita += 30;
            if(obtemCompGato(c->animal) == 1){ //1 = bravo
                receita += 5;
            }
        }
        c = c->prox;
    }
    return receita;
}