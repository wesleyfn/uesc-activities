#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa para ler e imprimir os resultados de uma turma de n alunos em uma
disciplina (matrícula, nome, sobrenome, nota). O programa devera informar o melhor
estudante, o pior estudante e a media da turma. Considere n um valor informado pelo usuário.
*/

typedef struct{
    int matricula;
    float nota;
    char nome[20], sobrenome[30];
} TAluno;

int main(void)
{
    TAluno *alunos;
    int n, i, melhor = 0, pior = 0;
    float media;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    alunos = malloc(n * sizeof(TAluno));
    if (alunos == NULL) {
        printf("Erro de memoria!");
        return -1;
    }
    
    for (i = 0; i < n; i++)
    {
        printf("\nAluno %d\n", i+1);
        printf("Digite o numero de matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Digite o nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Digite o sobrenome: ");
        scanf(" %[^\n]", alunos[i].sobrenome);
        printf("Digite a nota: ");
        scanf("%f", &(alunos[i].nota));

        if(alunos[melhor].nota < alunos[i].nota)
            melhor = i;
        if(alunos[pior].nota > alunos[i].nota)
            pior = i;

        media += alunos[i].nota;
    }
    media /= n;
    printf("\nMelhor aluno: %s %s\n", alunos[melhor].nome, alunos[melhor].sobrenome);
    printf("Pior aluno: %s %s\n", alunos[pior].nome, alunos[pior].sobrenome);
    printf("Media da turma: %.2f\n", media);

    free(alunos);
    return 0;
}
