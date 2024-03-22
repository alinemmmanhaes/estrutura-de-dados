#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

void calc_esfera(float r, float* area, float* volume){
    *area = 4*PI*r*r;
    *volume = (4*PI*r*r*r)/3;
}

int raizes(float a, float b, float c, float* x1, float* x2){
    int delta = 0;
    delta = (b*b) - (4*a*c);

    if(delta < 0){
        return 0;
    }

    *x1 = ((-1*b) + sqrt(delta))/(2*a);
    *x2 = ((-1*b) - sqrt(delta))/(2*a);
    if(delta == 0){
        return 1;
    }

    return 2;
}

int pares (int n, int* vet){
    int qtd = 0;
    for(int i=0; i<n; i++){
        if(vet[i]%2 == 0){
            qtd++;
        }
    }
    return qtd;
}

void inverte (int n, int* vet){
    int aux = 0;
    for(int i=0, j=n-1; i<n/2; i++, j--){
        aux = vet[i];
        vet[i] = vet[j];
        vet[j] = aux;
    }
}

double avalia (double* poli, int grau, double x){
    double result  = 0;
    for(int i=0; i<grau + 1; i++){
        result += poli[i] * pow(x, i);
    }
    return result;
}

/*int main(){
    float raio = 0, area = 0, volume = 0;
    printf("Digite o raio: ");
    scanf("%f", &raio);
    calc_esfera(raio, &area, &volume);
    printf("Area: %.2f / Volume: %.2f\n", area, volume);

    return 0;
}*/

/*int main(){
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int resultado = 0;

    printf("Digite os coeficientes (a, b, c): ");
    scanf("%f %f %f", &a, &b, &c);

    resultado = raizes(a, b, c, &x1, &x2);
    if(resultado == 0){
        printf("Não há raízes!\n");
    }
    else if(resultado == 1){
        printf("Há uma raíz: %.2f\n", x1);
    }
    else if(resultado == 2){
        printf("Há duas raízes: %.2f e %.2f\n", x1, x2);
    }

    return 0;
}*/

/*int main(){
    int n = 0, par = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int* vet = malloc(n*sizeof(int));
    printf("Digite os números do vetor: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    par = pares(n, vet);
    if(par == 1){
        printf("O vetor tem %d número par\n", par);
    }
    else{
        printf("O vetor tem %d números pares\n", par);
    }

    free(vet);
}*/

/*int main(){
    int n = 0, par = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n);

    int* vet = malloc(n*sizeof(int));
    printf("Digite os números do vetor: ");
    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    inverte(n, vet);

    printf("Vetor invertido: ");
    for(int i=0; i<n; i++){
        printf("%d ", vet[i]);
    }

    free(vet);
}*/

/*int main(){
    int grau = 0;
    double x = 0, resultado = 0;
    printf("Digite o grau do polinômio: ");
    scanf("%d", &grau);

    double* vet = malloc((grau + 1)*sizeof(double));
    printf("Digite os coeficientes do polinômio: ");
    for(int i=0; i<grau + 1; i++){
        scanf("%lf", &vet[i]);
    }

    printf("Digite o valor do x: ");
    scanf("%lf", &x);

    resultado = avalia(vet, grau, x);
    printf("Resultado do polinômio: %.2lf", resultado);

    free(vet);
    return 0;
}*/