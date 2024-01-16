package itens;
public class Armadura extends Itens{
    private int def;

    public int getAtk() {
        return def;
    }

    public Armadura(String nome, int def) {
        super(nome, 1);
        this.def = def;
    }

    @Override
    public String toString() {
        return String.format("%dx%s 🛡 %d", quantidade, nome, def);
    }
}
