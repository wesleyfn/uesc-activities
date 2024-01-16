#include <stdio.h>
#include <stdlib.h>
/*
Crie uma estrutura para representar um ponto no plano (x; y). Utilize a estrutura para fazer um
programa que leia três pontos e informe se eles formam ou não um triângulo retângulo.
*/
typedef struct {
    float x,y;
} TPonto;

int main(void)
{
    TPonto A, B, C;

    printf("Ponto A\nDigite o valor de x: ");
    scanf("%f", &A.x);
    printf("Digite o valor de y: ");
    scanf("%f", &A.y);

    printf("Ponto B\nDigite o valor de x: ");
    scanf("%f", &B.x);
    printf("Digite o valor de y: ");
    scanf("%f", &B.y);

    printf("Ponto C\nDigite o valor de x: ");
    scanf("%f", &C.x);
    printf("Digite o valor de y: ");
    scanf("%f", &C.y);

    if (A.x == B.x)
    {
        if (A.y == C.y || B.y == C.y)
            printf("Eh um triangulo retangulo!\n");
    }
    else if (B.x == C.x)
    {
        if (B.y == A.y || C.y == A.y)
            printf("Eh um triangulo retangulo!\n");
    }
    else if (C.x == A.x)
    {
        if (C.y == B.y || A.y == B.y)
            printf("Eh um triangulo retangulo!\n");
    }
    else printf("Nao eh um triangulo retangulo!\n");
    return 0;
}