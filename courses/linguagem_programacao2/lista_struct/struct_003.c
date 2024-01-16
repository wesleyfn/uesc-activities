#include <stdio.h>
#include <stdlib.h>
/*
Reescreva o programa anterior alocando memória dinamicamente para a estrutura.
*/
typedef struct{
    char nome[10], sobrenome[30], sexo[10], email[30];
    short idade;
    long telefone;
} TAluno;

int main(void)
{
    TAluno *ptr;

    ptr = malloc(sizeof(TAluno));
    if(ptr == NULL) {
        printf("Erro de memoria!"); 
        return -1;
    }

    printf("Digite o nome do aluno: ");
    scanf(" %[^\n]", ptr->nome);

    printf("Digite o sobrenome do aluno: ");
    scanf(" %[^\n]", ptr->sobrenome);

    printf("Digite a idade do aluno: ");
    scanf("%hd", &ptr->idade);

    printf("Digite o telefone do aluno: ");
    scanf("%ld", &ptr->telefone);

    printf("Digite o sexo do aluno: ");
    scanf(" %[^\n]", ptr->sexo);

    printf("Digite o email do aluno: ");
    scanf(" %[^\n]", ptr->email);

    printf("\nInformacoes do(a) Aluno(a)");
    printf("\nNome: %s %s\nIdade: %hd\nTelefone: %ld\nSexo: %s\nEmail: %s\n",
        ptr->nome, ptr->sobrenome, ptr->idade, ptr->telefone, ptr->sexo, ptr->email);
    
    free(ptr);
    return 0;
}
