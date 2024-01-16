package exercicio1;
class Triangle extends Shape2D 
{
    private double dimPrincipal; //base
    private double ladoA;
    private double ladoB;
    private double altura;

    public Triangle() {
        this(1f, 1f, 1f);
    }

    public Triangle(Triangle triangle) {
        this(triangle.dimPrincipal, triangle.ladoA, triangle.ladoB);
    }

    public Triangle(double base, double ladoA, double ladoB) {
        if(verificarFigura(base, ladoA, ladoB)) {
            dimPrincipal = base;
            this.ladoA = ladoA;
            this.ladoB = ladoB;
            this.altura = Math.pow(ladoA,2) + Math.pow(dimPrincipal,2);
        }
        else {
            dimPrincipal = 0f;
            this.ladoA = 0f;
            this.ladoB = 0f;
            this.altura = 0f;
            System.out.println("ERRO! Altura ou base menor ou igual à zero!");
        }
    }

    public double calcArea() {
        return (dimPrincipal*altura) / 2;
    }

    public double calcPerimetro() {
        return ladoA + ladoB + dimPrincipal;
    }

    private boolean verificarFigura(double base, double ladoA, double ladoB) {
        return base > 0 && ladoA > 0 && ladoB > 0;
    }

    @Override
    public String toString() {
        return String.format("Triangle [ base: %.2f, ladoA: %.2f, ladoB: %.2f]", dimPrincipal, ladoA, ladoB);
    }
    
}