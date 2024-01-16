#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, idade;
    char nome[25], matricula[10];
    char sexo, email[50];
    FILE *file;

    if ((file = fopen("arq03.txt", "w")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    printf("\n");
    for (i = 0; i < n; i++)
    {   
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);
        
        printf("Digite a matricula: ");
        scanf(" %s", matricula);

        printf("Digite o sexo [M/F]: ");
        scanf(" %c", &sexo);

        printf("Digite a idade: ");
        scanf(" %d", &idade);

        printf("Digite o email: ");
        scanf(" %s", email);
        printf("\n");

        fprintf(file, "%-28s", nome);
        fprintf(file, "%-13s", matricula);
        fprintf(file, "%-6c", sexo);
        fprintf(file, "%-6d", idade);
        fprintf(file, "%s\n", email);
    }
    
    fclose(file);
    return 0;
}
