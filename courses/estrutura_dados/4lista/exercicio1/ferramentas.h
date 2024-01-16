#define TRUE 1;
#define FALSE 0;

// Armazenando as informações de um aluno
typedef struct {
  int numMatricula; //chave com 9 dígitos (INT_MAX +2147483647)
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
	struct DNoAluno* head; 	// Ponteiros para a cabeça 
	int topo;				// topo da pilha, inicialmente 0
} TPilhaEncAlunos; 			// head->prox = head -> lista vazia

typedef struct DNoAluno TNoAluno;
typedef TNoAluno *PNoAluno;

// Pilhas Lineares encadeadas
TPilhaEncAlunos* iniPilhaEncAlunos(void);
int empilharAlunoEnc(TAluno aluno, TPilhaEncAlunos* pilha);
int desempilharAlunoEnc(TAluno* aluno, TPilhaEncAlunos* pilha);
void imprimePilha(TPilhaEncAlunos* pilha);
void liberaPilha(TPilhaEncAlunos* pilha); //desempilha e libera toda a pilha