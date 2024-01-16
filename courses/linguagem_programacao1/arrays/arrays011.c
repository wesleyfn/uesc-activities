#include <stdio.h>
/*
11. Fazer um programa para ler 5 valores e, em seguida, mostrar a posição onde se encontram o
maior e o menor valor.
*/
int main()
{
    int vetor[5], maior = 0, menor = 0, posicaoMaior = 0, posicaoMenor = 0;
    double media = 0;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        media += vetor[i];

        if (maior < vetor[i])
        {
            maior = vetor[i];
            posicaoMaior = i;
        }
        if (menor > vetor[i] || i == 0)
        {
            menor = vetor[i];
            posicaoMenor = i;
        }
    }

    printf("\nMaior valor: %d\tPosição: %d", maior, posicaoMaior);
    printf("\nMenor valor: %d\tPosição: %d\n", menor, posicaoMenor);

    return 0;
}