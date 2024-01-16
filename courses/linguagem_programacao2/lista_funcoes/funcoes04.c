#include <stdio.h>
#include <math.h>
/*
Defina uma função Hipotenusa que calcule o comprimento da
hipotenusa de um triângulo retângulo, ao serem fornecidos os catetos.
Use a função em um programa para determinar o comprimento da
hipotenusa onde o comprimento dos catetos são lidos pelo programa. A
função deve receber dois argumentos float e retornar um valor float.
*/
float hipotenusa(float, float);

int main(void)
{
    float hip, cat1, cat2;

    printf("Digite o valor do 1o cateto: ");
    scanf("%f", &cat1);
    printf("Digite o valor do 2o cateto: ");
    scanf("%f", &cat2);

    hip = hipotenusa(cat1, cat2);
    printf("Hipotenusa: %f\n", hip);
    return 0;
}

float hipotenusa(float c1, float c2)
{
    return sqrt(c1*c1+c2*c2);
}