package exercicio1;
abstract class Shape2D
{
    public double dimPrincipal;

    public abstract double calcArea();
    public abstract double calcPerimetro();

    @Override
    public abstract String toString();
}