#include "sort.h"
#include <stdio.h>
#include "search.h"
#include <stdlib.h>

void imprimeVetor(long int* vet, long int n){
    for(long int i=0; i<n; i++){
        printf("%ld ", vet[i]);
    }
    printf("\n");
}

int main(){
    long int n = 100000;
    long int vet[n];
    for(long int i=0; i<n; i++){
        vet[i] = rand() % 100;
    }

    //printf("Vetor original: \n");
    //imprimeVetor(vet, n);

    quickSort(vet, n);

    imprimeVetor(vet, n);

    long int indice = buscaBinaria(vet, n, 5);
    printf("Indice de 5 no vetor: %ld\n", indice);

    return 0;
}