#include <stdio.h>
#include <stdlib.h>
/*
11.A seguinte estrutura representa uma sequência de números inteiros
Typedef{
int *val;
int n;
int max;
int min;
float media;
}TSeq;
Escreva um programa que declare uma variável de tipo Tseq e realize as seguintes operações:
a) Recebe a quantidade de elementos da sequência n.
b) Aloca dinamicamente um vetor para armazenar os valores da sequência (val) e lê
eles via teclado.
c) Calcula os atributos da sequência máximo (max), mínimo (min) e média (media).
d) Mostra todos os atributos da sequência na tela.
*/
typedef struct{
    int n, max, min;
    int *val;
    float media;
} TSeq;

int main(void)
{   
    int i;
    TSeq seq;
    seq.media = 0.0;

    printf("Digite o numero de valores: ");
    scanf("%d", &seq.n);

    seq.val = malloc(seq.n * sizeof(int));
    if (seq.val == NULL){
        puts("Erro de memoria!");
        return -1;
    }
    
    for (i = 0; i < seq.n; i++)
    {
        printf("Digite o %do valor: ", i+1);
        scanf("%d", &seq.val[i]);
        if(seq.val[i] > seq.max || i == 0) seq.max = seq.val[i];
        if(seq.val[i] < seq.min || i == 0) seq.min = seq.val[i];
        seq.media += seq.val[i];
    }

    seq.media /= seq.n;
    printf("n: %d\nmax: %d\nmin: %d\nmedia: %.2f\n",
        seq.n, seq.max, seq.min, seq.media);
    
    printf("seq: ");
    for (i = 0; i < seq.n; i++)
        printf("[%d] ", seq.val[i]);
    printf("\n");

    free(seq.val);
    return 0;
}