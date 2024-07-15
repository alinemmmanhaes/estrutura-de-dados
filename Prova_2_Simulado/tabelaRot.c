#include <stdlib.h>
#include "tabelaRot.h"

struct tabela{
    int dest;
    int nextHop;
    Tabela* prox;
};

struct hash{
    Tabela** tab;
    int tam;
};

int funcaoHash(int dest, Hash* h){
    return dest%h->tam;
}

Hash* criaHash(int t){
    Hash* h = malloc(sizeof(Hash));

    h->tam = t;
    h->tab = calloc(t, sizeof(Tabela*));

    return h;
}

void insereTabela(int dest, int nxthop, Hash* hash){
    int index = funcaoHash(dest, hash);

    Tabela* aux = hash->tab[index];
    
    while(aux){
        if(aux->dest == dest) break;

        aux = aux->prox;
    }

    if(aux == NULL){
        Tabela* novo = malloc(sizeof(Tabela));
        novo->dest = dest;
        novo->nextHop = nxthop;
        novo->prox = hash->tab[index];
        hash->tab[index] = novo;
    }else{
        aux->nextHop = nxthop;
    }
}

int buscaRot(int dest, Hash* hash){
    int index = funcaoHash(dest, hash);

    Tabela* aux = hash->tab[index];
    
    while(aux){
        if(aux->dest == dest) return aux->nextHop;

        aux = aux->prox;
    }

    return -1;
}

void liberaHash(Hash* hash){
    for(int i=0; i<hash->tam; i++){
        Tabela* t = hash->tab[i], *aux;
        while(t){
            aux = t;
            t = t->prox;
            free(aux);
        }
    }
    free(hash->tab);
    free(hash);
}