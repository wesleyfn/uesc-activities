#include <stdio.h>
#include <string.h>
/*
Faça um programa que leia uma string, imprima na tela e depois imprima a mesma
string invertida.
*/
int main()
{
    char string[101];
    char inverso[101];

    printf("Digite uma string: ");
    scanf(" %[^\n]", string);
    printf("Nome: %s\n", string);

    for (int x = 0, y = (strlen(string)-1); y >= 0 ; x++, y--)
    {
        inverso[x] = string[y];
    }
    printf("Invertido: %s\n", inverso);
    
}