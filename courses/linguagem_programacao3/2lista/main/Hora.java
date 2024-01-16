package main;

public class Hora 
{
    private int horas;
    private int minutos;
    private int segundos;
    
    public int getHoras(){
        return this.horas;
    }
    
    public int getMinutos(){
        return this.minutos;
    }
    
    public int getSegundos(){
        return this.segundos;
    }
    
    public void inicializarHora(int horas, int minutos, int segundos){
        if(verificarHora(horas,minutos,segundos)){
            this.horas = horas;
            this.minutos = minutos;
            this.segundos = segundos;
        } 
        else 
            System.out.println("Hora invalida!");
    }
    
    private boolean verificarHora(int h, int m, int s){
        return !((h < 0 || h > 23) || (m < 0 || m > 59) || (s < 0 || s > 59));
    }

    public void mostrarHora(){
        System.out.println(this.horas+":"+this.minutos+":"+this.segundos);
    }
    
    public long converterParaSegundos(){
        return this.horas*3600 + this.minutos*60 + this.segundos;
    }
}


