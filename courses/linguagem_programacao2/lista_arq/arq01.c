#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, maior, menor;
    int numero;
    float media = 0;
    FILE *file;

    if ((file = fopen("arq01.txt", "r")) == NULL){
        puts("Erro ao encontrar o arquivo!");
        return -1;
    }

    for (i = 0; !feof(file); i++)
    {
        fscanf(file, "%d", &numero);
        
        if (i == 0)
            maior = menor = numero;
        else if (maior < numero) 
            maior = numero;
        else if (menor > numero) 
            menor = numero;

        media += numero;
    }
    fclose(file);

    printf("Media: %.2f\n", media/i);
    printf("Maior: %d\tMenor: %d\n", maior, menor);
    
    return 0;
}