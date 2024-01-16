#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a, b, produto;
} TDupla;

int prod_rec(int, int);

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
        dupla[i].produto = prod_rec(dupla[i].a, dupla[i].b);
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Dupla %d\n", i+1);
        printf("%d * %d", dupla[i].a, dupla[i].b);
        printf(" = %d\n", dupla[i].produto);
    }

    free(dupla);
    return 0;
}

int prod_rec(int x, int y)
{
    if (y == 0 || x == 0)
        return 0;
    return x + prod_rec(x, y-1);
}