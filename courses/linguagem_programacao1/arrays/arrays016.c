#include <stdio.h>
/*
16. Faça um programa que leia dez conjuntos de dois valores, o primeiro representando o numero
do aluno e o segundo representando a sua altura em metros. Encontre o aluno mais baixo e o
mais alto. Mostre o número do aluno mais baixo e do mais alto, juntamente com suas alturas.
*/
int main()
{
    const int max = 3;
    int aluno[max];
    double altura[max];

    for (int i = 0; i < max; i++)
    {
        printf("Número do %do aluno: ", i+1);
        scanf("%d", &aluno[i]);
        printf("Altura do %do aluno: ", i+1);
        scanf("%lf", &altura[i]);
        printf("\n");

        
    }

    for (int i = 0; i < max; i++)
    {
        /* code */
    }
    
    
    return 0;
}
