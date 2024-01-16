#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int menu()
{
    int x;
    printf("[1] Cadastro\n[2] Leitura\n[3] Editar\n[4] Apagar\n[5] Sair\n");
    printf(":: ");
    scanf(" %d", &x);
    return x;
}

int indice()
{
    int x;
    printf("Digite o indice: ");
    scanf(" %d", &x);
    return x;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i = 0, code_produto[10] = {0}; //Vetor com 10 posições preenchidas com 0

    for(int op ; op != 5 ; op = menu())
    {
        switch (op)
        {
        case 1:
        
            i = indice();
            if(code_produto[i] == 0)
            {
                printf("Digite o novo código na posição [%d]: ", i);
                scanf(" %d", &code_produto[i]);
            }
            break;

        case 2:

            i = indice();
            printf("Código lido: %d\n", code_produto[i]);
            break;

        case 3:

            i = indice();    
            printf("Editar código na posição [%d]: ", i);
            scanf(" %d", &code_produto[i]);
            break;

        case 4:

            i = indice();
            printf("Apagando código na posição [%d]\n", i);
            code_produto[i] = 0;
            break;
        
        case 5:
            exit;
            
        default:
            break;
        }
    }
    return 0;

}
