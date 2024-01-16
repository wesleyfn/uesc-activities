#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, x, n, *vet, *verificados, cont, flag;

    printf("Digite o numero de valores: ");
    scanf("%d", &n);

    vet = malloc(n * sizeof(int));
    verificados = malloc(n * sizeof(int));
    if(vet == NULL || verificados == NULL) {
        printf("Erro de memoria!\n");
        return -1;
    }

    for(i = 0; i < n; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", (vet+i));
    }

    for(i = 0; i < n; i++) 
    {
        cont = 0;
        flag = 1;
        for(x = 0; x < n; x++){
            if(verificados[x] == vet[i]) {
                flag = 0;
            }
        }
        if(flag) {
            verificados[i] = vet[i];
            for(j = i; j < n; j++)
            { 
                if(vet[i] == vet[j]) 
                    cont++;
            }
            if(cont > 1) printf("%d se repete %d vezes\n", vet[i], cont);
        }
    }

    free(vet);
    free(verificados);
    return 0;
}