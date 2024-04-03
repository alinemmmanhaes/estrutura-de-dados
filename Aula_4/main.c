#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"
#include "lista.h"

int main(){
    Lista* l = CriaLista();

    Produto* arroz = CriaProd(1, "arroz", 10);
    Produto* banana = CriaProd(2, "banana", 7);
    Produto* chocolate = CriaProd(3, "chocolate", 15);
    Produto* feijao = CriaProd(4, "feijao", 9);

    /*InsereInicioProd(l, arroz);
    InsereInicioProd(l, banana);
    InsereInicioProd(l, chocolate);
    InsereInicioProd(l, feijao);*/

    InsereFimProd(l, arroz);
    InsereFimProd(l, banana);
    InsereFimProd(l, chocolate);
    InsereFimProd(l, feijao);

    ImprimeLista(l);

    RetiraProd(l, 1);
    ImprimeLista(l);

    LiberaLista(l);
    LiberaProd(arroz);
    LiberaProd(banana);
    LiberaProd(chocolate);
    LiberaProd(feijao);

    return 0;
}