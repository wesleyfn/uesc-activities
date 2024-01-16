#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Considere a seguinte estrutura para representar uma entrada de uma agenda de telefone
typedef struct item{
char nome[255];
char telefone[13];
struct item *ptr;
}Titem;
Escreva um programa que receba um número arbitrário de entradas da agenda e ao terminar a
leitura de dados imprima elas na mesma ordem que foram digitadas. Sugestão: Construa uma
lista enlaçada segundo a seguinte figura.
*/

typedef struct item{
    char nome[255];
    char tel[13];
    struct item *next;
} TItem;

int main(void)
{
    char nome[255];
    TItem *raiz = NULL, *last;

    printf("Digite o nome (0 para finalizar): ");
    scanf(" %[^\n]", nome);

    for ( ;nome[0] != '0'; )
    {
        if (raiz == NULL)
        {
            raiz = malloc(sizeof(TItem));
            last = raiz; 
        }
        else
        {
            last->next = malloc(sizeof(TItem));
            last = last->next;
        }
        if (last == NULL){
            puts("Erro de memoria!");
            return -1;
        }
        
        last->next = NULL;
        strcpy(last->nome, nome);
        printf("Digite o numero de telefone: ");
        scanf(" %[^\n]", last->tel);
        printf("\n");

        printf("Digite o nome (0 para finalizar): ");
        scanf(" %[^\n]", nome);

    }
    
    if (raiz != NULL)
    {
        printf("\nAgenda Telefonica:");    
        for (;raiz != NULL;)
        {
            last = raiz;
            printf("\nNome: %s\nTelefone: %s\n",last->nome, last->tel);
            raiz = last->next;
            free(last);
        }
    }
    
    return 0;
}