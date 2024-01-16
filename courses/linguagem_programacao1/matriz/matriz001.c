#include <stdio.h>
/*
1. Faça um programa que lê uma matriz de 3 x 3 elementos usando um comando for,
multiplica cada elemento por 5 e imprime o resultado.
*/
int main()
{
    int matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor de [%d,%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
            matriz[i][j] *= 5;
        }       
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%2d] ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}