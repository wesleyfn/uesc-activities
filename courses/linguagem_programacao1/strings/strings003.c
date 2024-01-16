#include <stdio.h>
#include <ctype.h>
#include <string.h>
/*
Faça um programa que receba uma string e depois imprime o seu conteúdo em letras
maiúsculas.
*/
int main()
{
    char string[50];

    printf("Digite uma string: ");
    scanf("%[^\n]", string);

    printf("Em maiusculas: ");
    for (int i = 0; i < strlen(string); i++)
    {
        printf("%c", toupper(string[i]));
    }
    printf("\n");
    
   
    
    return 0;
}