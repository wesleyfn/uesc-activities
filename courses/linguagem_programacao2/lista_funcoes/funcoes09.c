#include <stdio.h>
#include "bib_funcoes.h"
/*
Escreva um programa que imprima os primeiros n números primos onde
n é um valor informado pelo usuário. Considere utilizar alguma das
funções implementadas no programa anterior.
*/
int main(void)
{
    int i, n, flag;

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Primos: ");
    for (i = 2; i < n+1; i++)
    {
        flag = isPrimo(i);
        if (flag)
            printf("%d ", i);
    }
    printf("\n");
    return 0;
}