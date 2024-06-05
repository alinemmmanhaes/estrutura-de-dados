#include "lista.h"
#include <stdlib.h>

struct cel{
    Cel* prox;
    int num;
};

Lista* criaLista(){
    Lista* l = NULL;

    return l;
}

Lista* insere(Lista* l, int i){
    if(l == NULL){
        Cel* c = malloc(sizeof(Cel));
        c->num = i;
        c->prox = NULL;
        return c;
    }
    
    l->prox = insere(l->prox, i);
    return l;
}

Lista* retira(Lista* l, int cod){
    if(l!=NULL){
        if(l->num == cod){
            Cel* t = l;
            l = l->prox;
            free(t);
        }
        else{
            l->prox = retira(l->prox, cod);
        }
    }
    return l;
}

void imprimeLista(Lista* l){
    if(l!=NULL){
        printf("%d\n", l->num);

        imprimeLista(l->prox);
    }
}

Lista* liberaLista(Lista* l){
    if(l!=NULL){
        Cel* t = l;
        l = l->prox;
        free(t);
        return liberaLista(l);
    }
    return NULL;
}