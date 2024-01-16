#include <stdio.h>
/*
3 - Crie um programa em C que peça 10 números, armazene eles em um vetor e diga qual
elemento é o maior, qual é o menor e que seus valores.
*/
int main()
{
    const int MAX = 10;
    int vetor[MAX], maior = 0, menor = 0;

    for (int i = 0; i < MAX; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        if(maior < vetor[i])
        {
            maior = vetor[i];
        }
        if(menor > vetor[i] || i == 0)
        {
            menor = vetor[i];
        }
    }

    printf("\nValores do vetor: ");
    for (int i = 0; i < MAX; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    printf("\nMaior valor: %d\nMenor valor: %d\n", maior, menor);

    return 0;
}