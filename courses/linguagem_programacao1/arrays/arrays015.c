#include <stdio.h>
/*
15. Faça um programa que receba do usuário dois vetores, A e B, com 10 números inteiros cada. Crie
um novo vetor denominado C calculando C = A - B. Mostre na tela os dados do vetor C.
*/
int main()
{
    const int max = 10;
    int vetorA[max], vetorB[max], vetorC[max];

    for (int i = 0; i < max; i++)
    {
        printf("Digite o %do valor [vetor A]: ", i+1);
        scanf("%d", &vetorA[i]);
    }
    printf("\n");

    for (int i = 0; i < max; i++)
    {
        printf("Digite o %do valor [vetor B]: ", i+1);
        scanf("%d", &vetorB[i]);
    }

    printf("\nVetor C: ");
    for (int i = 0; i < max; i++)
    {
        vetorC[i] = vetorA[i] - vetorB[i];
        printf("[%d] ", vetorC[i]);
    }
    printf("\n");

    return 0;
}