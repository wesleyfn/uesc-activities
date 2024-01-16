#include <stdio.h>
#include <stdlib.h>
#include "ferramentas.h"

PNoAluno iniNoAluno(void){
	PNoAluno novo_no;
	novo_no = (TNoAluno*) malloc(sizeof(TNoAluno));
    novo_no->dir = novo_no;
    novo_no->esq = novo_no;
    return novo_no;
}

TPilhaEncAlunos* iniPilhaEncAlunos(void)
{
	TPilhaEncAlunos* pilha = malloc(sizeof(TPilhaEncAlunos));
	pilha->head = iniNoAluno();
	pilha->head->dir = pilha->head;
	pilha->head->esq = pilha->head;
    
	pilha->topo = 0;
    return pilha;
}

void liberaPilha(TPilhaEncAlunos* pilha)
{
    PNoAluno atual = pilha->head->dir;
    while (atual != pilha->head) {
        atual = atual->dir;
        free(atual->esq);
    }
    free(atual);
    free(pilha);
}//desempilha e libera toda a pilha

int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha)
{
    if (pilha != NULL)
    {
        PNoAluno ultimo = pilha->head->esq;
        PNoAluno novo_no = iniNoAluno();

        novo_no->dir = pilha->head;
        novo_no->esq = ultimo;
        novo_no->aluno = aluno;

        ultimo->dir = novo_no;
        pilha->head->esq = novo_no;
        pilha->topo++;
        return TRUE;  
    }
    else
        return FALSE;
}

int desempilharAlunoEnc(TAluno* aluno, TPilhaEncAlunos* pilha)
{
    if (pilha->topo > 0) 
    {
        PNoAluno ultimo = pilha->head->esq;
        PNoAluno penultimo = ultimo->esq;

        penultimo->dir = pilha->head;
        pilha->head->esq = penultimo;
        pilha->topo--;

        *aluno = ultimo->aluno;
        free(ultimo);
        return TRUE;
    } 
    else 
        return FALSE;
}

void imprimePilha(TPilhaEncAlunos* pilha)
{
    printf("[ \n ");
	PNoAluno atual = pilha->head;
	while(atual->dir != pilha->head) {
		atual = atual->dir;
		printf("%d, ", atual->aluno.numMatricula);
		printf("%s, ", atual->aluno.nome);
		printf("%s;\n ", atual->aluno.email);
	}
	printf(" ]\ntopo: %d\n", pilha->topo);
    return;
}


