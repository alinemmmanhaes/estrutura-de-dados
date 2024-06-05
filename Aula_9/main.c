#include "lista.h"

int main(){
    Lista* l = criaLista();

    l = insere(l, 1);
    l = insere(l, 2);
    l = insere(l, 3);

    l = retira(l, 2);

    imprimeLista(l);

    l = liberaLista(l);

    return 0;
}