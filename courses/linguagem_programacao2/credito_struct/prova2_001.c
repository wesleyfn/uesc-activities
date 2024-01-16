#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    double x, y, z;
} TPontoEsp;

typedef struct{
    double raio;
    TPontoEsp centro;
} TEsfera;

int main(void)
{
    TPontoEsp ponto;
    TEsfera esfera;
    double d;

    puts("Digite os dados da esfera: ");
    puts("-> Centro");
    printf("Valor de x: ");
    scanf("%lf", &esfera.centro.x);
    printf("Valor de y: ");
    scanf("%lf", &esfera.centro.y);
    printf("Valor de z: ");
    scanf("%lf", &esfera.centro.z);
    printf("-> Raio: ");
    scanf("%lf", &esfera.raio);

    puts("\nDigite os dados do ponto: ");
    printf("Valor de x: ");
    scanf("%lf", &ponto.x);
    printf("Valor de y: ");
    scanf("%lf", &ponto.y);
    printf("Valor de z: ");
    scanf("%lf", &ponto.z);

    d = sqrt(pow(ponto.x - esfera.centro.x, 2) 
           + pow(ponto.y - esfera.centro.y, 2) 
           + pow(ponto.z - esfera.centro.z, 2));


    if (d < esfera.raio)
        printf("O ponto esta dentro da esfera!\n");
    else if (d > esfera.raio)
        printf("O ponto esta fora da esfera!\n");
    else
        printf("O ponto esta na borda de esfera!\n");
        
    return 0;
}