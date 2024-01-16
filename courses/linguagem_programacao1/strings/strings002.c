#include <stdio.h>
#include <string.h>
/*
Faça um programa que leia duas strings digitadas pelo usuário e em seguida imprima as
duas concatenadas.
*/
int main()
{
    char x[50], y[50];
    

    printf("Digite uma string para x: ");
    scanf(" %[^\n]", x);
    
    printf("Digite uma string para y: ");
    scanf(" %[^\n]", y);

    printf("Concatenadas: %s\n", strcat(x,y));
    
    return 0;
}