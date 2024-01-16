#include <stdio.h>
#include <string.h>
/*
Faça um programa que receba um nome digitado em seguida diga se ele é um
palíndromo.
*/
int main()
{
    char nome[20];
    char inverso[20];

    printf("Digite um nome: ");
    scanf("%s", nome);

    for (int x = 0, y = (strlen(nome)-1); y >= 0 ; x++, y--)
    {
        inverso[x] = nome[y];
    }
    printf("Invertido: %s\n", inverso);

    if (!strcmp(nome,inverso)) //strcmp entrega 0 se os parametros são iguais
    {
        printf("Palindromo encontrado!\n");
    }
    else printf("Palindromo não encontrado!\n");
    
    
    
}