#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, x, lmA, lmB, cmA, cmB;
    int **matA, **matB, **matC, acumulo;

    printf("Digite numero de linhas da matriz A: ");
    scanf("%d", &lmA);
    printf("Digite numero de colunas da matriz A: ");
    scanf("%d", &cmA);
    printf("\nDigite numero de linhas da matriz B: ");
    scanf("%d", &lmB);
    printf("Digite numero de colunas da matriz B: ");
    scanf("%d", &cmB);

    if (cmA != lmB)
    {   
        puts("\n-> Nao eh possivel efetuar a operacao!");
        puts("-> O numero de colunas da matriz A é diferente do numero de linhas da matriz B.");
        return -1;
    }
    
    matC = malloc(lmA * sizeof(int *));
    matA = malloc(lmA * sizeof(int *));
    matB = malloc(lmB * sizeof(int *));
    if(matA == NULL || matB == NULL || matC == NULL) {
        printf("Erro de memoria!\n");
        return -1;
    }
    for (i = 0; i < lmA; i++)
    {
        matA[i] = malloc(cmA * sizeof(int));
        if(matA[i] == NULL) {
            printf("Erro de memoria!\n");
            return -1;
        }
    }
    for (i = 0; i < lmB; i++)
    {
        matB[i] = malloc(cmB * sizeof(int));
        if(matB[i] == NULL) {
            printf("Erro de memoria!\n");
            return -1;
        }
    }
    for (i = 0; i < lmA; i++)
    {
        matC[i] = malloc(cmB * sizeof(int));
        if(matC[i] == NULL) {
            printf("Erro de memoria!\n");
            return -1;
        }
    }

    puts("\nMatriz A");
    for (i = 0; i < lmA; i++) {
        for (j = 0; j < cmA; j++)
        {
            printf("[%d,%d]: ",i,j);
            scanf("%d", &matA[i][j]);
        }  
    }
    puts("\nMatriz B");
    for (i = 0; i < lmB; i++) {
        for (j = 0; j < cmB; j++)
        {
            printf("[%d,%d]: ",i,j);
            scanf("%d", &matB[i][j]);
        }  
    }

    for (i = 0; i < lmA; i++) {
        for (j = 0; j < cmB; j++)
        {
            acumulo = 0;
            for (x = 0; x < lmB; x++) {
                acumulo += matA[i][x] * matB[x][j];
            }
            matC[i][j] = acumulo;
        }  
    }

    puts("\nMatriz C");
    for (i = 0; i < lmA; i++) {
        for (j = 0; j < cmB; j++)
        {
            printf("[%3d] ", matC[i][j]);
        } 
        printf("\n");
    }
    
    for (i = 0; i < lmA; i++) 
        free(matA[i]);
    for (i = 0; i < lmB; i++) 
        free(matB[i]);
    for (i = 0; i < lmA; i++) 
        free(matC[i]);
    free(matA);
    free(matB);
    free(matC);
    return 0;
}