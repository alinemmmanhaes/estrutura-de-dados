#include <stdio.h>
#include <stdlib.h>
#include "PilhaN.h"

typedef struct{
    int Topo, Base;
}IndicePilha;

struct pilhan{
    TipoItem* Item[MaxTam];
    IndicePilha Pilha[N];
};

PilhaN* CriaPilhaN(){
    PilhaN* p = malloc(sizeof(PilhaN));
    int escala = MaxTam/N, base = 0;
    for(int i=0; i<N; i++){
        p->Pilha[i].Base = base;
        p->Pilha[i].Topo = p->Pilha[i].Base;
        base += escala;
    }

    return p;
}

void PushPilhaN(PilhaN* p, int num, TipoItem* item){
    if(num != N-1){
        if(p->Pilha[num].Topo != p->Pilha[num+1].Base){
            p->Item[p->Pilha[num].Topo] = item;
            p->Pilha[num].Topo++;
        }
        else{
            printf("Pilha Cheia\n");
        }
    }
    else{
        if(p->Pilha[num].Topo != MaxTam){
            p->Item[p->Pilha[num].Topo] = item;
            p->Pilha[num].Topo++;
        }
        else{
            printf("Pilha Cheia\n");
        }
    }
}

void PopPilhaN(PilhaN* p, int num){
    if(p->Pilha[num].Topo > p->Pilha[num].Base){
        p->Pilha[num].Topo--;
    }
    else{
        printf("Pilha Vazia\n");
    }
}

void ImprimePilhaN(PilhaN* p, int num){
    printf("Pilha %d:\n", num);
    for(int i=p->Pilha[num].Base; i < p->Pilha[num].Topo; i++){
        printf("%d ", *(p->Item[i]));
    }
    printf("\n\n");
}

void LiberaPilhaN(PilhaN* p){
    free(p);
}