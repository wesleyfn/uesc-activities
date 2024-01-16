#include <stdio.h>
/*
4. Faça um programa que leia um vetor de 8 posições e, em seguida, leia também dois valores X e
Y quaisquer correspondentes a duas posições no vetor. Ao final seu programa devera escrever a
soma dos valores encontrados nas respectivas posições X e Y .
*/
int main()
{
    int vetor[8];
    int x, y;

    printf("Digite o valor de X: ");
    scanf("%d", &x);
    printf("Digite o valor de Y: ");
    scanf("%d", &y);

    printf("\nVetor");
    for (int i = 0; i < 8; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);
    }

    printf("\nSoma[%d]+[%d]: %d\n", vetor[x], vetor[y], vetor[x]+vetor[y]);

    return 0;
}