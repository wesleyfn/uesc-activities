package Exercicio2;

import base.Data;
import base.Hora;

public class App {
    public static void main(String[] args) throws Exception 
    {
        Data data = new Data(4,2,2001);
        Hora hora = new Hora(3,42,22);
        DataHora dataHora1 = new DataHora(data, hora);

        Data data2 = new Data(4,2,2001);
        Hora hora2 = new Hora(3,42,22);
        DataHora dataHora2 = new DataHora(data2, hora2);

        System.out.println("\nDataHora1: "+ dataHora1.toString());
        System.out.println("DataHora2: "+ dataHora2.toString());

        System.out.print("==? "+ dataHora1.isEqual(dataHora2));
        System.out.print(" , <? "+ dataHora1.isLower(dataHora2));
        System.out.println(" , >? "+ dataHora1.isGreather(dataHora2) +"\n");
    }
}
