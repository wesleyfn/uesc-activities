package exercicio1;
class Square extends Shape2D 
{
    private double dimPrincipal;

    public Square() {
        this(1f);
    }

    public Square(Square square) {
        this(square.dimPrincipal);
    }

    public Square(double lados) {
        if(verificarFigura(lados)) {
            dimPrincipal = lados;
        }
        else {
            dimPrincipal = 0f;
            System.out.println("ERRO! Lado menor ou igual à zero!");
        }
    }

    public double calcArea() {
        return dimPrincipal*dimPrincipal;
    }

    public double calcPerimetro() {
        return 4*dimPrincipal;
    }

    private boolean verificarFigura(double lados) {
        return lados > 0;
    }

    @Override
    public String toString() {
        return String.format("Square [ lados: %.2f ]", dimPrincipal);
    }

}
