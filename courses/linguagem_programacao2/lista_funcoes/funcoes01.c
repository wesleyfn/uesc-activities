#include <stdio.h>
#include <string.h>
#define NUM_BITS 8
/*
Escreva uma função DecimalToBinario que receba um número inteiro e
retorne uma cadeia de caracteres com o número em representação
binária. Exemplo: se a função receber o número 17 deverá retornar
100001.
*/
void DecimalToBinario(char *, int);

int main(void)
{  
    int i, n_dec;
    char n_bin[NUM_BITS];
    printf("Digite o numero a ser convertido: ");
    scanf("%d", &n_dec);
    
    DecimalToBinario(n_bin, n_dec);
    printf("-> ");
    for (i = 0; n_bin[i]; i++)
    {
        putchar(n_bin[i]);
        if((i+1) % 4 == 0) printf(" ");
    }
    printf("\n");
    return 0;
}

void DecimalToBinario(char *num_bin, int num_dec)
{
    int i, resto, quociente;

    for (i = NUM_BITS-1; i >= 0; i--)
    {
        resto = num_dec % 2;
        quociente = num_dec / 2;
        num_dec = quociente;
        num_bin[i] = resto + '0';
    }
    num_bin[NUM_BITS] = '\0';
    return;
}