#include <stdio.h>
#include <stdlib.h>
/*
Modifique o programa anterior para considerar os pontos sobre os eixos coordenadas com a
mensagem “Ponto sobre os eixos". Utilize a menor quantidade de comparações possível.
*/
typedef struct {
    float x,y;
} TPonto;

int main(void)
{
    TPonto pontoA;

    do { 
        printf("Digite o valor de x: ");
        scanf("%f", &pontoA.x);
        printf("Digite o valor de y: ");
        scanf("%f", &pontoA.y);

        if (pontoA.x == 0 || pontoA.y == 0)
        {
            printf("-> Ponto sobre os eixos!\n");
        }
        else if (pontoA.y > 0)
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