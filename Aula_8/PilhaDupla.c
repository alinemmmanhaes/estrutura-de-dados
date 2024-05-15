#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"

typedef struct{
    int Topo, Base;
}IndicePilha;

struct pilhadupla{
    TipoItem* Item[MaxTam];
    IndicePilha Pilha1, Pilha2;
};

PilhaDupla* CriaPilhaDupla(){
    PilhaDupla* P = malloc(sizeof(PilhaDupla));
    P->Pilha1.Base = 0;
    P->Pilha1.Topo = -1; /* cresce para a direita */
    P->Pilha2.Base = MaxTam -1;
    P->Pilha2.Topo = MaxTam; /* cresce para a esquerda */

    return P;
}

void PushPilha(PilhaDupla* p, int num, TipoItem* item){
    if(num == 1){
        if(p->Pilha1.Topo != p->Pilha2.Topo-1){
            p->Pilha1.Topo++;
            p->Item[p->Pilha1.Topo] = item;
        }
        else{
            printf("Pilha Cheia\n");
        }
    }
    else if(num == 2){
        if(p->Pilha1.Topo != p->Pilha2.Topo-1){
            p->Pilha2.Topo--;
            p->Item[p->Pilha2.Topo] = item;
        }
        else{
            printf("Pilha Cheia\n");
        }
    }
}

void PopPilha(PilhaDupla* p, int num){
    if(num == 1){
        if(p->Pilha1.Topo >= p->Pilha1.Base){
            p->Pilha1.Topo--;
        }
        else{
            printf("Pilha Vazia\n");
        }
    }
    else if(num == 2){
        if(p->Pilha2.Topo <= p->Pilha2.Base){
            p->Pilha2.Topo++;
        }
        else{
            printf("Pilha Vazia\n");
        }
    }
}

void ImprimePilha(PilhaDupla* p, int num){
    printf("Pilha %d:\n", num);
    if(num == 1){
        for(int i=p->Pilha1.Base; i <= p->Pilha1.Topo; i++){
            printf("%d ", *(p->Item[i]));
        }
    }
    else if(num == 2){
        for(int i=p->Pilha2.Base; i >= p->Pilha2.Topo; i--){
            printf("%d ", *(p->Item[i]));
        }
    }
    printf("\n\n");
}

void LiberaPilha(PilhaDupla* p){
    free(p);
}