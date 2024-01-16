#include <stdio.h>
/*
5. Declare uma matriz 5 x 5. Preencha com 1 a diagonal principal e com 0 os demais
elementos. Escreva ao final a matriz obtida.
*/
int main()
{
    int matriz[5][5] = {0};

    for (int i = 0, c = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][i] = 1;
        } 
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("[%d] ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}