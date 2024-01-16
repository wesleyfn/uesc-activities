#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que receba n duplas de números inteiros e
determine se o segundo e múltiplo do primeiro. Escreva uma função
Multiplo que receba dois números inteiros e retorne 1 se o segundo for
múltiplo do primeiro ou 0 em caso contrário.
*/
int mult(int, int);

typedef struct{
    int a, b, multiplo;
} TDupla;
int main(void)
{
    int n, i;
    TDupla *dupla;

    printf("Digite o numero de duplas: ");
    scanf("%d", &n);

    dupla = malloc(n * sizeof(TDupla));
    if (dupla == NULL){
        puts("Erro de memoria!");
        return -1;
    }

    for (i = 0; i < n; i++)
    {
        printf("\nDigite a dupla %d:\n", i+1);
        printf("A: ");
        scanf("%d", &dupla[i].a);
        printf("B: ");
        scanf("%d", &dupla[i].b);
        dupla[i].multiplo = mult(dupla[i].a, dupla[i].b);
    }
    
    for (i = 0; i < n; i++)
    {
        printf("\nDupla %d\n", i+1);
        printf("a: %d   b:%d\n", dupla[i].a, dupla[i].b);
        printf("Multiplo: %d\n", dupla[i].multiplo);
    }
    
    free(dupla);
    return 0;
}

int mult(int a, int b)
{
    if (b == 0) 
        return 0;
    return a%b == 0 ? 1 : 0;
}