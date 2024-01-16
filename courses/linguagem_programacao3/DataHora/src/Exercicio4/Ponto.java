package Exercicio4;

public class Ponto 
{
    private double x;
    private double y;

    public double getX() {
        return x;
    }

    public double getY() {
        return y;
    }

    public Ponto() {
        this(0f,0f);
    }

    public Ponto(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public String imprimePonto() {
        return "("+ this.x +", "+ this.y +")";
    }
}
