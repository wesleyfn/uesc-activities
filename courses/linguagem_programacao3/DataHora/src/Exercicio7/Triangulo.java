package Exercicio7;

import Exercicio4.Ponto;

public class Triangulo 
{
    private Ponto ptA, ptB, ptC;
    private double dimAB, dimBC, dimCA; //Dimensões

    public double getDimAB() {
        return dimAB;
    }
    public double getDimBC() {
        return dimBC;
    }
    public double getDimCA() {
        return dimCA;
    }

    public Triangulo(Ponto A, Ponto B, Ponto C) {
        if(isTriangulo(A, B, C)) {
            ptA = A;
            ptB = B;
            ptC = C;
            
            //Dimensões aproximadas dos segmentos de reta
            dimAB = Math.round(Math.sqrt(Math.pow(B.getX() - A.getX(), 2) + Math.pow(B.getY() - A.getY(), 2)));
            dimBC = Math.round(Math.sqrt(Math.pow(C.getX() - B.getX(), 2) + Math.pow(C.getY() - B.getY(), 2)));
            dimCA = Math.round(Math.sqrt(Math.pow(A.getX() - C.getX(), 2) + Math.pow(A.getY() - C.getY(), 2)));
        }
        else {
            ptA = null;
            ptB = null;
            ptC = null;
            dimAB = 0f;
            dimBC = 0f;
            dimCA = 0f;
            System.out.println("Os pontos informados nao formam um triangulo!");
        }
    }

    public String imprimeTriangulo() {
        if(ptA != null)
            return "A"+ptA.imprimePonto()+" B"+ptB.imprimePonto()+" C"+ptC.imprimePonto();
        else
            return null;
    }

    private boolean isTriangulo(Ponto A, Ponto B, Ponto C) 
    {
        double determinante;
        determinante = A.getX()*B.getY() + A.getY()*C.getX() + B.getX()*C.getY();
        determinante -= B.getY()*C.getX() + A.getX()*C.getY() + A.getY()*B.getX();
        return determinante != 0 ? true : false;
    }
 
    public boolean isTrianguloRetangulo() 
    {
        if(ptA != null) {
            if(dimAB > dimBC && dimAB > dimCA) {
                return dimAB*dimAB == (dimBC*dimBC + dimCA*dimCA);
            }
            else if(dimBC > dimAB && dimBC > dimCA) {
                return dimBC*dimBC == (dimAB*dimAB + dimCA*dimCA);
            }
            else {
                return dimCA*dimCA == (dimBC*dimBC + dimAB*dimAB);
            }
        }
        else
            return false;
    }
 
    public boolean isTrianguloEquilatero() {
        return (dimAB == dimBC) && (dimBC == dimCA) && ptA != null;
    }

    public boolean isTrianguloIsosceles() 
    {
        if(!(isTrianguloEquilatero()) && (ptA != null)) {
            if(dimAB == dimBC || dimBC == dimCA || dimCA == dimAB) {
                return true;
            }
        }
        return false;
    }
}
