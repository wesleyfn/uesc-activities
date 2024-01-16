#include <stdio.h>
#include "bib_funcoes.h"

int main(void)
{
    int i, j, flag;

    for (i = 0; i < 101; i++)
    {
        flag = isPerfeito(i);
        if (flag)
        {
            printf("Perfeito: %d = ", i);
            for (j = i; j > 1; j--)
                if (i%j == 0) printf("%d ", i/j);
            printf("\n");
        }
    }
    return 0;
}