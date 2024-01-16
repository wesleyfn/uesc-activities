#include <stdio.h>
/*
3. Ler um conjunto de números reais, armazenando-o em vetor e calcular o quadrado dos
componentes deste vetor, armazenando o resultado em outro vetor. Os conjuntos tem 10
elementos cada. Imprimir todos os conjuntos.
*/

int main()
{
    double numbers[10], sqrnumbers[10];

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%lf", &numbers[i]);
        
        sqrnumbers[i] = numbers[i] * numbers[i];
    }

    printf("Valores lidos: ");
    for (int i = 0; i < 10; i++)
    {   
        printf("[%.1lf] ", numbers[i]);
    }
    printf("\n");

    printf("Valores lidos ^2: ");
    for (int i = 0; i < 10; i++)
    {   
        printf("[%.1lf] ", sqrnumbers[i]);
    }
    printf("\n");
}
