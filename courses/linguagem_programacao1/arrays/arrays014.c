#include <stdio.h>
#include <stdlib.h>

/*
14. Faça um programa que leia um vetor de 5 posições para números reais e, depois, um código
inteiro. Se o código for zero, finalize o programa; se for 1, mostre o vetor na ordem direta; se
for 2, mostre o vetor na ordem inversa. Se for 3 saia do programa. Caso, o código seja diferente
de 1, 2 ou 3 escreva uma mensagem informando que a escolha e inválida.
*/

void normal(double *vetor);
void inverse(double *vetor);

int main()
{
    double numeros[5];
    int code;

    for (int i = 0; i < 5; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%lf", &numeros[i]);
    }

    printf("\nDigite o código: ");
    scanf("%d", &code);

    switch (code)
    {
    case 1:
        printf("Ordem Direta: ");
        normal(numeros);
        break;
    case 2:
        printf("Ordem Inversa: ");
        inverse(numeros);
        break;
    case 3:
        exit;
        break;
    default:
        printf("Escolha Inválida!");
        break;
    }
    printf("\n");
    

    return 0;
}

void normal(double *vetor)
{
    for (int i = 0; i < 5; i++)
    {
        printf("[%.1lf] ", vetor[i]);
    }
}

void inverse(double *vetor)
{
    for (int i = 4; i > -1; i--)
    {
        printf("[%.1lf] ", vetor[i]);
    } 
}