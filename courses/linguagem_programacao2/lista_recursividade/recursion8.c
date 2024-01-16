#include <stdio.h>
/*
Um problema típico em ciência da computação consiste em converter um número da sua
forma decimal para a forma binária. Faça uma função recursiva que receba um número
decimal e imprima seu valor binário.
*/
void toBinary(int);

int main(void)
{
    toBinary(8);
    printf("\n");
    return 0;
}

void toBinary(int n)
{
    printf("%d", n%2);
    if (n == 1 || n == 0)
        return;
    n = n/2;
    return toBinary(n);
}