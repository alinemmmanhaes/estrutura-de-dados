#include <stdio.h>
#include <stdlib.h>

int main(){
    int num1 = 2, num2 = 5, num3 = 6, num4 = 9;
    int* pont1, *pont2, *pont3, *pont4;

    pont1 = &num1;
    pont2 = &num2;
    pont3 = &num3;
    pont4 = &num4;

    printf("%d %d %d %d\n", num1, num2, num3, num4);

    *pont1 = 8;
    *pont2 = 4;
    *pont3 = 0;
    *pont4 = 1;

    printf("Modificando os apontados dos ponteiros...\n");
    printf("%d %d %d %d\n", num1, num2, num3, num4);

    return 0;
}