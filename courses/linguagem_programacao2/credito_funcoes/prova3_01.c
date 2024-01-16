#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b, multiplo;
} TDupla;

int mult(int, int);

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
        printf("Valor A: ");
        scanf("%d", &dupla[i].a);
        printf("Valor B: ");
        scanf("%d", &dupla[i].b);
        dupla[i].multiplo = mult(dupla[i].a, dupla[i].b);
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Dupla %d\n", i+1);
        printf("%d e %d : ", dupla[i].a, dupla[i].b);
        printf("%s\n", dupla[i].multiplo ? "Multiplo" : "Nao Multiplo");
    }
    
    free(dupla);
    return 0;
}

int mult(int x, int y)
{
    if (y == 0) 
        return 0;
    return x%y == 0 ? 1 : 0;
}