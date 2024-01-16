package Exercicio5;

import Exercicio4.Ponto;

public class SegmentoReta 
{
    private Ponto ptInicial;
    private Ponto ptFinal;
    private double dimensao;
    
    public SegmentoReta(double x1, double y1, double x2, double y2) {
        this.ptInicial = new Ponto(x1, y1);
        this.ptFinal = new Ponto(x2, y2);
        calculaDimensao();
    }

    public String imprimeSegmentoReta() {
        return String.format("O segmento de reta inicia no ponto %s e finaliza no ponto %s com dimensão %.1f", 
                              ptInicial.imprimePonto(), ptFinal.imprimePonto(), dimensao);
    }

    private void calculaDimensao() {
        dimensao = Math.pow(ptFinal.getX() - ptInicial.getX(), 2);
        dimensao += Math.pow(ptFinal.getY() - ptInicial.getY(), 2);
        dimensao = Math.sqrt(dimensao);
    }
}