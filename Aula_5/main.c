#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "lista.h"

int main(){
    Cel* l = CriaLista();

    Produto* arroz = CriaProd(4, "arroz", 10);
    Produto* banana = CriaProd(3, "banana", 7);
    Produto* chocolate = CriaProd(2, "chocolate", 15);
    Produto* feijao = CriaProd(1, "feijao", 9);

    l = InsereProd(l, arroz);
    l = InsereProd(l, banana);
    l = InsereProd(l, chocolate);
    l = InsereProd(l, feijao);

    ImprimeLista(l);

    //l = RetiraProd(l, 1);
    //l = RetiraProd(l, 2);
    //l = RetiraProd(l, 3);
    l = RetiraProd(l, 4);
    ImprimeLista(l);

    LiberaLista(l);
    LiberaProd(arroz);
    LiberaProd(banana);
    LiberaProd(chocolate);
    LiberaProd(feijao);

    return 0;
}