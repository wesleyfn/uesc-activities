#include <stdio.h>
#include <stdlib.h>
/*
Crie uma estrutura para representar um ponto do espaço (x; y; z). Escreva um programa que
utilize a estrutura para verificar se o ponto pertence ao plano Ax + By + Cz = D onde os
coeficientes A;B;C; e D são digitados pelo usuário.
*/

typedef struct{
    float x, y, z;
} TPonto;

int main(void)
{
    TPonto ponto;
    float a, b, c, d, total;

    puts("Determine o ponto:");
    printf("Digite o valor de x: ");
    scanf("%f", &ponto.x);
    printf("Digite o valor de y: ");
    scanf("%f", &ponto.y);
    printf("Digite o valor de z: ");
    scanf("%f", &ponto.z);

    puts("Determine os coeficientes:");
    printf("Digite o valor de a: ");
    scanf("%f", &a);
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);
    printf("Digite o valor de d: ");
    scanf("%f", &d);

    total = a*ponto.x + b*ponto.y + c*ponto.z - d;
    printf("%.2f\n", total);

    if (total == 0) printf("O ponto pertence ao plano!\n");
    else printf("O ponto nao pertence ao plano!\n");
    return 0;
}