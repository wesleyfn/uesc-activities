package itens;
public class Potion extends Itens{
    private double cura;

    public Potion() {
        super("Poção", 1);
    }

    public static void usarPotion() {
        
    }

    @Override
    public String toString() {
        return String.format("%dx%s", quantidade, nome);
    }
}
