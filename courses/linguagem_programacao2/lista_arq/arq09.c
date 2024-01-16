#include <stdio.h>
#include <stdlib.h>
/*
Escreva um programa que leia o vetor do arquivo gerado no exercicio anterior. Mostre os
elementos na tela e informe a média.
*/
int main(void)
{
    int i, n;
    float x, media = 0;
    FILE *file;

    if ((file = fopen("arq08.txt", "rb")) == NULL){
        puts("Erro ao ler o arquivo!");
        return -1;
    }

    fread(&n, sizeof(int), 1, file);
    printf("Valores lidos: ");
    for (i = 0; i < n; i++)
    {
        fread(&x, sizeof(float), 1, file);
        printf("[%.1f] ", x);
        media += x;
    }

    printf("\nMedia: %.2f\n", media/n);
    fclose(file);
    return 0;
}