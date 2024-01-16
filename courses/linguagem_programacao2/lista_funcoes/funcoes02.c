#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define NUM_BITS 16
/*
Escreva uma função BinarioToDecimal que receba uma cadeia de
caracteres que represente um número binário (i.e. a cadeia pode ser
composta apenas por 0s e 1s) e retorno o número em notação decimal.
Exemplo: se a função receber 10101 deverá retornar 22.
*/
void BinarioToDecimal(char *, int *);

int main(void)
{
    int n_dec = 0;
    char n_bin[NUM_BITS];

    printf("Digite o numero binario: ");
    scanf(" %[^\n]", n_bin);
    
    BinarioToDecimal(n_bin, &n_dec);
    printf("-> %d\n", n_dec);
    return 0;
}

void BinarioToDecimal(char *num_bin, int *num_dec)
{
    int exp, i;

    i = NUM_BITS - (NUM_BITS - strlen(num_bin)+1);
    for (exp = 0; i >= 0; exp++, i--){
        if (num_bin[i] == '1')
            *num_dec += pow(2,exp);
    }
    return;
}