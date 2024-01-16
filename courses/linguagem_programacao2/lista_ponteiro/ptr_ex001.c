/*
1. Escreva um programa que leia um valor de ponto flutuante via teclado. Crie um ponteiro
que aponte para o valor. Imprima o valor na tela usando a t ́ecnica de referˆencia direta e a
t ́ecnica de referˆencia indireta. Imprima tamb ́em o endere ̧co da vari ́avel apontada.
*/
#include <stdio.h>

int main(void)
{
    float valor, *ptr_valor;
    ptr_valor = &valor;

    printf("Digite o valor: ");
    scanf("%f", &valor);

    printf("Direta: %.2f\nIndireta: %.2f\nEndereço: %p\n", valor, *ptr_valor, ptr_valor);

    return 0;
}