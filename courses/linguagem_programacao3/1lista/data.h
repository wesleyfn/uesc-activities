typedef struct Data Data; //Estrutura opaca

/* Retorna um objeto do tipo Data */
Data* new_Data(void);

/* Deleta o objeto do tipo Data e libera memoria */
void del_Data(Data *data);

/* Retorna o dia da semana ex. segunda-feira */
char* getDiaSemana(Data *data);

/* Retorna o mes */
int getMes(Data *data);

/* Retorna o ano */
int getAno(Data *data);

/* Inicializa o objeto do tipo Data */
int setData(Data *data, int dia, int mes, int ano);

/* Mostra os atributos do objeto do tipo Data no console */
void prtData(Data *data);
