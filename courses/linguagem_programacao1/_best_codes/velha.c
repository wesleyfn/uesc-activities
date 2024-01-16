/* Jogo da "Véia"
 * O código se baseia nas regras simples do jogo da velha. Com qualquer linha vertical, 
 * horizontal ou diagonal possuindo valores idênticos na matriz o programa imprime o vencedor 
 * e encerra.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 3 

int main()
{
    setlocale(LC_ALL, "portuguese");
    char matriz[MAX][MAX] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
    char player_xo = 'O', selecionado;

    for(int cont = 0 ; cont < 9 ; )
    {
        printf("Jogo da Véia\n");
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++)
            {
                //Atribui X ou O no valor indicado da matriz e alterna os players X e O com ternário
                if(selecionado == matriz[i][j])
                {
                    matriz[i][j] = player_xo;
                    player_xo = matriz[i][j] == 'O' ? 'X' : 'O';
                    cont++;
                }
                //Imprime a matriz
                if(j == 1) {
                    printf("| %c |", matriz[i][j]);
                }
                else {
                    printf(" %c ", matriz[i][j]);
                }
            }
            printf("\n");   
        }

        //Verifica se há alguma linha com colunas idênticas na matriz
        for (int i = 0; i < MAX; i++) {
            if (matriz[i][2] == matriz[i][0] && matriz[i][0] == matriz[i][1])
            {
                printf("Vencedor: %c\n", matriz[i][0]);
                exit(0);
            }         
        }
        //Verifica se há alguma coluna com linhas idênticas na matriz
        for (int j = 0; j < MAX; j++) {
            if (matriz[2][j] == matriz[0][j] && matriz[0][j] == matriz[1][j])
            {
                printf("Vencedor: %c\n", matriz[0][j]);
                exit(0);
            }          
        }
        //Verifica se há valores idênticos na diagonal principal na matriz
        if (matriz[0][0] == matriz[1][1] && matriz[1][1] == matriz[2][2])
        {
            printf("Vencedor: %c\n", matriz[0][0]);
            exit(0);
        }
        //Verifica se há valores idênticos na diagonal secundária na matriz
        else if (matriz[0][2] == matriz[1][1] && matriz[1][1] == matriz[2][0])
        {
            printf("Vencedor: %c\n", matriz[0][2]);
            exit(0);
        }
        //Verifica se deu VELHA!
        else if (cont == 9) {
            printf("DEEU VELHA!");
        }
        //Indica onde marcar X ou O na matriz
        else 
        {
            printf("Vez de [%c]:", player_xo);
            scanf(" %c", &selecionado);
        }
        printf("\n");
    }
    return 0;
}

