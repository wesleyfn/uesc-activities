#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n, *numeros, *maior, *menor;
    float media = 0;

    printf("Digite a quantidade desejada de inteiros: ");
    scanf("%d", &n);

    numeros = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {   
        printf("Digite o %do valor: ", i+1);
        scanf("%d", (numeros+i));

        media += numeros[i];
        if (i == 0 || *maior < *(numeros+i))
            maior = (numeros+i);

        if (i == 0 || *menor > *(numeros+i))
            menor = (numeros+i);
    }
    media /= n;

    printf("\nMedia: %.2f\nMaior: %d\nMenor: %d\n", media, *maior, *menor);
    free(numeros);
    return 0;
}