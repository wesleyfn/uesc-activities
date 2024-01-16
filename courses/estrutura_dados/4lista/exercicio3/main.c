#include <stdio.h>
#include <stdlib.h>
#include "ferramentas.h"

//pilha
//[n| h |1] [h| 1 |2] [1| 2 |3] [2| 3 |h]

int main(void)
{
	TListAlunos *lista = NULL;
  lista = geraListaDeAlunos(LSIZE, LSIZE, FALSE);
  TPilhaEncAlunos *pilha1 = iniPilhaEncAlunos();
  TPilhaEncAlunos *pilha2 = iniPilhaEncAlunos();
  TPilhaEncAlunos *pilha3 = iniPilhaEncAlunos();

  for (int i = 0; i < 10; i++) {
    empilharAlunoEnc(lista->lista[i], pilha1);
    empilharAlunoEnc(lista->lista[10+i], pilha2);
    empilharAlunoEnc(lista->lista[20+i], pilha3);
  }
  printf("ALUNOS da turma a:\n");
  imprimePilha(pilha1);
  printf("ALUNOS da turma B:\n");
  imprimePilha(pilha2);
  printf("ALUNOS da turma C:\n");
  imprimePilha(pilha3);

  TFilaEncAlunos* fila=iniFilaAlunosEnc();
  insereNaFilaEnc(pilha1, fila, 'A');
  insereNaFilaEnc(pilha2, fila, 'B');
  insereNaFilaEnc(pilha3, fila, 'C');
  

	return 0;
}