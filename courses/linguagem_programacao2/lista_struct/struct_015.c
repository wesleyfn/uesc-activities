#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
Modifique o programa anterior para que a agenda de telefone seja impressa na 
ordem alfabética. Sugestão: Construa a lista de forma que cada vez que seja lida
uma nova entrada seja colocada na posição correta (ver figura).
*/
typedef struct item{
    char nome[255];
    char tel[13];
    struct item *next;
} TItem;

int main(void)
{
    char nome[255];
    struct item *buff;
    TItem *raiz = NULL, *last, *checkpoint;

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
        
        //last->next = NULL;
        strcpy(last->nome, nome);

        printf("Digite o numero de telefone: ");
        scanf(" %[^\n]", last->tel);
        printf("\n");

        if (raiz->next != NULL)
        {
            checkpoint = last;
            last = raiz;
            printf("\n\n%s\n\n", last->nome);
            printf("\n\n%s\n\n", last->next->nome);
            for (char *p = last->nome; *p ; p++) *p = tolower(*p);
            for (char *p = last->next->nome; *p ; p++) *p = tolower(*p);
            if (strcmp(last->nome, last->next->nome) > 0)
            {
                //buff = malloc(sizeof(TItem));
                buff = last;
                printf("\nbuff = %s\tlast = %s\n", buff->nome, last->nome);
                last = last->next;
                printf("last = ");
                puts(last->nome);
                last->next = buff;
                printf("\n\n%s\n\n", last->next->nome);
                free(buff);
            }
            last = checkpoint;
        }

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
    free(checkpoint);
    return 0;
}