#include <stdio.h>
#include <math.h>
/*
18. Faça um programa que calcule o desvio padrão de um vetor v contendo n = 10 números, onde m
e a media do vetor.
*/

int main()
{
    const int MAX = 10;
    int vetor[MAX];
    double media = 0, variancia = 0;

    for (int i = 0; i < MAX; i++) //Entrada dos valores e o somatório
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]); //entrada

        media += vetor[i]; //somatório
    }
    media /= MAX; //media
    
    for (int i = 0; i < 10; i++)
    {
        variancia += pow((vetor[i] - media), 2.0); //somatório
    }  

    variancia = variancia/(MAX-1);
    printf("Desvio Padrão: %.1lf\n", sqrt(variancia)); //printa o calculo do devio padrão

    return 0;
}