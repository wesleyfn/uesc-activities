package main;

public class Data 
{
    private int dia;
    private int mes;
    private int ano;
    
    public int getDia(){
        return this.dia;
    }
    
    public int getMes(){
        return this.mes;
    }
    
    public int getAno(){
        return this.ano;
    }
    
    private boolean verificarData(int dia, int mes, int ano){   
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
                if (dia == 29 && verificarBissexto()) {
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
    
    public void inicializarData(int dia, int mes, int ano){
        if(verificarData(dia, mes, ano)){
            this.dia = dia;
            this.mes = mes;
            this.ano = ano;
        }
        else 
            System.out.println("Data invalida!");
    }
    
    public void mostrarData(){
        System.out.println(this.dia+"/"+this.mes+"/"+this.ano);
    }
    
    public boolean verificarBissexto(){
        return ((ano % 100 != 0) && (ano % 4 == 0)) || ano % 400 == 0;
    }
}
