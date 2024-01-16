#include <stdio.h>
/*
9. Faça um programa que preencha um vetor com 10 números reais, calcule e mostre a quantidade
de números negativos e a soma dos números positivos desse vetor.
*/
int main()
{
    double vetor[10];
    double somaPositivo = 0;
    int quantNegativo = 0;

    for (int i = 0; i < 10; i++)
    {   
        printf("Digite o %do valor: ", i+1);
        scanf("%lf", &vetor[i]);
    
        vetor[i] >= 0 ? somaPositivo += vetor[i] : quantNegativo++;
    }
    
    printf("\nNúmeros de valores negativos: %d\n", quantNegativo);
    printf("Soma dos números positivos: %.1lf\n", somaPositivo);

    return 0;
    
}