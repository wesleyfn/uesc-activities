#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char usuario_code[15], livro_code[15],
        titulo[30], genero[15], autor[30];
} TLivro;

int main(void)
{
    int n, i;
    TLivro *livro, *ptr;

    printf("Digite o numero de livros: ");
    scanf("%d", &n);

    livro = malloc(n * sizeof(TLivro));
    if (livro == NULL){
        puts("Erro de memoria!");
        return -1;
    }
    
    for (i = 0; i < n; i++)
    {
        printf("\nDigite os dados do Livro %d\n", i+1);
        printf("-> Codigo do usuario: ");
        scanf(" %[^\n]", livro[i].usuario_code);
        printf("-> Titulo do livro: ");
        scanf(" %[^\n]", livro[i].titulo);
        printf("-> Codigo do livro: ");
        scanf(" %[^\n]", livro[i].livro_code);
        printf("-> Genero do livro: ");
        scanf(" %[^\n]", livro[i].genero);
        printf("-> Nome do autor: ");
        scanf(" %[^\n]", livro[i].autor);
    }

    puts("\nLivros do genero [Policial]: ");
    puts("Code      Titulo");
    for (ptr = livro; ptr < &livro[n]; ptr++)
    {
        for (i = 0; ptr->genero[i] != '\0'; i++){ //deixa todos os caracteres minusculos
            ptr->genero[i] = tolower(ptr->genero[i]); 
        }
        if (strcmp(ptr->genero, "policial") == 0)
        {
            printf("%-10s", ptr->livro_code);
            printf("%s\n", ptr->titulo);
        }  
    }
    free(livro);
    return 0;
}