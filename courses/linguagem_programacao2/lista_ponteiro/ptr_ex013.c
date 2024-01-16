#include <stdio.h>

int main(void)
{
    int i;
    char str[100], *ptr_str;
    ptr_str = str;

    printf("Digite uma string: ");
    scanf("%[^\n]", str);
    for (i = 0; *ptr_str != '\0'; i++)
    {
        ptr_str++;
    }
    printf("Numero de caracteres: %d\n", i);
    return 0;
}