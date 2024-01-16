package personagens;

import itens.Arma;

public class Heroi extends Personagens
{
    private Arma arma;
    //armadura
    private int level;

    public int getLevel() {
        return level;
    }

    public Heroi(String nome, int pvAtual, int pvMax, int xp, int atk, int def) {
        super(nome, pvAtual, pvMax, xp, atk, def);
        this.level = 1;
    }

    public Heroi(String nome) {
        this(nome, 20, 20, 0, 2, 1);
    }

    public Heroi() {
        this(null, 0, 0, 0, 0, 0);
    }

    public void adicionarXp(int add) {
        this.setXp(this.getXp() + add);
    }

    @Override
    public String toString() {
        return String.format("Nome: %s Lvl: %d\nPV: %d, XP: %d\nATK: %d, DEF: %d", nome, level, pvAtual, xp, atk, def);
    }
}
