#include <stdio.h>
#include <stdlib.h>

int** inverte2 (int n, int* vet){
    int** pont = malloc(n*sizeof(int*));
    int indice = 0, menor = 0, *ptroca = 0;

    for(int i=0; i<n; i++){
        pont[i] = &vet[i];
    }

    for(int i=0; i<n; i++){
        menor = *pont[i];
        indice = i;
        for(int j=i; j<n; j++){
            if(*pont[j] < menor){
                menor = *pont[j];
                indice = j;
            }
        }
        ptroca = pont[indice];
        pont[indice] = pont[i];
        pont[i] = ptroca;
    }
    return pont;
}

int main(){
    int n=0;
    printf("Quantos números? ");
    scanf("%d", &n);

    int* vet = malloc(n*sizeof(int));

    printf("Digite os números: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    int** pont = inverte2(n, vet);

    for(int i=0; i<n; i++){
        printf("%d ", *pont[i]);
    }

    free(vet);
    free(pont);
    return 0;
}