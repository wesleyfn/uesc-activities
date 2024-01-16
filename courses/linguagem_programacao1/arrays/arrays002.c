
#include <stdio.h>
/*
2. Crie um programa que leia 6 valores inteiros e, em seguida, mostre na tela os valores lidos.
*/
int main()
{
    int numbers[6];


    for (int i = 0; i < 6; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &numbers[i]);
    }

    printf("Valores lidos: ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}