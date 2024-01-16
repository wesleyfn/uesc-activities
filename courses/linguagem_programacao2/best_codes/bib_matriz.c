#include <stdio.h>
#include <stdlib.h>

float ** aloca_matriz(const int lin, const int col)
{
    int i;
    float **mat;

    mat = malloc(lin * sizeof(float *));
    if (mat == NULL){
        puts("Erro de memoria!");
        exit(-1);
    }
    for (i = 0; i < lin; i++)
    {
        mat[i] = malloc(col * sizeof(float));
        if (mat[i] == NULL){
            puts("Erro de memoria!");
            exit(-1);
        }
    }
    return mat;
}

void prt_operacao(float **mat1, float **mat2, float **mat3,
                  const int lin, const int col, const char oper)
{
    int i, j;
    for (i = 0; i < lin; i++)
    {
        for (j = 0; j < col; j++)
            printf("%5.2f ", mat1[i][j]);
        if (i == lin/2){
            printf("  %c  ", oper);
        } else printf("     ");

        for (j = 0; j < col; j++)
            printf("%5.2f ", mat2[i][j]);
        if (i == lin/2){
            printf("  =  ");
        } else printf("     ");

        for (j = 0; j < col; j++)
            printf("%5.2f ", mat3[i][j]);
        printf("\n");  
    }
    return;
}

void libera_matriz(float ** mat, const int lin)
{
    int i;
    for (i = 0; i < lin; i++)
        free(mat[i]);
    free(mat);
    return;
}