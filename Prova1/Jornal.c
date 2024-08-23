//
//  Jornal.c
//  Prova1ED
//
//  Created by Aline Mendonça Mayerhofer Manhães on 22/05/22.
//

#include "Jornal.h"
#include "Autor.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cel Cel;

struct jornal{
    char* nome;
    Cel* prim;
    Cel* ult;
};

struct cel{
    Noticia* noticia;
    Cel* prox, *ant;
    time_t hora_post;
};

Jornal* criaJornal(char* nome){
    Jornal* j = malloc(sizeof(Jornal));
    j->prim = j->ult = NULL;
    j->nome = strdup(nome);

    return j;
}

void insereNoticia(Jornal* j, Noticia* news){
    Cel* c = malloc(sizeof(Cel));
    c->noticia = news;
    c->ant = j->ult;
    c->prox = NULL;
    c->hora_post = time(NULL);

    if(!j->prim){
        j->prim = c;
    }

    if(j->ult){
        j->ult->prox = c;
    }
    j->ult = c;

    if(difftime(c->hora_post, retornaHora(c->noticia)) <= TEMPO_PREMIACAO){
        premiaAutor(retornaAutor(c->noticia));
    }
}

void removeNoticiasVelhas(Jornal* j){
    Cel* c = j->prim;
    while(c){
        if(difftime(time(NULL), retornaHora(c->noticia)) >= TEMPO_NOTICIA_VELHA){
            if(j->prim == c){
                j->prim = c->prox;
            }
            if(j->ult == c){
                j->ult = c->ant;
            }
            if(c->prox){
                c->prox->ant = c->ant;
            }
            if(c->ant){
                c->ant->prox = c->prox;
            }

            liberaNoticia(c->noticia);
            Cel* aux = c;
            c = c->prox;
            free(aux);
        }
        else{
            c = c->prox;
        }
    }
}

void imprimeNoticiasJornal(Jornal* j){
    printf("Notícias do Jornal %s", j->nome);
    Cel* c =j->prim;
    while(c){
        imprimeNoticia(c->noticia);
        printf("\n***** Hora de Publicação: %s", ctime(&c->hora_post));
        c = c->prox;
    }
}

void imprimeNoticiasAutoresPremiados(Jornal* j){
    Cel* c =j->prim;
    while(c){
        if(ehPremiado(retornaAutor(c->noticia))){
            imprimeNoticia(c->noticia);
            printf("\n***** Hora de Publicação: %s", ctime(&c->hora_post));
        }
        c = c->prox;
    }
}

int retornaNumeroNoticias(Jornal* j){
    int total = 0;
    Cel* c =j->prim;
    while(c){
        total++;
        c = c->prox;
    }
    return total;
}

void liberaJornal(Jornal* j){
    Cel* c =j->prim, *aux = j->prim;
    while(c){
        aux = c;
        c = c->prox;
        liberaNoticia(aux->noticia);
        free(aux);
    }
    free(j->nome);
    free(j);
}