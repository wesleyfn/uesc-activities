#include <stdio.h>
#include <locale.h>
/*
3. Faça um programa que preencha uma matriz 3x4 de valores reais, calcule e mostre a
quantidade de elementos pares, a quantidade de elementos ímpares e a média de todos os
elementos.
*/
int main()
{
    setlocale(LC_ALL, "portuguese");

    int matriz[3][4], qImpar = 0, qPar = 0, i, j;
    double media = 0;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Digite o valor da matriz, [%d,%d]: ",i,j);
            scanf("%d", &matriz[i][j]);

            matriz[i][j]%2 == 0 ? qPar++ : qImpar++;
            media += matriz[i][j];
        }     
    }
    media /= i*j;

    printf("\nQuantidade de números PARES: %d\n", qPar);
    printf("Quantidade de números IMPARES: %d\nMédia: %.2lf\n", qImpar, media);
    return 0;
}