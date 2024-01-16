#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{   
    int i, j, qVogais = 0, qDigBrancos = 0;
    char str[100], *ptr_str;
    char vogais[] = "aeiou";
    ptr_str = str;

    printf("Digite a string: ");
    scanf("%[^\n]", str);

    for (i = 0; *ptr_str != '\0'; i++)
    {
        for (j = 0; vogais[j] != '\0'; j++)
        {
            if (*ptr_str == vogais[j]) qVogais++;
        }
        if (isspace(*ptr_str))
        {
            qDigBrancos++;
        }
        ptr_str++;
    } 
    printf("Numero de vogais: %d\nNumero de digitos: %d\n", qVogais, (i-qDigBrancos));
    printf("Numero de caracteres em branco: %d\n", qDigBrancos);
    return 0;
}