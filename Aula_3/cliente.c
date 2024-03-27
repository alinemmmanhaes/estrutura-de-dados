#include <stdlib.h>
#include "matriz.h"

int main(){
    int l1, l2, c1, c2, elem;
    printf("Vamos criar duas matrizes!\n");

    printf("Quantas linhas na matriz 1? ");
    scanf("%d", &l1);
    printf("Quantas colunas na matriz 1? ");
    scanf("%d", &c1);
    Matriz* mat1 = inicializaMatriz(l1, c1);

    printf("Quantas linhas na matriz 2? ");
    scanf("%d", &l2);
    printf("Quantas colunas na matriz 2? ");
    scanf("%d", &c2);
    Matriz* mat2 = inicializaMatriz(l2, c2);

    printf("Lendo matriz 1! Digite seus elementos: \n");
    for(int i=0; i<l1; i++){
        for(int j=0; j<c1; j++){
            scanf("%d", &elem);
            modificaElemento(mat1, i, j, elem);
        }
    }

    printf("Lendo matriz 2! Digite seus elementos: \n");
    for(int i=0; i<l2; i++){
        for(int j=0; j<c2; j++){
            scanf("%d", &elem);
            modificaElemento(mat2, i, j, elem);
        }
    }

    printf("Matriz 1:\n");
    imprimeMatriz(mat1);

    printf("Matriz 2:\n");
    imprimeMatriz(mat2);

    Matriz* trans1 = transposta(mat1);
    Matriz* trans2 = transposta(mat2);

    printf("Transposta da Matriz 1:\n");
    imprimeMatriz(trans1);

    printf("Transposta da Matriz 2:\n");
    imprimeMatriz(trans2);

    Matriz* mult1 = multiplicacao(mat1, mat2);

    printf("Multiplicação da Matriz 1 com a Matriz 2:\n");
    imprimeMatriz(mult1);

    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(trans1);
    destroiMatriz(trans2);
    destroiMatriz(mult1);

    return 0;
}