#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    float *vetor;
    FILE *file;

    printf("Digite o numero de valores que deseja: ");
    scanf("%d", &n);

    vetor = malloc(n * sizeof(float));
    if (vetor == NULL){
        puts("Erro de memoria!");
        return -1;
    }
    
    if ((file = fopen("arq08.txt", "wb")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("Digite o valor para [%d]: ", i);
        scanf("%f", &vetor[i]);
    }
    
    fwrite(&n, sizeof(int), 1, file);
    fwrite(vetor, sizeof(float), n, file);

    fclose(file);
    return 0;
}