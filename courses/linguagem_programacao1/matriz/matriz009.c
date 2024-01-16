#include <stdio.h>
/*
9. Leia duas matrizes 4 x 4 e escreva uma terceira com os maiores valores de cada posição
das matrizes lidas.
*/
void saida(int x[4][4], int h);

int main()
{
    int matriz1[4][4], matriz2[4][4], maior[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
        {
            printf("Digite o valor na matriz1 [%d,%d]: ",i,j);
            scanf("%d", &matriz1[i][j]);

            printf("Digite o valor na matriz2 [%d,%d]: ",i,j);
            scanf("%d", &matriz2[i][j]);

            maior[i][j] = matriz1[i][j] >= matriz2[i][j] ? matriz1[i][j] : matriz2[i][j];       
        }       
    }
    
    saida(matriz1, 1);
    saida(matriz2, 2);
    saida(maior, 3);
    
    return 0;
}

void saida(int x[4][4], int n)
{
    printf("\n      Matriz %d\n", n);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("[%2d] ", x[i][j]);
        }
        printf("\n");
    }
}
