#include "tabelaRot.h"

#define tam 17

int main(){
    Hash* hash = criaHash(tam);

    insereTabela(260, 397, hash);
    insereTabela(22, 37, hash);
    insereTabela(26, 16, hash);
    insereTabela(499, 373, hash);
    insereTabela(134, 98, hash);

    FILE* file = fopen("input.txt", "r");
    int dest;
    while(fscanf(file, "%d", &dest) == 1){
        if(buscaRot(dest, hash) == -1){
            printf("Não há nextHop para essa destination\n");
        }else{
            printf("dest: %d, nextHop: %d\n", dest, buscaRot(dest, hash));
        }
    }

    liberaHash(hash);
    fclose(file);

    return 0;
}