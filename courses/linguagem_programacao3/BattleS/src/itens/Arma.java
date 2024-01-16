package itens;
public class Arma extends Itens{
    private int atk;
    
    public int getAtk() {
        return atk;
    }

    public Arma(String nome, int atk) {
        super(nome, 1);
        this.atk = atk;
    }

    @Override
    public String toString() {
        return String.format("%dx%s 🗡 %d", quantidade, nome, atk);
    }
}
