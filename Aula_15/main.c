#include "hash.h"

int main(){
    Hash* hash = criaHash(17);
    FILE* file = fopen("input.txt", "r");

    char palavra[501];
    while(fscanf(file, "%s", palavra) == 1){
        insereHash(hash, palavra);
    }

    imprime(hash);
    printf("\n\n");
    imprimeOrdenado(hash);

    fclose(file);
    liberaHash(hash);
}