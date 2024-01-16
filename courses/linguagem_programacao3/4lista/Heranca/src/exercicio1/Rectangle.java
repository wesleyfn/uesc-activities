package exercicio1;
class Rectangle extends Shape2D 
{
    private double dimPrincipal; //largura
    private double altura;

    public Rectangle() {
        this(1f, 2f);
    }

    public Rectangle(Rectangle rectangle) {
        this(rectangle.altura, rectangle.dimPrincipal);
    }

    public Rectangle(double altura, double largura) {
        if(verificarFigura(altura, largura)) {
            dimPrincipal = largura;
            this.altura = altura;
        }
        else {
            dimPrincipal = 0f;
            this.altura = 0f;
            System.out.println("ERRO! Altura ou largura menor ou igual à zero!");
        }
    }

    public double calcArea() {
        return dimPrincipal*dimPrincipal;
    }

    public double calcPerimetro() {
        return 4*dimPrincipal;
    }

    private boolean verificarFigura(double altura, double largura) {
        return altura > 0 && largura > 0;
    }

    @Override
    public String toString() {
        return String.format("Rectangle [ altura: %.2f, largura: %.2f ]", altura, dimPrincipal);
    }
}
