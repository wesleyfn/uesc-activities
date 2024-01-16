public class Main {
    public static void main(String[] args) {
        Data data1 = new Data(4, 2,2001);
        Data data2 = new Data(22,5,2005);
        Contato contato = new Contato("Wesley", "wfnascimento.cic", 988656730);
        Contato contato1 = new Contato();
        Contato contato2 = new Contato("Alexandre", null, 0);

        System.out.print("Data1: ");
        data1.prtData();
        System.out.print("Data2: ");
        data2.prtData();

        System.out.println(Contato.getNumContatos());
        System.out.println("Diferenca: " + Data.diasAte(data1, data2) + " dias");
    }
}
