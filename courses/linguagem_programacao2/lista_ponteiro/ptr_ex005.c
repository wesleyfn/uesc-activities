#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int main(void)
{
    float *prova1, *prova2;
    float media_aluno, media_prova1 = 0, media_prova2 = 0;
    int i, j;

    prova1 = malloc(MAX * sizeof(float));
    prova2 = malloc(MAX * sizeof(float));
    if(prova1 == NULL || prova2 == NULL) {
        printf("ERRO!");
        return -1;
    }

    for (i = 0; i < MAX; i++)
    {
        printf("Aluno %d\n", i+1);
        printf("Digite a nota da prova 1: ");
        scanf("%f", &prova1[i]);
        printf("Digite a nota da prova 2: ");
        scanf("%f", &prova2[i]);
        printf("\n");
        media_prova1 += prova1[i];
        media_prova2 += prova2[i];
    }

    for (i = 0; i < MAX; i++)
    {
        media_aluno = (prova1[i] + prova2[i])/2;
        printf("Aluno %d:\n", i+1);
        printf("Media: %.2f\n", media_aluno);
        printf("%s\n\n", media_aluno >= 7.0 ? "[Aprovado]" : "[Reprovado]");
    }

    media_prova1 /= MAX;
    media_prova2 /= MAX;

    puts("Turma:");
    printf("Media da prova 1: %.2f\n", media_prova1);
    printf("Media da prova 2: %.2f\n", media_prova2);
    
    free(prova1);
    free(prova2);
    return 0;
}