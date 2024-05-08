#include "posto.h"
#include "fila.h"
#include <string.h>
#include <stdlib.h>

struct posto{
    char* nome;
    Fila* np;
    Fila* posi;
    Fila* neg;
};

Posto* inicPosto(char* nome){
    Posto* p = malloc(sizeof(Posto));
    p->nome = strdup(nome);
    p->np = CriaFila();
    p->neg = CriaFila();
    p->posi = CriaFila();;
    return p;
}

void imprimePosto(Posto* posto){
    printf("Dados do Posto: %s\n", posto->nome);

    printf("Amostras não processadas\n");
    imprimefila(posto->np);

    printf("\nAmostras com resultados positivos\n");
    imprimefila(posto->posi);

    printf("\nAmostra com resultados negativos\n");
    imprimefila(posto->neg);
}

void realizaColeta(Posto* posto, char* pessoa, int idade){
    Amostra* a = inicAmostra(pessoa, idade);
    if(idade >= 60){
        inserePreferencial(posto->np, a);
    }
    else{
        insereAmostra(posto->np, a);
    }
}

void processaLoteAmostras(Posto* posto){
    while(temAmostraFila(posto->np)){
        Amostra* amostra = removeAmostra(posto->np);
        if(retornaCargaViral(amostra) > LIMITE_CARGA_VIRAL){
            registraResultado(amostra, POSITIVO);
            insereAmostra(posto->posi, amostra);
        }
        else{
            registraResultado(amostra, NEGATIVO);
            insereAmostra(posto->neg, amostra);
        }
    }
}

void liberaPosto(Posto* posto){
    free(posto->nome);
    liberafila(posto->np);
    liberafila(posto->posi);
    liberafila(posto->neg);
    free(posto);
}