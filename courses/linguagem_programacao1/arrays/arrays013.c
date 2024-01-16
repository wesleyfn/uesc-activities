#include <stdio.h>
/*
13. Leia um vetor com 20 números inteiros. Escreva os elementos do vetor eliminando elementos
repetidos.
*/
int main()
{
    int max = 20;
    int vetor[max], aux[max], aparicoes = 0, h = 0;

    for (int i = 0; i < max; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    for (int i = 0; i < max; i++)
    {   
        for (int j = 0; j < max; j++)
        {
            if (vetor[i] == vetor[j])
            {
                aparicoes++;  
            }
        }

        if (aparicoes == 1)
        {
            aux[h] = vetor[i];
            h++;
        }  
        aparicoes = 0;

    }  

    printf("\nNão repetíveis: %s", h == 0 ? "Nenhum!\n" : "");
    for (int i = 0; i < h; i++)
    {
        printf("[%d] ", aux[i]);
    }
    printf("\n");

    return 0;
}