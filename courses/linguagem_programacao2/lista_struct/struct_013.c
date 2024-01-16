#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[15]; //nome da equipe
    int jg, je, jp; //jogos ganhos, empatados e perdidos
    int ca, cv; //castoes amarelos e vermelhos
    int gf, gc, sg; //gols a favor, contra e saldo de gols
    int pts; //pontos ganhos (jg * 3, + empate);
} TEquipe;

int main(void)
{
    int i, n, buffer, flag, *s;
    TEquipe *equipe;

    printf("Digite o numero de equipes: ");
    scanf("%d", &n);

    equipe = malloc(n * sizeof(TEquipe));
    s = malloc(n * sizeof(int));
    if (equipe == NULL || s == NULL){
        puts("Erro de memoria!");
        return -1;
    }
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("Dados da equipe %d\n", i+1);
        printf("-> Nome: ");
        scanf(" %[^\n]", equipe[i].nome);
        printf("-> Vitorias: ");
        scanf(" %d", &equipe[i].jg);
        printf("-> Empates: "); 
        scanf("%d", &equipe[i].je);
        printf("-> Derrotas: ");
        scanf("%d", &equipe[i].jp);
        printf("-> Cartoes Amarelos: ");
        scanf("%d", &equipe[i].ca);
        printf("-> Cartoes Vermelhos: ");
        scanf("%d", &equipe[i].cv);
        printf("-> Gols a favor: ");
        scanf("%d", &equipe[i].gf);
        printf("-> Gols contra: ");
        scanf("%d", &equipe[i].gc);

        equipe[i].sg = equipe[i].gf - equipe[i].gc;
        equipe[i].pts = (3 * equipe[i].jg) + equipe[i].je;
        
        s[i] = i;
        printf("\n");
    }

    do { //Bubble Sort
        flag = 0;
        for(i = 0; i < n-1; i++)
        {
            if (equipe[s[i]].pts < equipe[s[i+1]].pts)
            {
                buffer = s[i];
                s[i] = s[i+1];
                s[i+1] = buffer;
                flag = 1;
            }
        }
    } while (flag);
    
    printf("Nome            JG  JE  JP  CA  CV  GF  GC  SG  Pts\n");
    printf("---------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%-15s %-3d %-3d %-3d %-3d", 
                equipe[s[i]].nome, 
                equipe[s[i]].jg, 
                equipe[s[i]].je, 
                equipe[s[i]].jp, 
                equipe[s[i]].ca);
        printf(" %-3d %-3d %-3d %-3d %d\n", 
                equipe[s[i]].cv, 
                equipe[s[i]].gf, 
                equipe[s[i]].gc, 
                equipe[s[i]].sg, 
                equipe[s[i]].pts);
    }
    printf("---------------------------------------------------\n");

    free(s);
    free(equipe);
    return 0;
}