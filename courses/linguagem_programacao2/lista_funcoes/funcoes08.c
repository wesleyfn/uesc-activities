#include <stdio.h>
#include "bib_funcoes.h"
/*
Diz-se que um número inteiro e primo se for divisível apenas por 1 por
se mesmo. Por exemplo, 2, 3, 5, e 7 são números primos, mas 4, 6, 8 e
9, não são.
a. Escreva uma função que determine se um número é primo.
b. Use essa função em um programa que determine e imprima todos
os números primos entre 1 e 1000.
*/
int main(void)
{
    int i, flag;

    printf("Primos: ");
    for (i = 1; i < 1001; i++)
    {
        flag = isPrimo(i);
        if (flag)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}

