#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **mat, lcm, i, j, flag = 1;

    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%d", &lcm);

    mat = malloc(lcm * sizeof(int *));
    if (mat == NULL) {
        puts("Erro de memoria!");
        return -1;
    }
    for (i = 0; i < lcm; i++)
    {
        mat[i] = malloc(lcm * sizeof(int));
        if (mat[i] == NULL) {
            puts("Erro de memoria!");
            return -1;
        }
    }

    printf("\nPreencha a matriz\n");
    for (i = 0; i < lcm; i++) {
        for (j = 0; j < lcm; j++)
        {
            printf("[%d,%d]: ", i,j);
            scanf("%d", &mat[i][j]);
        }
    }
    
    for (i = 0; i < lcm; i++) {
        for (j = 0; j < lcm; j++)
        {
            printf("[%d] ", mat[i][j]);
            if (i > j && mat[i][j] != 0)
                flag = 0;
        }
        printf("\n");
    }
    printf("%s diagonal superior\n", flag == 0 ? "Nao eh" : "Eh");

    for (i = 0; i < lcm; i++)
        free(mat[i]);
    free(mat);
    return 0;
}