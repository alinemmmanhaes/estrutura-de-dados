#include "search.h"
#include <stdio.h>

long int buscaBinaria(long int* vet, long int n, long int x){
    long int inicio = 0, fim = n-1, meio;

    while(inicio <= fim){
        meio = (fim + inicio)/2;
        if(x == vet[meio]){
            return meio;
        }
        else if(vet[meio] > x){
            fim = meio - 1;
        }
        else if(vet[meio] < x){
            inicio = meio + 1;
        }
    }
    return -1;
}

long int buscaLinear(long int* vet, long int n, long int x){
    for(long int i=0; i<n; i++){
        if(x == vet[i]){
            return i;
        }
    }
    return -1;
}