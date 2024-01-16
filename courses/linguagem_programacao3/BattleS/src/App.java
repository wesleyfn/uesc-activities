import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

import itens.*;
import personagens.*;


public class App {
    public static void main(String[] args) throws Exception 
    {
        
        //System.out.print("Digite o nome do seu personagem: ");

        
        Itens arma = new Arma("Espada", 8);
        Itens armadura = new Armadura("Blusa", 1);
        Itens potion = new Potion();

        Inventario.add(arma);
        Inventario.add(armadura);
        Inventario.add(potion);
        Inventario.print();

        Inventario.remove(0);
        Inventario.print();

        //////////////////////////////////////

        System.out.println("\nArquivos: ");
        File file = new File("teste.txt");
        Scanner fscan = new Scanner(file);

        System.out.println("Existe: "+ file.exists());

        
        Heroi heroi = new Heroi(fscan.nextLine(), fscan.nextInt(), fscan.nextInt(), fscan.nextInt(), fscan.nextInt(), fscan.nextInt());
        System.out.println(heroi.toString());


        fscan.close();
    }
}
