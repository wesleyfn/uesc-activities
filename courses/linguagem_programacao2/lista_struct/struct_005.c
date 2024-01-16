#include <stdio.h>
#include <stdlib.h>
/*
Utilize uma estrutura para representar um ponto do plano (x; y), escreva um programa que leia
um ponto do teclado e informe a que quadrante pertence (I, II, III ou IV). O programa ficará em
execução até que o ponto (0; 0) seja digitado. Desconsidere os pontos sobre os eixos
coordenados. Utilize a menor quantidade de comparações possível. Sugestão: O problema
pode ser resolvido verificando apenas duas condições para cada ponto digitado.
*/
typedef struct{
    int x,y;
} TPonto;

int main(void)
{
    TPonto pontoA;

    do { 
        printf("Digite o valor de x: ");
        scanf("%d", &pontoA.x);
        printf("Digite o valor de y: ");
        scanf("%d", &pontoA.y);

        if (pontoA.y > 0)
        {
            if (pontoA.x > 0)
                printf("-> Quadrante I\n");
            else if (pontoA.x < 0)
                printf("-> Quadrante II\n");
        }
        else if (pontoA.y < 0)
        {
            if (pontoA.x > 0)
                printf("-> Quadrante IV\n");
            else if (pontoA.x < 0)
                printf("-> Quadrante III\n");   
        }
        printf("\n");
    } while (pontoA.x != 0 || pontoA.y != 0);

    printf("Programa finalizado!\n");
    return 0;
}
