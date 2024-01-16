#include <stdio.h>
/*
4.Leia uma matriz 4 x 4, conte e escreva quantos valores maiores que 10 ela possui.
*/
int main()
{
    int matriz[4][4], count10 = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Digite o valor da matriz, [%d,%d]: ",i,j);
            scanf("%d", &matriz[i][j]);

            if(matriz[i][j] > 10) count10++;
        }     
    }
    printf("\nA matriz possui %d valores maiores que 10\n", count10);
    return 0;
}