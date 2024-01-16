#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float *prova1, *prova2;
    float media_aluno = 0, media_prova1 = 0, media_prova2 = 0;
    int i, j, n;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);
    printf("\n");

    prova1 = malloc(n * sizeof(float));
    prova2 = malloc(n * sizeof(float));
    if(prova1 == NULL || prova2 == NULL) {
        printf("ERRO!");
        return(-1);
    }

    for (i = 0; i < n; i++)
    {
        printf("Aluno %d:\n", i+1);
        printf("Digite a nota da prova 1: ");
        scanf("%f", &prova1[i]);
        printf("Digite a nota da prova 2: ");
        scanf("%f", &prova2[i]);
        printf("\n");
        media_prova1 += prova1[i];
        media_prova2 += prova2[i];
    }

    for (i = 0; i < n; i++)
    {
        media_aluno = (prova1[i] + prova2[i])/2;
        printf("Aluno %d:\n", i+1);
        printf("Media: %.2f\n", media_aluno);
        printf("%s\n\n", media_aluno >= 7.0 ? "[Aprovado]" : "[Reprovado]");
    }

    media_prova1 /= n;
    media_prova2 /= n;

    puts("Media da Turma:");
    printf("Prova 1: %.2f\n", media_prova1);
    printf("Prova 2: %.2f\n", media_prova2);
    free(prova1);
    free(prova2);
    return 0;
}