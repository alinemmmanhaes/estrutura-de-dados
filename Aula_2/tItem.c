#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tProd.h"
#include "tItem.h"

typedef struct tItem{
    int qtd;
    tProd* prod;
}tItem;

tItem* CriaItem(tProd* prod, int qtd){
    tItem* item = malloc(sizeof(tItem));
    item->prod = prod;
    item->qtd = qtd;

    return item;
}

void DesalocaItem(tItem* item){
    free(item);
}

void ImprimeItem(tItem* item){
    printf("\t   Item: ");
    ImprimeProduto(item->prod);
    printf("quantidade: %d\n", item->qtd);
}

tItem** LeItens(tProd** prod, int qtdprod, int qtditens){
    char nome[100];
    int qtd, flag = 0;
    tItem** itens = malloc(qtditens* sizeof(tItem*));
    for(int i=0; i<qtditens; i++){
        flag = 0;
        printf("Qual o nome do produto? ");
        scanf("%[^\n]%*c", nome);
        printf("Qual o quantidade do produto? ");
        scanf("%d%*c", &qtd);
        for(int j=0; j<qtdprod; j++){
            if(ComparaNome(prod[j], nome)){
                itens[i] = CriaItem(prod[j], qtd);
                flag = 1;
                break;
            }
        }
        if(!flag){
            printf("Produto não encontrado. Digite novamente\n");
            i--;
        }
    }

    return itens;
}

float ObtemValorItem(tItem* item){
    float valor = 0;
    valor = item->qtd * ObtemPrecoProd(item->prod);
    return valor;
}