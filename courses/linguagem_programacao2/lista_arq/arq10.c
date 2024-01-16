#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char placa[7];
    float km, consumo;
} TVeiculo;

int main(void)
{   
    int i, n;
    FILE *file;
    TVeiculo veiculo;

    if ((file = fopen("arq010.txt", "wb")) == NULL){
        puts("Erro ao ler o arquivo!");
        return -1;
    }

    printf("Digite o numero de veiculos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nVeiculo %d\n", i+1);
        printf("Digite a placa: ");
        scanf("%s", veiculo.placa);

        printf("Digite o numero de km percorridos: ");
        scanf("%f", &veiculo.km);

        printf("Digite o consumo de combustivel: ");
        scanf("%f", &veiculo.consumo);

        fwrite(&veiculo, sizeof(TVeiculo), 1, file);
    }
    
    fclose(file);
    return 0;
}