package base;
public class Hora 
{
    private int horas;
    private int minutos;
    private int segundos;
    
    public Hora() {
        this(0, 0, 0);
    }
    
    public Hora(int hora, int min, int seg){
        if(isHora(hora, min, seg)){
            this.horas = hora;
            this.minutos = min;
            this.segundos = seg;
        } 
        else 
            System.out.println("Hora inválida!");
    }
    
    public int getHoras(){
        return this.horas;
    }
    public int getMinutos(){
        return this.minutos;
    }
    public int getSegundos(){
        return this.segundos;
    }
    
    private boolean isHora(int hora, int min, int seg){
        return !((hora < 0 || hora > 23) || (min < 0 || min > 59) || (seg < 0 || seg > 59));
    }
     
    public long toSegundos(){
        return this.horas*3600 + this.minutos*60 + this.segundos;
    }

    public boolean isEqual(Hora hora2) {
        return this.toSegundos() == hora2.toSegundos() ? true : false;
    }

    public boolean isLower(Hora hora2) {
        return this.toSegundos() < hora2.toSegundos() ? true : false;
    }

    public boolean isGreather(Hora hora2) {
        if(!this.isEqual(hora2))
            return !this.isLower(hora2);
        return false;
    }

    @Override
    public String toString(){
        return String.format("%02d:%02d:%02d", this.horas, this.minutos, this.segundos);
    }
}
