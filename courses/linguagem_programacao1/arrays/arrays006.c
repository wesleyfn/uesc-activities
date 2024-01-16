#include <stdio.h>
/*
6. Escreva um programa que leia 10 números inteiros e os armazene em um vetor. Imprima o vetor,
o maior elemento e a posição que ele se encontra. ̃
*/
int main()
{
    int vetor[10];
    int maior = 0, posicao = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);

        if (maior < vetor[i])
        {
            maior = vetor[i];
            posicao = i;
        }
    }

    printf("\nValores lidos: ");
    for (int i = 0; i < 10; i++)
    {   
        printf("[%d] ", vetor[i]);
    }
    printf("\n\nMaior valor: %d\nPosição no vetor: %d\n", maior, posicao);
    
    return 0;
}
