#include <stdio.h>
/*
17. Faça um programa que preencha um vetor de tamanho 100 com os 100 primeiros naturais que
não são múltiplos de 7 ou que terminam com 7.
*/
int main()
{
    const int max = 100;
    int vetor[max];

    for (int i = 0, j = 7; i < 100; j++)
    {
        if (j%7 == 0)
        {
            vetor[i] = j;
            i++;
        }
        else
        {
            for (int x = j; x > 9; )
            {
                x -= 10;
                if (x == 7)
                {
                    vetor[i] = j;
                    i++;
                } 
            } 
        }     
    }

    printf("Valores lidos: ");
    for (int i = 0; i < 100; i++)
    {
        printf("[%d] ", vetor[i]);
    }

    return 0;
}