#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct cel Cel;

struct lista{
    Cel* first;
    Cel* last;
};

struct cel{
    void* animal;
    int tipo;
    Cel* prox;
    Cel* ant;
};

Lista* CriaLista(){
    Lista* l = malloc(sizeof(Lista));
    l->first = l->last = NULL;

    return l;
}

void InsereAnimal(Lista* l, void* animal, int tipo){
    Cel* cel = malloc(sizeof(Cel));

    cel->animal = animal;
    cel->tipo = tipo;

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
    for(cel = l->first; cel!=NULL; cel = cel->prox){
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

    if(cel->prox){
        cel->ant->prox = cel->prox;
    }
    if(cel->ant){
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
    Cel* cel = NULL;
    for(cel = l->first; cel!=NULL; cel = cel->prox){
        if(cel->animal == p){
            return 1;
        }
    }

    return 0;
}