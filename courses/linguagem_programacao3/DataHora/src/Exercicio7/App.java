package Exercicio7;

import Exercicio4.Ponto;

public class App {
    public static void main(String[] args) 
    {
        Ponto pontoA = new Ponto(1, 1.7);
        Ponto pontoB = new Ponto(0, 0);
        Ponto pontoC = new Ponto(2, 0);
        Triangulo triangulo = new Triangulo(pontoA, pontoB, pontoC);
        
        System.out.println("\n"+ triangulo.imprimeTriangulo());
        System.out.println("isTrianguloRetangulo: "+ triangulo.isTrianguloRetangulo());
        System.out.println("isTrianguloEquilatero: "+ triangulo.isTrianguloEquilatero());
        System.out.println("isTrianguloIsosceles: "+ triangulo.isTrianguloIsosceles());
        System.out.println();
    }
}
