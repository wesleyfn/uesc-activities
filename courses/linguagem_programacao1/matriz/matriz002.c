#include <stdio.h>
/*
2. Faça um programa que lê um vetor de 3 elementos e uma matriz de 3 x 3 elementos. Em
seguida o programa deve fazer a multiplicação do vetor pelas colunas da matriz.
*/
int main()
{
    int vetor[3], matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        printf("Digite o valor do vetor, [%d]: ", i);
        scanf("%d", &vetor[i]);
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor da matriz, [%d,%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
            matriz[i][j] *= vetor[j];
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