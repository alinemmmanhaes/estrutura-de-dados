#include "BanhoTosa.h"
#include "Lista.h"
#include <string.h>
#include <stdlib.h>

struct banhotosa{
    char* nome;
    Lista* agressivo;
    Lista* manso;
};

BanhoTosa* inicBanhoTosa(char* nome){
    BanhoTosa* loja = malloc(sizeof(BanhoTosa));
    loja->agressivo = CriaLista();
    loja->manso = CriaLista();
    loja->nome = strdup(nome);

    return loja;
}

void cadastraCachorro(BanhoTosa* loja, Cachorro* dog){
    if(obtemCompCachorro(dog) == MANSO){
        InsereAnimal(loja->manso, (void*)dog, DOG, ImprimeCachorro);
    }
    if(obtemCompCachorro(dog) == BRAVO){
        InsereAnimal(loja->agressivo, (void*)dog, DOG, ImprimeCachorro);
    }
}

void cadastraGato(BanhoTosa* loja, Gato* cat){
    if(obtemCompGato(cat) == MANSO){
        InsereAnimal(loja->manso, (void*)cat, CAT, ImprimeGato);
    }
    if(obtemCompGato(cat) == BRAVO){
        InsereAnimal(loja->agressivo, (void*)cat, CAT, ImprimeGato);
    }
}

void atualizaSituacaoGato(BanhoTosa* loja, Gato* cat){
    int tipo = obtemCompGato(cat);

    if(tipo == MANSO){
        if(ExisteNaLista(loja->agressivo, (void*)cat)){
            RemoveAnimal(loja->agressivo, (void*)cat);
            InsereAnimal(loja->manso, (void*)cat, CAT, ImprimeGato);
        }
    }
    else if(tipo == BRAVO){
        if(ExisteNaLista(loja->manso, (void*)cat)){
            RemoveAnimal(loja->manso, (void*)cat);
            InsereAnimal(loja->agressivo, (void*)cat, CAT, ImprimeGato);
        }
    }
}

void atualizaSituacaoCachorro(BanhoTosa* loja, Cachorro* dog){
    int tipo = obtemCompCachorro(dog);
    printf("oi ");
    if(tipo == MANSO){
        if(ExisteNaLista(loja->agressivo, (void*)dog)){
            RemoveAnimal(loja->agressivo, (void*)dog);
            InsereAnimal(loja->manso, (void*)dog, DOG, ImprimeCachorro);
        }
    }
    else if(tipo == BRAVO){
        if(ExisteNaLista(loja->manso, (void*)dog)){
            RemoveAnimal(loja->manso, (void*)dog);
            InsereAnimal(loja->agressivo, (void*)dog, DOG, ImprimeCachorro);
        }
    }
}

void imprimeBanhoTosa(BanhoTosa* loja){
    printf("Loja %s\n", loja->nome);
    printf("- Lista de animais Mansos:\n");
    ImprimeLista(loja->manso);
    printf("- Lista de animais Agressivos:\n");
    ImprimeLista(loja->agressivo);
    printf("\n");
}

float calculaReceita(BanhoTosa* loja){
    float receita = 0;
    receita += CalculaLista(loja->manso);
    receita += CalculaLista(loja->agressivo);
    return receita;
}

void liberaBanhoTosa(BanhoTosa* loja){
    LiberaLista(loja->manso);
    LiberaLista(loja->agressivo);
    free(loja->nome);
    free(loja);
}