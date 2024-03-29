#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ferramentas.h"

PNoAluno iniNoAluno(void)
{
	PNoAluno novo_no;
	novo_no = (TNoAluno*) malloc(sizeof(TNoAluno));

	novo_no->dir = novo_no;
	novo_no->esq = novo_no;
	return novo_no;
}

FNo* iniFNo(void)
{
	FNo* novo_no;
	novo_no = (FNo*) malloc(sizeof(FNo));
	
	novo_no->dir = novo_no;
	novo_no->esq = novo_no;
	novo_no->pilha = iniPilhaEncAlunos();
	return novo_no;
}

TPilhaEncAlunos* iniPilhaEncAlunos(void)
{
	TPilhaEncAlunos *pilha;
  pilha = (TPilhaEncAlunos*) malloc(sizeof(TPilhaEncAlunos));
  pilha->topo = 0;
  pilha->head = iniNoAluno();
	return pilha;
}

int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha)
{
	PNoAluno NoNovo = iniNoAluno();
  PNoAluno ultimo = pilha->head->esq;
	
  NoNovo->dir = pilha->head;
  NoNovo->esq = ultimo;
  ultimo->dir = NoNovo;
  pilha->head->esq = NoNovo;
	
	NoNovo->aluno = aluno;
  pilha->topo++; 
	return TRUE;
}

void liberaPilha(TPilhaEncAlunos* pilha)
{
	PNoAluno atual = pilha->head->dir;
	while(atual != pilha->head){
    atual = atual->dir;
    free(atual->esq);
  }
  free(atual);
}

void imprimePilha(TPilhaEncAlunos* pilha)
{
  printf("[ \n ");
	PNoAluno atual = pilha->head->dir;
	while(atual != pilha->head){
		printf("%d, ", atual->aluno.numMatricula);
		printf("%s, ",atual->aluno.nome);
		printf("%s;\n ", atual->aluno.email);
    atual = atual->dir;
	}
	printf(" ]\ntopo: %d\n", pilha->topo);
}
int insereNaFilaEnc(TPilhaEncAlunos* pilha, TFilaEncAlunos* fila, char chave)
{
  if (fila == NULL || pilha == NULL)
    return FALSE;
  else
  { //[u| h |1] [h| 1 |2] [1| 2 |u] [2| u |h]
    FNo* novo_no = iniFNo();
	  FNo* ultimo = fila->head->esq; //ultimo
    //sala de aula
    novo_no->chave = chave;//nome da turma
		novo_no->dir = fila->head;
		novo_no->esq = ultimo;
	  ultimo->dir = novo_no; 
		fila->head->esq = novo_no;

    //entrando os alunos
		novo_no->pilha = pilha;
    
	  fila->tam++; 
		return TRUE;
  }
}
//[u| h |1] [h| 1 |2] [1| 2 |u] [2| u |h]
//  [] [] [] [] []
//
int removeDaFilaEnc(TPilhaEncAlunos* pilha, TFilaEncAlunos* fila)
{
	if(fila->tam == 0)
		return FALSE; 
	else 
	{
    FNo* primeiro = fila->head->dir;
    FNo* segundo = primeiro->dir;
    fila->head->dir = segundo;
    segundo->esq = fila->head;  
		
		pilha = primeiro->pilha;
		liberaPilha(primeiro->pilha);
		free(primeiro);
    fila->tam--;
		return TRUE;
	}
}

void imprimeFila(TFilaEncAlunos* fila){
  FNo *atualFila = fila->head->dir;
	
	while(atualFila != fila->head){
    printf("\nTurma %c\n", atualFila->chave);
		imprimePilha(atualFila->pilha);
    atualFila = atualFila->dir;
	}
}

/*void liberaFila(TFilaEncAlunos* fila){
  PNoAluno atual = fila->head->dir;
	while(atual != fila->head){
    atual = atual->dir;
    free(atual->esq);
  }
  free(atual);
}*/




// LISTAS
TListAlunos *iniListAlunos(int cap, int eOrd) {
  TListAlunos *listaA;
  TAluno *lista;

  if (eOrd)
    lista = malloc(sizeof(TAluno) * cap);
  else
    lista = malloc(sizeof(TAluno) * (cap + 1));

  listaA = malloc(sizeof(TListAlunos));
  if (lista == NULL || listaA == NULL) {
    puts("> Falha na alocacao!");
    exit(-1);
  }
  listaA->lista = lista;
  listaA->tam = 0;
  listaA->cap = cap;
  listaA->eOrd = eOrd;
  return listaA;
}
TListAlunos *geraListaDeAlunos(int tam, int cap, int eOrd) {
  TListAlunos *lista = iniListAlunos(cap, eOrd);
  TAluno aluno;
  if (tam > cap)
    tam = cap;
  srand(time(NULL));
  int j;
  for (int i = 0, j=0; i < tam;) {
    aluno.numMatricula = (2000 + (rand() % 23)) * 100000;
    aluno.numMatricula += (aluno.numMatricula == 202200000) ? 10000 : ((rand() % 2) + 1) * 10000;
    aluno.numMatricula += (rand() % 999) + 1;
    sprintf(aluno.email, "%d@uesc.br", aluno.numMatricula);
    //sprintf(aluno.nome, "Aluno_%d", aluno.numMatricula);
    sprintf(aluno.nome, "Aluno_%d", j);
    if (incAlunoNaLista(aluno, lista))
      i++;
  }
  j++;//remover essa linha depois
  return lista;
}

int buscaAluno_NOrd(TAluno lista[], int tam, int chave) {
  lista[tam].numMatricula = chave;
  int i = 0;
  while (lista[i].numMatricula != chave)
    i++;
  return i;
}
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap) {
  if (*tam == cap)
    return FALSE; // lista cheia
  if (buscaAluno_NOrd(lista, *tam, aluno.numMatricula) == *tam) {
    lista[*tam] = aluno;
    *tam += 1;
    return TRUE;
  } else
    return FALSE;
}
int remAluno_NOrd(int chave, TAluno lista[], int *tam) {
  if (*tam == 0)
    return FALSE; // lista vazia
  int pos = buscaAluno_NOrd(lista, *tam, chave);
  if (pos < *tam) {
    *tam -= 1;
    lista[pos] = lista[*tam];
    return TRUE;
  } else
    return FALSE;
}

int buscaAluno_Ord(TAluno lista[], int tam, int chave) {
  int min = 0, max = tam, i = 0;
  while (min != max) {
    i = (max + min) / 2;
    if (lista[i].numMatricula < chave)
      min = ++i;
    else if (lista[i].numMatricula > chave)
      max = i;
    else
      return i;
  }
  return i;
}
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap) {
  if (*tam == cap)
    return FALSE; // lista cheia
  int pos = buscaAluno_Ord(lista, *tam, aluno.numMatricula);
  if (pos == *tam) {
    lista[*tam] = aluno;
    *tam += 1;
    return TRUE;
  } else {
    if (lista[pos].numMatricula != aluno.numMatricula) {
      for (int i = *tam; i > pos; i--)
        lista[i] = lista[i - 1];
      lista[pos] = aluno;
      *tam += 1;
      return TRUE;
    } else
      return FALSE;
  }
}
int remAluno_Ord(int chave, TAluno lista[], int *tam) {
  if (*tam == 0)
    return FALSE; // lista vazia
  int pos = buscaAluno_Ord(lista, *tam, chave);
  if (pos < *tam && lista[pos].numMatricula == chave) {
    for (int i = pos; i < *tam - 1; i++)
      lista[i] = lista[i + 1];
    *tam -= 1;
    return TRUE;
  } else
    return FALSE;
}

int incAlunoNaLista(TAluno aluno, TListAlunos *lista) {
  if (lista->eOrd == TRUE)
    return (incAluno_Ord(aluno, lista->lista, &lista->tam, lista->cap));
  else
    return (incAluno_NOrd(aluno, lista->lista, &lista->tam, lista->cap));
}
int remAlunoDaLista(TAluno aluno, TListAlunos *lista) {
  if (lista->eOrd == TRUE)
    return (remAluno_Ord(aluno.numMatricula, lista->lista, &lista->tam));
  else
    return (remAluno_NOrd(aluno.numMatricula, lista->lista, &lista->tam));
}
int buscaChaveNaLista(int chave, TListAlunos *lista) {
  if (lista->eOrd == TRUE)
    return (buscaAluno_Ord(lista->lista, lista->tam, chave));
  else
    return (buscaAluno_NOrd(lista->lista, lista->tam, chave));
}

void liberaLista(TListAlunos *lista) {
  free(lista->lista);
  free(lista);
}

TFilaEncAlunos* iniFilaAlunosEnc()
{
  TFilaEncAlunos* fila = (TFilaEncAlunos*)malloc(sizeof(TFilaEncAlunos));
  fila->tam = 0;
  fila->head = iniNoAluno();
	return fila;
}

