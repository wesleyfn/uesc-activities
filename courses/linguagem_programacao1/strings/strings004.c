#include <stdio.h>
#include <string.h>
#include <ctype.h>
/*
Uma string deve receber um nome completo de uma pessoa digitado todo em
minúsculo e em seguida colocar apenas as iniciais em maiúsculo, imprimindo o
resultado na tela.
*/
int main() {

    char nome[50];

    printf("Digite um nome completo: ");
    scanf("%[^\n]", nome);

    for (int i = 0; i < strlen(nome)+1; i++) 
    {
        if (i == 0 || nome[i-1] == ' ') {
            nome[i] = toupper(nome[i]);
        }
    }
    printf("Resultado: %s\n", nome);

    return 0;
}