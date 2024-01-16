#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que leia os dados de um aluno e os imprima na tela. Considere os
dados (nome, sobrenome, idade, telefone, sexo, email). Utilize o operador de ponto para
manipular a estrutura.
*/
typedef struct{
    char nome[10], sobrenome[30], sexo[10], email[30];
    short idade;
    long telefone;
} TAluno;

int main(void)
{
    TAluno aluno;

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", aluno.nome);

    printf("Digite o sobrenome do aluno: ");
    scanf(" %[^\n]", aluno.sobrenome);

    printf("Digite a idade do aluno: ");
    scanf("%hd", &aluno.idade);

    printf("Digite o telefone do aluno: ");
    scanf("%ld", &aluno.telefone);

    printf("Digite o sexo do aluno: ");
    scanf(" %[^\n]", aluno.sexo);

    printf("Digite o email do aluno: ");
    scanf(" %[^\n]", aluno.email);

    printf("\nInformacoes do(a) Aluno(a)");
    printf("\nNome: %s %s\nIdade: %hd\nTelefone: %ld\nSexo: %s\nEmail: %s\n",
        aluno.nome, aluno.sobrenome, aluno.idade, aluno.telefone, aluno.sexo, aluno.email);
    
    return 0;
}
