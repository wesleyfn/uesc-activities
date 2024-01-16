#include <stdio.h>
/*
10. Gerar e imprimir uma matriz de tamanho 10 x 10, onde seus elementos são da forma:
A[i][j] = 2i + 7j − 2 se i < j;
A[i][j] = 3i2 − 1 se i = j;
A[i][j] = 4i3 − 5j2 + 1 se i > j.
*/
int main()
{
    int matriz[10][10];

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (i < j) 
                matriz[i][j] = 2*i + 7*j - 2;
            else if (i == j) 
                matriz[i][j] = 3*(i*i) - 1;
            else if (i > j) 
                matriz[i][j] = 4*(i*i*i) - 5*(j*j) + 1;
        }       
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("[%4d] ", matriz[i][j]);
        }
        printf("\n");
    }
    return 0;
}