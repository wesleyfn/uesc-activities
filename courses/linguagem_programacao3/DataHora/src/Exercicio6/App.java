package Exercicio6;

import Exercicio4.Ponto;

public class App {
    public static void main(String[] args) {
        Ponto ponto1 = new Ponto(0, 1);
        Ponto ponto2 = new Ponto(2, 0);
        SegmentoReta segmentoReta = new SegmentoReta(ponto1, ponto2);
        
        System.out.println("\n"+ segmentoReta.imprimeSegmentoReta());
    }
}
