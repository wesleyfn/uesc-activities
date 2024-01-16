#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct{
    int idade;
    float salario;
    char nome[20], cpf[11];
} TTrabalhador;

TTrabalhador le_trabalhador(void);
void grava_trabalhador(TTrabalhador);

int main(void)
{
    int i;
    TTrabalhador trab[MAX];

    for (i = 0; i < MAX; i++)
    {
        trab[i] = le_trabalhador();
        grava_trabalhador(trab[i]);
    }
    return 0;
}

TTrabalhador le_trabalhador()
{
    TTrabalhador t;
    printf("Digite o nome: ");
    scanf(" %[^\n]", t.nome);
    printf("Digite a idade: ");
    scanf(" %d", &t.idade);
    printf("Digite o CPF: ");
    scanf(" %s", t.cpf);
    printf("Digite o salario: ");
    scanf(" %f", &t.salario);
    printf("\n");
    return t;
}

void grava_trabalhador(TTrabalhador t)
{
    FILE *file;

    if ((file = fopen("dados.txt", "a+")) == NULL){
        puts("Erro ao criar o arquivo!");
        exit(-1);
    }
    fprintf(file, "%-20s  ", t.nome);
    fprintf(file, "%-10d", t.idade);
    fprintf(file, "%-16s", t.cpf);
    fprintf(file, "%.2f\n", t.salario);
    
    fclose(file);
    return;
}