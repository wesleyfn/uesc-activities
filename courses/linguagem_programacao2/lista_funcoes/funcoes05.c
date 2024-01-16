#include <stdio.h>
/*
Crie um programa que leia a base e o expoente e imprima baseexpoente.
Admita que o expoente e um valor inteiro (positivo, negativo ou zero).
Escreva uma função PotenciaInt, que utilize um for para controlar o
calculo. Não use a função power().
*/
int PotenciaInt(int, int);

int main(void)
{
    int base, exp;

    printf("Digite o valor da base: ");
    scanf("%d", &base);
    printf("Digite o valor do expoente: ");
    scanf("%d", &exp);
    printf("%d^(%d) = ", base, exp);

    if (exp < 0) printf("1/");
    printf("%d\n", PotenciaInt(base, exp));
    return 0;
}

int PotenciaInt(int base, int exp)
{
    int i, result;

    if (exp < 0) exp *= -1;
    result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}