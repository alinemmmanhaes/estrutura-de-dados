#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cel{
    Palavra* palavra;
    Cel* prox;
};

struct hash{
    Cel** tab;
    int tam;
    int total;
};

int hashFunction(char* palavra, int tam){
    char c = palavra[0];
    int total = 0, i=0;
    while(c != '\0'){
        c = palavra[i];
        total += palavra[i];
        i++;
    }

    return total % tam;
}

Hash* criaHash(int tam){
    Hash* h = malloc(sizeof(Hash));
    h->tam = tam;
    h->total = 0;
    h->tab = calloc(h->tam, sizeof(Cel*));
    return h;
}

void insereHash(Hash* hash, char* palavra){
    int index = hashFunction(palavra, hash->tam);

    Cel* aux = hash->tab[index];
    while(aux){
        if(strcmp(palavra, retornaPalavra(aux->palavra)) == 0) break;
        aux = aux->prox;
    }
    
    if(aux == NULL){
        Cel* cel = malloc(sizeof(Cel));
        cel->palavra = criaPalavra(palavra);

        cel->prox = hash->tab[index];
        hash->tab[index] = cel;
        hash->total++;
    }else{
        incrementaFreq(aux->palavra);
    }
}

void liberaHash(Hash* hash){
    for(int i=0; i<hash->tam; i++){
        Cel* cel = hash->tab[i], *aux = NULL;
        while(cel){
            aux = cel;
            cel = cel->prox;
            liberaPalavra(aux->palavra);
            free(aux);
        }
    }
    free(hash->tab);
    free(hash);
}

void imprime(Hash* hash){
    for(int i=0; i<hash->tam; i++){
        for(Cel* cel = hash->tab[i]; cel; cel = cel->prox){
            imprimePalavra(cel->palavra);
        }
    }
}

void imprimeOrdenado(Hash* hash){
    Palavra* palavras[hash->total];

    int j = 0;
    for(int i=0; i<hash->tam; i++){
        for(Cel* cel = hash->tab[i]; cel; cel = cel->prox){
            palavras[j] = cel->palavra;
            j++;
        }
    }

    qsort(palavras, hash->total, sizeof(Palavra*), comparaPalavras);

    for(int i=0; i<hash->total; i++){
        imprimePalavra(palavras[i]);
    }
}