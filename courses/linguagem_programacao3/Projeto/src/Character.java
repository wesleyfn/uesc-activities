public class Character 
{
    private String name;
    private int pv;
    private int xp;
    private byte level;
    private Weapons weapon;

    public String getName() {
        return name;
    }
    public int getPv() {
        return pv;
    }
    public int getXp() {
        return xp;
    }
    public byte getLevel() {
        return level;
    }
    public Weapons getWeapon() {
        return weapon;
    }

    public Character() {
        this("Fulano");
    }

    public Character(String name) {
        this.name = name;
        this.pv = 10;
        this.xp = 0;
        this.level = 1;
    }

    public void damage(int dmg) {
        this.pv -= dmg;
    }

    public void healing(int heal) {
        this.pv += heal;
    }
}
