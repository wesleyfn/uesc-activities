#include <stdio.h>
/*
8. Faça um programa para ler a nota da prova de 15 alunos e armazene num vetor, calcule e
imprima a media geral.
*/
int main()
{
    double notas[15], media = 0;

    for (int i = 0; i < 15; i++)
    {
        printf("Digite a %da nota: ", i+1);
        scanf("%lf", &notas[i]);

        media += notas[i];
    }
    printf("Media: %.1lf\n", media/15);

    return 0;
}