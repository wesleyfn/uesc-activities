#include <stdio.h>
#include "bib_matriz.h"

int main(void)
{
    float **A, **B, **Som, **Sub;
    int i, j, m, n;

    printf("Digite o numero de linhas: ");
    scanf("%d", &m);
    printf("Digite o numero de colunas: ");
    scanf("%d", &n);

    A = aloca_matriz(m, n);
    B = aloca_matriz(m, n);
    Som = aloca_matriz(m, n);
    Sub = aloca_matriz(m, n);

    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++)
        {
            printf("Digite o elemento [%d,%d] de A: ", i+1, j+1);
            scanf("%f", &A[i][j]);
            printf("Digite o elemento [%d,%d] de B: ", i+1, j+1);
            scanf("%f", &B[i][j]);

            Som[i][j] = A[i][j] + B[i][j];
            Sub[i][j] = A[i][j] - B[i][j];
        }
    }

    printf("\nSoma\n");
    prt_operacao(A, B, Som, m, n, '+');
    printf("\nSubtracao\n");
    prt_operacao(A, B, Sub, m, n, '-');

    libera_matriz(A, m);
    libera_matriz(B, m);
    libera_matriz(Som, m);
    libera_matriz(Sub, m);
    
    return 0;
}