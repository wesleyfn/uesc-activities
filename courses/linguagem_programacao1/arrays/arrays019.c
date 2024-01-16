#include <stdio.h>
/*
19. Faça um programa que receba 6 números inteiros e mostre:
• Os números pares digitados;
• A soma dos números pares digitados;
• Os números ímpares digitados;
• A quantidade de números ímpares digitados;
*/
int main()
{
    int j = 0, h = 0;
    const int max = 6;
    int numbers[max];
    int par[max], somaPar = 0;
    int impar[max], quantImpar = 0;

    for (int i = 0; i < max; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &numbers[i]);

        if (numbers[i]%2 == 0)
        {
            par[j] = numbers[i];
            somaPar += numbers[i];
            j++;
        }
        else
        {
            impar[h] = numbers[i];
            h++;
        }
    }

    printf("\nNúmeros pares: ");
    for (int i = 0; i < j; i++)
    {
        printf("[%d] ", par[i]);
    }
    printf("\nSoma: %d", somaPar);

    printf("\nNúmeros pares: ");
    for (int i = 0; i < h; i++)
    {
        printf("[%d] ", impar[i]);
    }
    printf("\nQuantidade: %d\n", h);
    
    return 0;
}
