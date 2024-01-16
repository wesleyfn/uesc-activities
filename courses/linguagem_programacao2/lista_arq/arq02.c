#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[25];
    char telefone[13];
} TAluno;

int main(void)
{
    TAluno aluno;
    FILE *file;

    if((file = fopen("arq02.txt", "w")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    for ( ; ; )
    {    
        printf("Digite o nome: ");
        fgets(aluno.nome, 255, stdin);
        if (!strcmp(aluno.nome, "\n"))
            break;

        printf("Digite o numero: ");
        fgets(aluno.telefone, 13, stdin);
        printf("\n");

        aluno.nome[strlen(aluno.nome)-1] = '\0';
        fprintf(file, "Nome: %-28s", aluno.nome);
        fprintf(file, "Telefone: %s\n", aluno.telefone);
    }

    fclose(file);
    return 0;
}