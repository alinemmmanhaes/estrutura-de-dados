#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

typedef struct matriz{
    int** mat;
    int linhas;
    int colunas;
}Matriz;

Matriz* inicializaMatriz (int nlinhas, int ncolunas){
    Matriz* mat = malloc(sizeof(Matriz));
    mat->linhas = nlinhas;
    mat->colunas = ncolunas;
    mat->mat = malloc(mat->linhas* sizeof(int*));
    for(int i=0; i<mat->linhas; i++){
        mat->mat[i] = calloc(mat->colunas, sizeof(int));
    }

    return mat;
}

void modificaElemento (Matriz* mat, int linha, int coluna, int elem){
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz* mat, int linha, int coluna){
    return mat->mat[linha][coluna];
}

int recuperaNColunas (Matriz* mat){
    return mat->colunas;
}

int recuperaNLinhas (Matriz* mat){
    return mat->linhas;
}

Matriz* transposta (Matriz* mat){
    Matriz* mat2 = inicializaMatriz(mat->colunas, mat->linhas);
    for(int i=0; i<mat2->linhas; i++){
        for(int j=0; j<mat2->colunas; j++){
            modificaElemento(mat2, i, j, recuperaElemento(mat, j, i));
        }
    }
    return mat2;
}

Matriz* multiplicacao (Matriz* mat1, Matriz* mat2){
    Matriz* mat = inicializaMatriz(mat1->linhas, mat2->colunas);
    int soma;
    for(int i=0; i<mat->linhas; i++){
        for(int j=0; j<mat->colunas; j++){
            soma = 0;
            for(int k=0; k<mat2->linhas; k++){
                soma+= recuperaElemento(mat1, i, k)*recuperaElemento(mat2, k, j);
            }
            modificaElemento(mat, i, j, soma);
        }
    }
    return mat;
}

void imprimeMatriz(Matriz* mat){
    for(int i=0; i<mat->linhas; i++){
        imprimeLinhas(mat, i);
    }
}

void imprimeLinhas (Matriz* mat, int indice){
    for(int i=0; i<mat->colunas; i++){
        printf("%d ", recuperaElemento(mat, indice, i));
    }
    printf("\n");
}

void destroiMatriz (Matriz* mat){
    for(int i=0; i<mat->linhas; i++){
        free(mat->mat[i]);
    }
    free(mat->mat);
    free(mat);
}