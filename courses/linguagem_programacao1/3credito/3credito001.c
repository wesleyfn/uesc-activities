#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
/*
1 – Escreva um algoritmo que preencha um vetor com 100 números inteiros aleatórios
entre 1 e 10 e peça ao usuário que digite um número inteiro k. O algoritmo deve apresentar
como resultado o número de ocorrências de k no vetor.
*/
int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    const int MAX = 100;
    int numeros[MAX], k, vezes = 0;

    for (int i = 0; i < MAX; i++)
    {
        numeros[i] = rand() % 10+1;
    }

    printf("Digite o valor de k: ");
    scanf("%d", &k);

    for (int i = 0; i < MAX; i++)
    {
        if(k == numeros[i]) vezes++;
    }
    
    printf("Número de ocorrências de [%d]: %d\n", k, vezes);
    return 0;
}