#include "ferramentas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

  TPilhaEncAlunos *pilha = iniPilhaEncAlunos();
  TAluno aluno;

  aluno.numMatricula = 98765432;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202333312;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202020421;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202020122;
  empilharAlunoEnc(aluno, pilha);
  aluno.numMatricula = 202011230;
  empilharAlunoEnc(aluno, pilha);

  imprimePilha(pilha);

  desempilharAlunoEnc(&aluno, pilha);
  imprimePilha(pilha);
  liberaPilha(pilha);

  TFilaEncAlunos *fila = iniFilaAlunosEnc(LSIZE);
  TAluno alunoo;

  alunoo.numMatricula = 98765432;
  insereNaFilaEnc(alunoo, fila);
  alunoo.numMatricula = 202333312;
  insereNaFilaEnc(alunoo, fila);
  alunoo.numMatricula = 202020421;
  insereNaFilaEnc(alunoo, fila);
  alunoo.numMatricula = 202020122;
  insereNaFilaEnc(alunoo, fila);
  alunoo.numMatricula = 202011230;
  insereNaFilaEnc(alunoo, fila);

  imprimeFila(fila);

  removeDaFilaEnc(&aluno, fila);
  imprimeFila(fila);
  // liberaPilha(pilha);
  return 0;
}