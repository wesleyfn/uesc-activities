#include <stdio.h>

int main(void)
{
    int count = 0;
    char str[100], *ptr_str, c;
    ptr_str = str;

    printf("Digite a string: ");
    scanf("%[^\n]", str);
    printf("Digite um caractere: ");
    scanf(" %c", &c);

    for ( ;*ptr_str != '\0'; )
    {   
        if (*ptr_str == c) count++;
        ptr_str++;
    }
    printf("Ha %d ocorrencias de \'%c\' em \"%s\"\n", count, c, str);
    return 0;
}