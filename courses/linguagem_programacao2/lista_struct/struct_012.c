#include <stdio.h>
#include <stdlib.h>
/*
Faça um programa para processar os resultados de um torneio de futebol de areia onde
participaram n equipes. Para cada equipe considere: nome da equipe, jogos ganhos, jogos
empatados, jogos perdidos, número de cartões amarelos, número de cartões vermelhos, goles
a favor, goles em contra e saldo. Seu programa deverá informar:
a) Nome da equipe que ganhou o torneio (jogos ganhos = 3 pontos, jogos empatados =
1ponto). Desconsidere o caso que duas equipes alcançaram o mesmo número de
pontos.
b) Nome da equipe que teve o melhor ataque.
c) Nome da equipe que teve a melhor defesa.
d) Nome da equipe Fair Play, os cartões vermelhos têm peso 2 e os amarelhos peso 1.
*/
typedef struct{
    char nome[30]; //nome da equipe
    int jg, je, jp; //jogos ganhos, empatados e perdidos
    int ca, cv; //castoes amarelos e vermelhos
    int gf, gc, sg; //gols a favor, contra e saldo de gols
    int pts; //pontos ganhos (jg * 3, + empate);
} TEquipe;

int main(void)
{
    int i, n;
    int maior_gf = 0, menor_gc = 0, won = 0, fairplay = 0;
    TEquipe *equipe;

    printf("Digite o numero de equipes: ");
    scanf("%d", &n);

    equipe = malloc(n * sizeof(TEquipe));
    if (equipe == NULL){
        puts("Erro de memoria!");
        return -1;
    }
    for (i = 0; i < n; i++)
    {
        printf("Dados da %da equipe\n", i+1);
        printf("Nome: ");
        scanf(" %[^\n]", equipe[i].nome);
        printf("Jogos ganhos: ");
        scanf(" %d", &equipe[i].jg);
        printf("Jogos empatados: ");
        scanf("%d", &equipe[i].je);
        printf("Jogos perdidos: ");
        scanf("%d", &equipe[i].jp);
        printf("Cartoes amarelos: ");
        scanf("%d", &equipe[i].ca);
        printf("Cartoes vermelhos: ");
        scanf("%d", &equipe[i].cv);
        printf("Gols a favor: ");
        scanf("%d", &equipe[i].gf);
        printf("Gols contra: ");
        scanf("%d", &equipe[i].gc);

        equipe[i].sg = equipe[i].gf - equipe[i].gc;
        equipe[i].pts = (3 * equipe[i].jg) + equipe[i].je;

        if (equipe[i].pts > equipe[won].pts)
            won = i;
        if (equipe[i].gf > equipe[maior_gf].gf)
            maior_gf = i;
        if (equipe[i].gc < equipe[menor_gc].gc)
            menor_gc = i;
        if ((equipe[i].ca + equipe[i].cv*2) < (equipe[fairplay].ca + equipe[fairplay].cv*2))
            fairplay = i;
        
        printf("\n");
    }
    
    printf("\nEquipe vencedora: %s\n", equipe[won].nome);
    printf("Equipe com melhor ataque: %s\n", equipe[maior_gf].nome);
    printf("Equipe com melhor defesa: %s\n", equipe[menor_gc].nome);
    printf("Equipe Fair Play do torneio: %s\n", equipe[fairplay].nome);

    free(equipe);
    return 0;
}