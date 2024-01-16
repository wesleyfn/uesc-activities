#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
Faça um programa que recebe um nome completo de uma pessoa, transforme as iniciais
em maiúsculo e depois imprima no formato “Último_nome, Nome”.
*/
int main() {

    char nome[50], ultimo[50] = {0};

    printf("Digite um nome completo: ");
    scanf(" %[^\n]", nome);

    for (int i = 0; i < strlen(nome)+1; i++) 
    {
        if (i == 0 || nome[i-1] == ' ') {
            nome[i] = toupper(nome[i]);
        }
    }

    for (int x = 0, y = strlen(nome)-1; nome[y] != ' '; y--, x++){
        ultimo[x] = nome[y];   
    }
    for (int i = strlen(nome)-1; i >= 0 ; i--){
        printf("%c", ultimo[i]);
    }
    printf(", %s\n", strtok(nome, " "));
    

    return 0;
}