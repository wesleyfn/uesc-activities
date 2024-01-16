#define TRUE 1
#define FALSE 0
#define LSIZE 10

// Armazenando as informacoes de um aluno
typedef struct {
  int numMatricula; //chave com 9 digitos (INT_MAX +2147483647)
  char nome[100];   // nome com até 99 caracteres
  char email[100];  // eMail com até 99 caracteres
} TAluno;

// No aluno duplamente encadeado
struct DNoAluno {
	TAluno aluno;
	struct DNoAluno* dir;
	struct DNoAluno* esq;
};

typedef struct {
	struct DNoAluno* head; 	// ponteiros para a cabeca 
	int topo;				// topo da pilha, inicialmente 0
} TPilhaEncAlunos; 			// head->prox = head -> lista vazia

typedef struct DNoAluno TNoAluno;
typedef TNoAluno *PNoAluno;

// Pilhas Lineares Encadeadas
TPilhaEncAlunos* iniPilhaEncAlunos(void);
int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha);
int desempilharAlunoEnc(TAluno* aluno, TPilhaEncAlunos* pilha);
void imprimePilha(TPilhaEncAlunos* pilha);
void liberaPilha(TPilhaEncAlunos* pilha);

typedef struct{
	TAluno* lista;
	int cap;
	int tam;
  	int eOrd;
} TListAlunos;

// Listas Lineares Sequenciais
TListAlunos* iniListAlunos(int cap, int eOrd);
TListAlunos* geraListaDeAlunos(int tam, int cap, int eOrd);
void liberaLista(TListAlunos* lista);

int buscaAluno_NOrd(TAluno lista[], int tam, int chave);
int incAluno_NOrd(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_NOrd(int chave, TAluno lista[], int *tam);

int buscaAluno_Ord(TAluno lista[], int tam, int chave);
int incAluno_Ord(TAluno aluno, TAluno lista[], int *tam, int cap);
int remAluno_Ord(int chave, TAluno lista[], int *tam);

int buscaChaveNaLista(int chave, TListAlunos *lista);
int incAlunoNaLista(TAluno aluno, TListAlunos *lista);
int remAlunoDaLista(TAluno aluno, TListAlunos *lista);

