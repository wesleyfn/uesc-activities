#include <stdio.h>
/*
11. Leia uma matriz de 3 x 3 elementos. Calcule a soma dos elementos que estão acima da
diagonal principal.
*/
int main()
{
    int matriz[3][3], soma = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
        {
            printf("Digite o valor de [%d,%d]: ",i,j);
            scanf("%d", &matriz[i][j]);

            if (j > i) soma += matriz[i][j];
        }       
    }
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {   
            printf("[%2d] ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("Soma: %d\n", soma);
    return 0;
}