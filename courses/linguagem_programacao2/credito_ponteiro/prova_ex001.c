#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    float *notas, *ptr;

    printf("Digite o numero de alunos: ");
    scanf("%d", &n);

    notas = malloc(n * sizeof(float));
    if (notas == NULL) {
        puts("Erro de memoria!");
        return -1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Digite a nota do %do aluno: ", i+1);
        scanf("%f", &notas[i]);
    }

    for (ptr = &notas[1]; ptr < &notas[n]; ptr+=3)
        *ptr += 0.5;
        
    for (i = 0; i < n; i++)
    {
        printf("Aluno %d\n", i+1);
        printf(" Nota: %.2f\n", notas[i]);
    }

    free(notas);
    return 0;
}