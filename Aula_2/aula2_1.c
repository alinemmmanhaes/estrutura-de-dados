#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tSuper.h"

int main(){
    int nprod, valorp;
    char nomep[100], nomes[100];

    printf("CADASTRAR PRODUTOS\nQuantos produtos serão cadastrados? ");
    scanf("%d%*c", &nprod);
    tProd** prods = malloc(nprod*sizeof(tProd*));
    for(int i=0; i<nprod; i++){
        printf("Qual o nome do produto? ");
        scanf("%[^\n]%*c", nomep);
        printf("Qual o valor do produto? ");
        scanf("%d%*c", &valorp);
        prods[i] = CriaProduto(nomep, valorp);
    }

    printf("CADASTRAR SUPERMERCADO\nQual o nome do supermercado? ");
    scanf("%[^\n]%*c", nomes);
    tSuper* super = CriaSuper(nomes, prods, nprod);

    ImprimeSuper(super);

    for(int i=0; i<nprod; i++){
        DesalocaProduto(prods[i]);
    }
    free(prods);
    DesalocaSuper(super);

    return 0;
}