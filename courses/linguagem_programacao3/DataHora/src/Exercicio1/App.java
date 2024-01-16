package Exercicio1;
public class App {
    public static void main(String[] args) throws Exception 
    {
        DataHora dataHora1 = new DataHora(4, 2, 2001, 3, 42, 22);
        DataHora dataHora2 = new DataHora();

        System.out.println("\nDataHora1: "+ dataHora1.toString());
        System.out.println("DataHora2: "+ dataHora2.toString());

        System.out.print("==? "+ dataHora1.isEqual(dataHora2));
        System.out.print(" , <? "+ dataHora1.isLower(dataHora2));
        System.out.println(" , >? "+ dataHora1.isGreather(dataHora2) +"\n");
    }
}
