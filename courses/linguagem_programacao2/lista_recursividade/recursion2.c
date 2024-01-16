#include <stdio.h>
/*
Escreva um programa iterativo para avaliar a*b usando a adição onde a e b são inteiros
não negativos.
*/
int iteracao(int, int);

int main(void)
{
    int x, y;

    printf("Digite os 2 valores: ");
    scanf("%d %d", &x, &y);
    printf("%d*%d = %d\n", x, y, iteracao(x, y));

    return 0;
}

int iteracao(int a, int b)
{
    if (b == 0)
        return 0;
    return a + iteracao(a, b-1);
}