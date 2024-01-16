#include <stdio.h>
/*
7. Crie um programa que leia 6 valores inteiros e, em seguida, mostre na tela os valores lidos na
ordem inversa.
*/
int main()
{
    int numbers[6];

    for (int i = 0; i < 6; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &numbers[i]);
    }

    printf("\nOrdem inversa: ");
    for (int i = 5; i > -1; i--)
    {
        printf("[%d] ", numbers[i]);
    }
    printf("\n");

    return 0;
}
