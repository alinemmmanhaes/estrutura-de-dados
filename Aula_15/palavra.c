#include "palavra.h"
#include <stdlib.h>
#include <string.h>

struct palavra{
    char* word;
    int freq;
};

Palavra* criaPalavra(char* word){
    Palavra* p = malloc(sizeof(Palavra));
    p->word = strdup(word);
    p->freq = 1;

    return p;
}

char* retornaPalavra(Palavra* p){
    return p->word;
}

void incrementaFreq(Palavra* p){
    p->freq++;
}

void liberaPalavra(Palavra* p){
    free(p->word);
    free(p);
}

void imprimePalavra(Palavra* p){
    printf("%s frequencia %d\n", p->word, p->freq);
}

int comparaPalavras(const void* p1, const void* p2){
    Palavra* pal1 = (Palavra*) p1;
    Palavra* pal2 = (Palavra*) p2;
    return strcmp(pal1->word, pal2->word);
}