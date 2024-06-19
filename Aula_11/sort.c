#include "sort.h"
#include <stdio.h>

void bubbleSort(long int* vet, long int n){
    long int menor, indice;
    for(long int i=0; i<n; i++){
        menor = vet[i];
        indice = i;
        for(long int j=i+1; j<n; j++){
            if(vet[j] < menor){
                menor = vet[j];
                indice = j;
            }
        }
        vet[indice] = vet[i];
        vet[i] = menor;
    }

    // long int menor;
    // for(long int i=0; i<n; i++){
    //     for(long int j=i+1; j<n; j++){
    //         if(vet[j] < vet[i]){
    //             menor = vet[j];
    //             vet[j] = vet[i];
    //             vet[i] = menor;
    //         }
    //     }
    // }
}

void quickSort(long int* vet, long int n){
    if(n<=1) return;
    long int x = vet[0], a = 1, b = n-1;
    do{
        while(a<n && vet[a]<=x) a++;
        while(vet[b]>x) b--;
        if(a<b){
            long int temp = vet[a];
            vet[a] = vet[b];
            vet[b] = temp;
            a++; b--;
        }

    }while(a <= b);

    vet[0] = vet[b];
    vet[b] = x;

    quickSort(vet, b);
    quickSort(&vet[a], n-a);
}