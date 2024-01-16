package Exercicio2;

import base.Data;
import base.Hora;

public class DataHora 
{
    private Data data;
    private Hora hora;
    
    public Data getData() {
        return this.data;
    }
    public Hora getHora() {
        return this.hora;
    }
    
    public DataHora(Data data, Hora hora) {
        this.data = data;
        this.hora = hora;
    }
    
    @Override
    public String toString() {
        return this.data.toString() +", "+ this.hora.toString();
    }
    
    public boolean isEqual(DataHora dataHora2) {
        return this.data.isEqual(dataHora2.data) && this.hora.isEqual(dataHora2.hora);
    }

    public boolean isGreather(DataHora dataHora2) 
    {
        if (this.data.isEqual(dataHora2.data)) 
            return this.hora.isGreather(dataHora2.hora);
        else if (this.data.isGreather(dataHora2.data)) 
            return true;
        else 
            return false;
    }

    public boolean isLower(DataHora dataHora2) {
        if(!this.isEqual(dataHora2))
            return !this.isGreather(dataHora2);
        return false;
    }
}
