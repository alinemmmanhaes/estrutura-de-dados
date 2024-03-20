#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <tItem.h>
#include <tEstoque.h>

typedef struct tEstoque{
    float valor;
    int nitens;
    tItem** item;
}tEstoque;

tEstoque* CriaEstoque(tProd** prod, int nprod){
    tEstoque* e = malloc(sizeof(tEstoque));
    while(1){
        printf("Quantos tipos de produto? ");
        scanf("%d%*c", &e->nitens);
        if(e->nitens <= nprod){
            break;
        }
    }
    e->item = LeItens(prod, nprod, e->nitens);
    e->valor = CalculaValor(e);
    return e;
}

float CalculaValor(tEstoque* estoque){
    float total = 0;
    for(int i=0; i<estoque->nitens; i++){
        total += ObtemValorItem(estoque->item[i]);
    }
    return total;
}

void DesalocaEstoque(tEstoque* estoque){
    for(int i=0; i<estoque->nitens; i++){
        DesalocaItem(estoque->item[i]);
    }
    free(estoque->item);
    free(estoque);
}

void ImprimeEstoque(tEstoque* estoque){
    printf("\tEstoque: %.2f\n", estoque->valor);
    for(int i=0; i<estoque->nitens; i++){
        ImprimeItem(estoque->item[i]);
    }
}