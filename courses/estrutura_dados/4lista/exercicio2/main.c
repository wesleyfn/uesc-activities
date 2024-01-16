#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ferramentas.h"

int main(void)
{
	TPilhaEncAlunos* pilha = iniPilhaEncAlunos();
    TListAlunos* lista = iniListAlunos(LSIZE, FALSE);
    lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);

//  Preenchendo pilha
    for (int i = 0; i < lista->cap; i++)
        empilharAlunoEnc(lista->lista[i], pilha); 
    imprimePilha(pilha);

//  Limpando a lista para utiliza-la como auxiliar e sorteando o aluno
    lista->tam = 0;
    int sorteado = rand() % LSIZE;
    printf("\n> Aluno sorteado: %d\n", lista->lista[sorteado].numMatricula);

//  Guardando na lista os alunos que estao acima do 
//  aluno sorteado na pilha e removendo o aluno sorteado
    while (pilha->topo-1 >= sorteado) {
        TAluno aluno;
		desempilharAlunoEnc(&aluno, pilha);
		if (pilha->topo > sorteado) {
            incAlunoNaLista(aluno, lista);
		}
	}

//  Devolvendo os alunos da lista para a pilha
	while (lista->tam-1 >= 0) {
        TAluno aluno = lista->lista[lista->tam-1];
		empilharAlunoEnc(aluno, pilha);
        remAlunoDaLista(aluno, lista);
	}
    imprimePilha(pilha);

    liberaPilha(pilha);
    liberaLista(lista);
	return 0;
}

