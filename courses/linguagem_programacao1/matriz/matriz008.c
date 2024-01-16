#include <stdio.h>
/*
8. Leia uma matriz 5 x 5. Leia também um valor x. O programa devera fazer uma busca desse
valor na matriz e, ao final, escrever a localização (linha e coluna) ou uma mensagem de “não
encontrado”.
*/
int main()
{
    int matriz[5][5], x, igual_i, igual_j;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
        {
            printf("Digite o valor de [%d,%d]: ",i ,j);
            scanf("%d", &matriz[i][j]);
        }       
    }

    printf("\nDigite o valor que deseja buscar na matriz: ");
    scanf("%d", &x);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
        {
            if (x == matriz[i][j])
            {
                igual_i = i;
                igual_j = j;
                printf("X = [%d,%d]\n", igual_i, igual_j);
            }
        }
    }
    return 0;
}