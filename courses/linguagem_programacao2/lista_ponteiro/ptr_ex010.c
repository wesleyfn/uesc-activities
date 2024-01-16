#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int **matA, **matB, lm, cm, i, j, operacao;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &lm);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &cm);

    matA = malloc(lm * sizeof(int *));
    matB = malloc(lm * sizeof(int *));
    if (matA == NULL || matB == NULL) {
        printf("Erro de memoria!\n");
        return -1;
    }
    for (i = 0; i < lm; i++) {
        matA[i] = malloc(cm * sizeof(int));
        if (matA[i] == NULL)
        {
            printf("Erro de memoria!\n");
            return -1;
        }
    }
    for (i = 0; i < lm; i++) {
        matB[i] = malloc(cm * sizeof(int));
        if (matB[i] == NULL)
        {
            printf("Erro de memoria!\n");
            return -1;
        }
    }

    printf("\nMatriz A\n");
    for (i = 0; i < lm; i++) {
        for (j = 0; j < cm; j++)
        {
            printf("[%d,%d]: ",i,j);
            scanf("%d", &matA[i][j]);
        }
    }
    printf("\nMatriz B\n");
    for (i = 0; i < lm; i++) {
        for (j = 0; j < cm; j++)
        {
            printf("[%d,%d]: ",i,j);
            scanf("%d", &matB[i][j]);
        }
    }
    
    printf("\nSoma:\n");
    for (i = 0; i < lm; i++) {
        for (j = 0; j < cm; j++)
        {
            operacao = matA[i][j] + matB[i][j];
            printf("[%3d] ", operacao);
        }
        printf("\n");
    }
    printf("\nSubtracao:\n");
    for (i = 0; i < lm; i++) {
        for (j = 0; j < cm; j++)
        {
            operacao = matA[i][j] - matB[i][j];
            printf("[%3d] ", operacao);
        }
        printf("\n");
    }

    for (i = 0; i < lm; i++)
        free(matA[i]);
    for (i = 0; i < lm; i++)
        free(matB[i]);
    free(matA);
    free(matB);
    return 0;
}