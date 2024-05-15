#include <stdio.h>
#include <stdlib.h>
#include "PilhaDupla.h"
#include "PilhaN.h"

int main(){
    //PILHA DUPLA
    /*
    PilhaDupla* pilhas = CriaPilhaDupla();
    int a = 1, b = 2, c = 3, d = 4, w = 5, x = 6, y = 7, z = 8;

    PushPilha(pilhas, 1, &a);
    PushPilha(pilhas, 1, &b);
    PushPilha(pilhas, 1, &c);
    PushPilha(pilhas, 1, &d);

    PushPilha(pilhas, 2, &w);
    PushPilha(pilhas, 2, &x);
    PushPilha(pilhas, 2, &y);
    PushPilha(pilhas, 2, &z);

    ImprimePilha(pilhas, 1);
    ImprimePilha(pilhas, 2);

    PopPilha(pilhas, 1);
    PopPilha(pilhas, 2);

    ImprimePilha(pilhas, 1);
    ImprimePilha(pilhas, 2);

    LiberaPilha(pilhas);
    */

    //PILHA MULTIPLA
    PilhaN* pilhas = CriaPilhaN();
    int a = 1, b = 2, c = 3, d = 4, w = 5, x = 6, y = 7, z = 8;

    PushPilhaN(pilhas, 1, &a);
    PushPilhaN(pilhas, 1, &b);
    PushPilhaN(pilhas, 2, &c);
    PushPilhaN(pilhas, 2, &d);

    PushPilhaN(pilhas, 4, &w);
    PushPilhaN(pilhas, 4, &x);
    PushPilhaN(pilhas, 9, &y);
    PushPilhaN(pilhas, 9, &z);

    ImprimePilhaN(pilhas, 1);
    ImprimePilhaN(pilhas, 2);
    ImprimePilhaN(pilhas, 4);
    ImprimePilhaN(pilhas, 9);

    PopPilhaN(pilhas, 1);
    PopPilhaN(pilhas, 2);
    PopPilhaN(pilhas, 4);
    PopPilhaN(pilhas, 9);

    ImprimePilhaN(pilhas, 1);
    ImprimePilhaN(pilhas, 2);
    ImprimePilhaN(pilhas, 4);
    ImprimePilhaN(pilhas, 9);

    LiberaPilhaN(pilhas);

    return 0;
}