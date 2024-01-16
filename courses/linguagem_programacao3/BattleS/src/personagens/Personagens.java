package personagens;
public abstract class Personagens 
{
    protected String nome;
    protected int pvAtual, pvMax;
    protected int xp, atk, def;

    public String getNome() {
        return nome;
    }
    public int getPvAtual() {
        return pvAtual;
    }
    public int getPvMax() {
        return pvMax;
    }
    public int getXp() {
        return xp;
    }
    public int getAtk() {
        return atk;
    }
    public int getDef() {
        return def;
    }
    
    /*public void setPv(int pv) {
        this.pv = pv;
    }*/
    public void setXp(int xp) {
        this.xp = xp;
    }

    public Personagens(String nome, int pvAtual, int pvMax, int xp, int atk, int def) {
        this.nome = nome;
        this.pvAtual = pvAtual;
        this.pvMax = pvMax;
        this.xp = xp;
        this.atk = atk;
        this.def = def;
    }

    public Personagens() {
        this(null, 0, 0, 0, 0, 0);
    }

    public void adicionarPv(int add) {
        pvAtual = pvAtual + add;
        if(pvAtual > pvMax) pvAtual = pvMax;
    }

    public void subtrairPv(int sub) {
        adicionarPv(-sub);
        if(pvAtual < 0) pvAtual = 0;
    }

    @Override
    public String toString() {
        return String.format("Nome: %s\nPV: %d, XP: %d\nATK: %d, DEF: %d", nome, pvAtual, xp, atk, def);
    }
}
