#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long int produto = 1;
    int **mat, i, j, lcm,
        qNeg = 0, maior = 0, maior2 = 0;

    printf("Digite a quantidade de linhas e colunas: ");
    scanf("%d", &lcm);

    mat = malloc(lcm * sizeof(int *));
    if(mat == NULL) {
        printf("Erro de memoria!\n");
        return -1;
    }
    for (i = 0; i < lcm; i++)
    {
        mat[i] = malloc(lcm * sizeof(int));
        if(mat[i] == NULL) {
            printf("Erro de memoria!\n");
            return -1;
        }
    }

    printf("\nMatriz\n");
    for (i = 0; i < lcm; i++) {
        for (j = 0; j < lcm; j++)
        {
            printf("[%d,%d]: ", i,j);
            scanf("%d", &mat[i][j]);
            if((j==0 && i==0) || (maior < mat[i][j])) 
                maior = mat[i][j];
        }
    }
    for (i = 0; i < lcm; i++) {
        for (j = 0; j < lcm; j++)
        {
            if ((j==0 && i==0) || (maior2 < mat[i][j] && mat[i][j] != maior)) {
                maior2 = mat[i][j];
            }
            if(mat[i][j] < 0) {
                qNeg++;
            }
            produto *= mat[i][j];
        }
    }
    
    printf("\nMaior: %d\nSegundo maior: %d\n", maior, maior2);
    printf("Quantidade de negativos: %d\nProduto dos valores: %ld\n", qNeg, produto);

    for (i = 0; i < lcm; i++) 
        free(mat[i]);
    free(mat);
    return 0;
}