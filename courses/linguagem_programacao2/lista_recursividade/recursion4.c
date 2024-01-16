#include <stdio.h>

int main(void)
{
    int x, i, result = 0;

    printf("Digite o valor: ");
    scanf("%d", &x);

    for (i = 0; i < x; i++)
    {
        result += x-i;
    }
    printf(" = %d\n", result);
    return 0;
}