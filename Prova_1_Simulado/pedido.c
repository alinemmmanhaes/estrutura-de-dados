#include <stdio.h>
#include <stdlib.h>
#include "pedido.h"
#include <string.h>

typedef struct cel Cel;

struct pedido{
    char* dono;
    Cel* prim;
    Cel* ult;
};

struct cel{
    TProduto* prod;
    Cel* prox;
};

TPedido* InicPedido (char* dono){
    TPedido* p = malloc(sizeof(TPedido));
    p->dono = strdup(dono);
    p->prim = p->ult = NULL;

    return p;
}

void IncluiProdutoPedido (TPedido* pedido, TProduto* prod){
    Cel* ce = pedido->prim;
    while(ce){
        if(strcmp(RetornaNome(ce->prod), RetornaNome(prod)) == 0){
            printf("Produto já existe no pedido\n");
            return;
        }
        ce = ce->prox;
    }

    Cel* c = malloc(sizeof(Cel));
    c->prod = prod;
    c->prox = NULL;

    if(!pedido->prim){
        pedido->prim = c;
    }

    if(pedido->ult){
        pedido->ult->prox = c;
    }
    pedido->ult = c;
}

void ImprimePedido (TPedido* pedido){
    printf("Pedido de %s:\n", pedido->dono);
    if(!pedido->prim){
        printf("Nao ha produtos neste pedido!\n");
        return;
    }

    Cel* c = pedido->prim;
    while(c){
        ImprimeIngredientes(c->prod);
        c = c->prox;
    }
}

void RetiraProdutoPedido (TPedido* pedido, char* prod){
    Cel* ant = NULL, *c = pedido->prim;
    while(c){
        if(strcmp(RetornaNome(c->prod), prod) == 0){
            break;
        }
        ant = c;
        c = c->prox;
    }

    if(!c){
        return;
    }

    if(pedido->prim == pedido->ult){
        pedido->prim = pedido->ult = NULL;
    }
    else if(c == pedido->prim){
        pedido->prim = c->prox;
    }
    else if(c == pedido->ult){
        pedido->ult = ant;
        ant->prox = NULL;
    }
    else{
        ant->prox = c->prox;
    }
    free(c);
}

int EnviaPedido (TPedido* pedido, int restricao_calorica, char* restricao_alimentar){
    int soma = 0;
    Cel* c = pedido->prim;
    while(c){
        soma += Calorias(c->prod);
        c = c->prox;
    }
    if(soma > restricao_calorica){
        printf("Pedido não Enviado! Pedido tem mais calorias do que a restricao, tente retirar algum produto!\n");
        return 0;
    }

    c = pedido->prim;
    while(c){
        if(VerificaIngrediente(c->prod, restricao_alimentar)){
            printf("Pedido não Enviado! Restricao alimentar no produto: %s\n", restricao_alimentar);
            return 0;
        }
        c = c->prox;
    }

    Cel* aux = pedido->prim;
    c = pedido->prim;
    while(c){
        aux = c;
        c = c->prox;
        free(aux);
    }
    free(pedido->dono);
    free(pedido);
    return 1;
}