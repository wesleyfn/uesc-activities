package itens;

import java.util.ArrayList;

public class Inventario {
    
    private static ArrayList<Itens> inventario = new ArrayList<>();

    public static void add(Itens item) {
        inventario.add(item);
    }

    public static void remove(int index) {
        inventario.remove(index);
    }

    public static void print() {
        int i = 0;
        System.out.print(" 🎒 |");
        for (Itens itens : inventario) {
            System.out.print(" ["+i+"] "+ itens.toString() +" ");
            i++;
        }
        System.out.println();
    }
}
