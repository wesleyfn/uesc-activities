#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int numero;
    char nome[20], sexo;
    char curso[50];
} TCandidato;

int menu(void);
void prt_allCandidatos(FILE *);
void prt_selecCandidato (FILE *, int);
void set_Candidatos(FILE *, TCandidato *);

int main(void)
{
    int n;
    TCandidato c;
    FILE *file;

    if ((file = fopen("arq06.txt", "w+")) == NULL){
        puts("Erro ao abrir o arquivo!");
        return -1;
    }

    for ( ; ; )
    {  
        switch (menu())
        {
        case 1:
            printf("Digite o numero de inscricao: ");
            scanf(" %d", &c.numero);
            printf("Digite o nome: ");
            scanf(" %[^\n]", c.nome);
            printf("Digite o sexo: ");
            scanf(" %c", &c.sexo);
            printf("Digite o curso: ");
            scanf(" %[^\n]", c.curso);
            printf("\n");

            set_Candidatos(file, &c);
            break;
        case 2:
            rewind(file);
            printf("Digite o numero de inscricao: ");
            scanf(" %d", &n);

            printf("\n");
            prt_selecCandidato(file, n);         
            break;
        case 3:
            rewind(file);
            prt_allCandidatos(file);
            break;
        case 4:
            return -1;
            break;
        default:
            break;
        } 
    }
    
    fclose(file);
    return 0;
}

int menu()
{
    int op;
    printf("(1) Inserir candidato\n");
    printf("(2) Mostrar um candidato\n");
    printf("(3) Listar todos os candidatos\n");
    printf("(4) Sair do programa\n:");
    scanf(" %d", &op);
    printf("\n");
    return op;
}

void prt_allCandidatos(FILE *f)
{
    char linha[255];
    for ( ; fgets(linha, 255, f) != NULL ; )
        printf("> %s", linha);
    printf("\n");
    return;
}

void set_Candidatos(FILE *f, TCandidato *c)
{
    fprintf(f, "%010d  ", c->numero);
    fprintf(f, "%-22s  ", c->nome);
    fprintf(f, "%-4c", c->sexo);
    fprintf(f, "%s\n", c->curso);
    return;
}

void prt_selecCandidato(FILE *f, int x)
{
    int n_insc;
    char linha[255];

    fscanf(f, "%d", &n_insc);
    if (fgets(linha, 255, f) == NULL) {
        printf("> Candidato nao encontrado!\n\n");
        return;
    }
    if (x == n_insc) {
        printf(">%s\n", linha);
        return;
    }
    return prt_selecCandidato(f, x);
}