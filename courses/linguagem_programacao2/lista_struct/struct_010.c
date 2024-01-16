#include <stdio.h>
/*
A seguinte estrutura representa um numero complexo
typedef {
float Re;
float Im;
}TNumComp;
Escreva um programa que recebe dois numeros complexos e informa os resultados da
soma e subtração desses dois números.
*/
typedef struct{
    float Re, Im;
} TNumComp;

int main(void)
{
    TNumComp num1, num2;
    float total1, total2;
    
    puts("Primeiro numero");
    printf("Digite o valor da parte real: ");
    scanf("%f", &num1.Re);
    printf("Digite o valor da parte imaginaria: ");
    scanf("%f", &num1.Im);

    puts("Segundo numero");
    printf("Digite o valor da parte real: ");
    scanf("%f", &num2.Re);
    printf("Digite o valor da parte imaginaria: ");
    scanf("%f", &num2.Im);

    total1 = (num1.Re + num2.Re);
    total2 = (num1.Im + num2.Im);
    printf("%f\n", total1);
    printf("\nSoma dos numeros complexos: %.1f + %.1fi\n", total1, total2);

    total1 = (num1.Re - num2.Re);
    total2 = (num1.Im - num2.Im);
    printf("Subtracao dos numeros complexos: %.1f - %.1fi\n", total1, total2);

    return 0;
}