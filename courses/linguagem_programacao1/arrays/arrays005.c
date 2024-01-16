#include <stdio.h>
/*
5. Faça um programa que receba do usuário um vetor com 10 posições. Em seguida deverá ser
impresso o maior e o menor elemento do vetor.
*/
int main()
{
    int vetor[10];
    int maior = 0, menor = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        if (maior < vetor[i])
        {
            maior = vetor[i];
        }
        if (menor > vetor[i] || i == 0)
        {
            menor = vetor[i];
        }   
    }   
    printf("\nMaior valor: %d\nMenor valor: %d\n", maior, menor);
    return 0;
}
