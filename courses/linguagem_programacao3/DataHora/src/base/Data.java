package base;

public class Data 
{
    private int dia;
    private int mes;
    private int ano;
    
    public void setDia(int dia) {
        this.dia = dia;
    }
    public void setMes(int mes) {
        this.mes = mes;
    }
    public void setAno(int ano) {
        this.ano = ano;
    }

    public int getDia() { 
        return this.dia; 
    }
    public int getMes() { 
        return this.mes; 
    } 
    public int getAno() { 
        return this.ano; 
    }

    public Data() {
        this(0, 0, 0);
    }

    public Data(int dia, int mes, int ano) {
        if(isData(dia, mes, ano)){
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }
    }
    
    private boolean isData(int dia, int mes, int ano) {   
        if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || ano < 1)
            return false;
	    else {
		//Abril, Junho, Setembro, Novembro 
            if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
                if (dia <= 30)
                    return true;
                else 
                    return false;
            }
            else if (mes == 2) //Fevereiro
            {	
                if (dia == 29 && isBissexto()) {
                    return true;
                } 
                else if (dia > 29) 
                    return false;
                //Se nao for igual a 29 e nem maior ficara no intervalo (1, 28)
                return true;
            }
	    }
	    //Janeiro, Marco, Maio, Julho, Agosto, Outubro, Dezembro
	    //Se dia fica num intervalo (1, 31), mes (1, 12) e ano > 0
	    return true;
    }
    
    public boolean isBissexto() {
        return ((this.ano % 100 != 0) && (this.ano % 4 == 0)) || (this.ano % 400 == 0);
    }

    public boolean isAnterior(Data outraData) {
        if (this.ano < outraData.getAno())
            return false;
        else if (this.ano > outraData.getAno())
            return true;
        else if (this.mes < outraData.getMes())
            return false;
        else if (this.mes > outraData.getMes())
            return true;
        //Se o ano e o mes forem iguais:
        return (this.dia > outraData.getDia());
    }

    private int mesToDias() {
        if (this.mes > 0) {
            switch (this.mes) {
                case 4:
                case 6:
                case 9:
                case 11:
                    return 30;
                case 2:
                    return this.isBissexto() ? 29 : 28;
                default:
                    return 31;
            }
        }
        else
            return 0;
    }

    public static int diferencaDias(Data dataInicio, Data dataFinal) {
        int def_anos = 0;
        Data dataAux = new Data(0,0,0);
        
        dataAux.ano = dataInicio.ano;
        int idias = dataInicio.dia;
        for (int i = dataInicio.mes - 1; i > 0; --i){
            dataAux.mes = i;
            idias += dataAux.mesToDias();
        }

        dataAux.ano = dataFinal.ano;
        int fdias = dataFinal.dia;
        for (int i = dataFinal.mes - 1; i > 0; --i) {
            dataAux.mes = i;
            fdias += dataAux.mesToDias();
        }

        for (int j = dataInicio.ano; j < dataFinal.ano; ++j) {
            dataAux.ano = j;
            def_anos += 365 + (dataAux.isBissexto() ? 1 : 0);
        }

        return def_anos - idias + fdias;
    }

    public boolean isEqual(Data data2) {
        return diferencaDias(this, data2) == 0 ? true : false;
    }

    public boolean isLower(Data data2) {
        return diferencaDias(this, data2) > 0 ? true : false;
    }

    public boolean isGreather(Data data2) {
        return diferencaDias(this, data2) < 0 ? true : false;
    }

    @Override
    public String toString() {
        return String.format("%02d/%02d/%04d", this.dia, this.mes, this.ano);
    }
}

