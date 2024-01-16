#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
/*
Escreva uma função que receba um número inteiro e retorne o mesmo
número em ordem inversa. Exemplo: se a função receber 1975 ela
deverá retornar 5719.
*/
void inverter_int(char *);

int main(void)
{
    char n[10];

    printf("Digite um numero inteiro: ");
    scanf(" %[^\n]", n);

    inverter_int(n);
    printf("-> %s\n", n);
    return 0;
}

void inverter_int(char *num)
{
    int i, j;
    char buff[MAX];

    j = strlen(num)-1;
    for (i = 0; num[i] != '\0'; i++, j--)
        buff[j] = num[i];
    buff[i] = '\0';
    strcpy(num, buff);
    return;
}