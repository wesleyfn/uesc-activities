#include <stdio.h>
#include <locale.h>
/*
7. Leia uma matriz 4 x 4, imprima a matriz e retorne a localização (linha e a coluna) do maior
valor.
*/
int main()
{
    setlocale(LC_ALL, "portuguese");

    int matriz[4][4], maior_numero = 0, maior_i, maior_j;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Digite o valor em [%d,%d]: ",i,j);
            scanf("%d", &matriz[i][j]);
            if (matriz[i][j] > maior_numero)
            {
                maior_numero = matriz[i][j];
                maior_i = i;
                maior_j = j;
            }
        }       
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("[%2d] ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("O maior número [%d] está na posição [%d,%d] da matriz\n",maior_numero, maior_i, maior_j);
    return 0;
}