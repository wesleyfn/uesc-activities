#include <stdio.h>
/*
10. Fazer um programa para ler 5 valores e, em seguida, mostrar todos os valores lidos juntamente
com o maior, o menor e a media dos valores.
*/
int main()
{
    int vetor[5], maior = 0, menor = 0;
    double media = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        media += vetor[i];

        if (maior < vetor[i])
        {
            maior = vetor[i];
        }
        if (menor > vetor[i] || i == 0)
        {
            menor = vetor[i];
        }
    }

    printf("\nValores lidos: ");
    for (int i = 0; i < 5; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    printf("\nMaior valor: %d\nMenor valor: %d", maior, menor);
    printf("\nMedia: %.1lf\n", media/5);
    
    return 0;
}