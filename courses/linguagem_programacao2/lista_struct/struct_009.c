#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
Crie uma estrutura para representar um ponto TPonto do espaço. Utilize a estrutura TPonto
para criar uma estrutura Tesfera (centro e radio). Escreva um programa usando as estruturas
anteriores que receba uma esfera e um ponto, seu programa deve informar se o ponto é
interno ou externo a esfera.
*/
typedef struct{
    float x,y,z;
} TPonto;

typedef struct{
    float raio;
    TPonto centro;
} TEsfera;

int main(void)
{
    TPonto ponto;
    TEsfera esfera;
    float total;

    puts("Determine o ponto");
    printf("Digite o valor de x: ");
    scanf("%f", &ponto.x);
    printf("Digite o valor de y: ");
    scanf("%f", &ponto.y);
    printf("Digite o valor de z: ");
    scanf("%f", &ponto.z);

    puts("Determine o centro da esfera");
    printf("Digite o valor de x: ");
    scanf("%f", &esfera.centro.x);
    printf("Digite o valor de y: ");
    scanf("%f", &esfera.centro.y);
    printf("Digite o valor de z: ");
    scanf("%f", &esfera.centro.z);

    printf("Digite o raio da esfera: ");
    scanf("%f", &esfera.raio);

    total = pow(ponto.x - esfera.centro.x,2) 
        + pow(ponto.y - esfera.centro.y,2)
        + pow(ponto.z - esfera.centro.z,2) 
        - pow(esfera.raio,2);

    if (total > 0)
        printf("Ponto externo!\n");
    else if (total < 0)
        printf("Ponto interno!\n");
    
    return 0;
}