//package construtorData;
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
        setData(0, 0, 0);
    }

    public Data(int dia, int mes, int ano) {
        setData(dia, mes, ano);
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
    
    private void setData(int dia, int mes, int ano) {
        if(isData(dia, mes, ano)){
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }
    }
    
    public void prtData() {
        System.out.println(this.dia+"/"+this.mes+"/"+this.ano);
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
        return (this.dia <= outraData.getDia() ? false : true);
    }

    private int mesToDias() {
        if (this.mes > 0) {
        if (this.mes == 4 ||this.mes == 6 || this.mes == 9 || this.mes == 11)
            return 30;
        else if (this.mes == 2)
            return this.isBissexto() ? 29 : 28;
        else
            return 31;
        }
        else
            return 0;
    }

    public static int diasAte(Data idata, Data fdata) {
        int def_anos = 0;
        Data aux = new Data(0,0,0);
        
        aux.ano = idata.ano;
        int idias = idata.dia;
        for (int i = idata.mes - 1; i > 0; --i){
            aux.mes = i;
            idias += aux.mesToDias();
        }

        aux.ano = fdata.ano;
        int fdias = fdata.dia;
        for (int i = fdata.mes - 1; i > 0; --i) {
            aux.mes = i;
            fdias += aux.mesToDias();
        }

        for (int j = idata.ano; j < fdata.ano; ++j) {
            aux.ano = j;
            def_anos += 365 + (aux.isBissexto() ? 1 : 0);
        }

        return def_anos - idias + fdias;
    }
}

