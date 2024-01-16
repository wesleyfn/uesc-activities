#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int quantTransacoes(FILE *);

int main(void)
{
    int n, quant, mais_unidades;
    char aux[50], art_unidades[20], art_dinheiro[20];
    float caixa = 0, valor, mais_dinheiro;
    FILE *file;

    if((file = fopen("arq04.txt", "r")) == NULL){
        puts("Erro ao ler o arquivo!");
        return -1;
    }

    n = quantTransacoes(file);
    printf("Numero total de transacoes: %d\n", n);

    rewind(file);
    for (int i = 0; i < n; i++)
    {
        fgets(aux, 13, file);
        fgets(aux, 24, file);
        fscanf(file, "%d", &quant);
        fscanf(file, "%f", &valor);

        if (i == 0)
        {
            mais_unidades = quant;
            mais_dinheiro = quant * valor;
        }

        if (mais_unidades < quant)
        {
            strcpy(art_unidades, aux);
            mais_unidades = quant;
        }

        if (mais_dinheiro < quant * valor)
        {
            strcpy(art_dinheiro, aux);
            mais_dinheiro = quant * valor;
        }

        fgets(aux, 255, file);
        caixa += quant * valor;
    }
    printf("Saldo de caixa: %.2f\n", caixa);
    printf("Artigo que vendeu mais: %s\n", art_unidades);
    printf("Artigo que proporcionou mais dinheiro: %s\n", art_dinheiro);

    fclose(file);
    return 0;
}

int quantTransacoes(FILE *f)
{
    int i;
    char linha[255];
    for (i = -1; !feof(f); i++)
        fgets(linha, 255, f);
    return i;
}