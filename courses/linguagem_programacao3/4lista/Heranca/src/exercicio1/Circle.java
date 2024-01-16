package exercicio1;
class Circle extends Shape2D 
{
    private double dimPrincipal;
    private double PI = 3.14159;

    public double getRaio() {
        return dimPrincipal;
    }

    public Circle() {
        this(1f);
    }

    public Circle(Circle circle) {
        this(circle.dimPrincipal);
    }

    public Circle(double raio) {
        if(verificarFigura(raio)) {
            dimPrincipal = raio;
        }
        else {
            dimPrincipal = 0f;
            System.out.println("ERRO! Raio menor ou igual à zero!");
        }
    }

    public double calcArea() {
        return PI * (dimPrincipal*dimPrincipal);
    }

    public double calcPerimetro() {
        return 2*PI * dimPrincipal;
    }

    private boolean verificarFigura(double raio) {
        return raio > 0;
    }

    @Override
    public String toString() {
        return String.format("Circle [ raio: %.2f ]", dimPrincipal);
    }
}
