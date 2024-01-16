#include <stdio.h>
#include <stdlib.h>
#define QFILE 4

int main(void)
{
    int n_maq;
    char data_quant[20];
    FILE *fmain, *fmaq1, *fmaq2, *fmaq3;

    if ((fmain = fopen("arq07.txt", "r")) == NULL){
        puts("Erro ao ler o arquivo!");
        return -1;
    }
    if (((fmaq1 = fopen("arq07-1.txt", "w")) == NULL) || 
        ((fmaq2 = fopen("arq07-2.txt", "w")) == NULL) ||
        ((fmaq3 = fopen("arq07-3.txt", "w")) == NULL)){
        puts("Erro ao criar o arquivo!");
        return -1;
    }

    for ( ; !feof(fmain) ; )
    {
        fscanf(fmain, "%d  ", &n_maq);
        fgets(data_quant, 20, fmain);

        switch (n_maq)
        {
        case 1:
            fprintf(fmaq1, "%s", data_quant);
            break;
        case 2:
            fprintf(fmaq2, "%s", data_quant);
            break;
        case 3:
            fprintf(fmaq3, "%s", data_quant);
            break;                    
        default:
            break;
        }   
    }

    fclose(fmain);
    fclose(fmaq1);
    fclose(fmaq2);
    fclose(fmaq3);
    puts("Programa finalizado!");
    return 0;
}

