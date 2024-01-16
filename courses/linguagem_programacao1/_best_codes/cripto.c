#include <string.h>
#include <stdio.h>

int main(void)
{
    char palavra[1001], palavra2[1001];
    int casos, t, c, tam;

    printf("Digite a quantidade de casos: ");
    scanf("%d", &casos);

    for ( ; casos > 0; casos--)
    {
        printf("Caso %d: ", casos);
        scanf(" %[^\n]", palavra);

        tam = strlen(palavra);

        //for para subtrair o valor ASCII das letras da palavra em -3
        for (short int i = 0; i < tam; i++)
        {
            if((palavra[i] >= 'a' && palavra[i] <= 'z') || (palavra[i] >= 'A' && palavra[i] <= 'Z'))
            {
                palavra[i] += 3;
            }
        }
        //for para inverter a palavra solicitada
        for (t = 0, c = tam-1; t < tam; t++, c--)
        {
            palavra2[c] = palavra[t];
        }

        palavra2[t] = '\0';

        //for para subtrair o valor ASCII da metade da palavra pra frente em -1
        for (short int i = tam/2; i < tam; i++)
        {
            palavra2[i] -= 1;
        }
        printf("-> %s\n", palavra2);
    }

    return 0;
}
