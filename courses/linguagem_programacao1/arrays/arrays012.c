#include <stdio.h>
/*
12. Faça um programa que leia um vetor de 10 posições e verifique se existem valores iguais ̃ e os
escreva na tela.
*/
int main()
{
    int vetor[10], igual[10], contador = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &vetor[i]);
    }
    
    printf("Valores Idênticos: ");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {   
            if (i != j)
            {  
                if (vetor[i] == vetor[j]) 
                {
                    printf("[%d] ", vetor[i]);
                    break;
                }
            }
            
        }
    }
    printf("\n");

    return 0;
}
