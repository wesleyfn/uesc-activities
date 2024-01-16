#include <stdio.h>
#include <stdlib.h>
#include "data.h"

struct Data {
	int dia;
	int mes;
	int ano;
};

/* Verifica se a data eh valida*/
int dataIsValida(int dia, int mes, int ano);
int verificarBissexto();

Data* new_Data(void) {
	Data *data;
	data = malloc(sizeof(Data));
	if (data == NULL) {
		puts("Erro de alocacao!");
		exit(-1);
	}
	return data;
}

void del_Data(Data *data) {
	free(data);
	return;
}

int verificarBissexto(int ano){
	return ((ano % 100 != 0) && (ano % 4 == 0)) || ano % 400 == 0;
}

int dataIsValida(int dia, int mes, int ano)
{
	if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || ano < 1)
        return 0;
	else {
	//Abril, Junho, Setembro, Novembro 
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            if (dia <= 30)
                return 1;
            else 
                return 0;
        }
		else if (mes == 2) //Fevereiro
		{	
			if (dia == 29 && verificarBissexto(ano)) {
				return 1;
			} 
			else if (dia > 29) 
				return 0;
			//Se nao for igual a 29 e nem maior ficara no intervalo (1, 28)
			return 1;
		}
	}
	//Janeiro, Marco, Maio, Julho, Agosto, Outubro, Dezembro
	//Se dia fica num intervalo (1, 31), mes (1, 12) e ano > 0
	return 1;
}

char* getDiaSemana(Data *data) 
{
	int d = data->dia;
	int m = data->mes;
	int a = data->ano;
	char* diaSemana[] = {
		"sabado", "domingo", "segunda-feira", "terca-feira", 
		"quarta-feira", "quinta-feira", "sexta-feira"
	};

	if (m == 1 || m == 2) {
		m = (m == 1) ? 13 : 14;
		a--;
	}

	int calculo = d + 2*m + ((3*(m+1))/5) + a + a/4 - a/100 + a/400 + 2;
	return diaSemana[calculo%7];
}

int setData(Data *data, int dia, int mes, int ano) {
	if (dataIsValida(dia, mes, ano)) {
		data->dia = dia;
		data->mes = mes;
		data->ano = ano;
		return 1;
	}
	data->dia = 0;
	data->mes = 0;
	data->ano = 0;
	puts("Data invalida!");
	return 0;
}

void prtData(Data *data)
{
	printf("%02d/%02d/%04d\n", data->dia, data->mes, data->ano);
	return;
}

