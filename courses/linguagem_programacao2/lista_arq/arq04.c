#include <stdio.h>
#include <time.h>

int main(void)
{
    int quant, code;
    char descricao[20];
    float valor;
    FILE *file;
    time_t timer;

    if ((file = fopen("arq04.txt", "a+")) == NULL){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    for ( ; ; )
    {
        printf("Digite o codigo (0 para encerrar): ");
        scanf("%d", &code);
        if (code == 0) break;

        printf("Digite o descricao: ");
        scanf(" %[^\n]", descricao);

        printf("Digite a quantidade: ");
        scanf(" %d", &quant);

        printf("Digite o valor: ");
        scanf("%f", &valor);
        printf("\n");
        
        timer = time(NULL);

        fprintf(file, "%010d  ", code);
        fprintf(file, "%-23s  ", descricao);
        fprintf(file, "%-7d", quant);
        fprintf(file, "%-10.2f", valor);
        fprintf(file, "%s", ctime(&timer));
    }

    fclose(file);
    return 0;
}