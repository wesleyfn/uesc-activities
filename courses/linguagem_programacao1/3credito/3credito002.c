#include <stdio.h>
#include <locale.h>
/*
2 - Crie um aplicativo em C que peça um número inicial ao usuário, uma razão e calcule
os termos de uma P.A (Progressão Aritmética), armazenando esses valores em um vetor
de tamanho 10.
*/
int main()
{
    setlocale(LC_ALL, "portuguese");

    const int MAX = 10;
    int razao, vetor[MAX];

    printf("Digite o valor inicial: ");
    scanf("%d", &vetor[0]);

    printf("Digite a razão da P.A: ");
    scanf("%d", &razao);

    printf("Progressão Aritmética (P.A): [%d] ", vetor[0]);
    for (int i = 1; i < MAX; i++)
    {
        vetor[i] = vetor[i-1] + razao;
        printf("[%d] ", vetor[i]);
    }
    printf("\n");

    return 0;
}