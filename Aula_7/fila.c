#include "fila.h"
#include <string.h>
#include <stdlib.h>

typedef struct cel Cel;

struct fila{
    Cel* prim;
    Cel* ult;
};

struct cel{
    Amostra* amostra;
    Cel* prox;
};

Fila* CriaFila(){
    Fila* f = malloc(sizeof(Fila));
    f->prim = f->ult = NULL;
    return f;
}

void insereAmostra(Fila* fila, Amostra* a){
    Cel* c = malloc(sizeof(Cel));
    c->amostra = a;
    c->prox = NULL;

    if(fila->prim == NULL){
        fila->prim = c;
    }

    if(fila->ult){
        fila->ult->prox = c;
    }
    fila->ult = c;
}

void inserePreferencial(Fila* fila, Amostra* a){
    Cel* c = malloc(sizeof(Cel));
    c->amostra = a;
    c->prox = fila->prim;

    fila->prim = c;

    if(fila->ult == NULL){
        fila->ult = c;
    }
}

Amostra* removeAmostra(Fila* fila){
    Cel* c = fila->prim;

    if(fila->prim){
        fila->prim = fila->prim->prox;
        Amostra* a = c->amostra;
        free(c);
        return a;
    }
    return NULL;
}

void imprimefila(Fila* fila){
    Cel* c = fila->prim;
    while(c){
        imprimeAmostra(c->amostra);
        c = c->prox;
    }
}

void liberafila(Fila* fila){
    Cel* c, *aux = fila->prim;
    while(aux){
        c = aux;
        aux = aux->prox;
        liberaAmostra(c->amostra);
        free(c);
    }
    free(fila);
}

int temAmostraFila(Fila* f){
    if(f->prim){
        return 1;
    }
    return 0;
}