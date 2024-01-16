package Exercicio6;

import Exercicio4.Ponto;

public class SegmentoReta 
{
    private Ponto ptInicial;
    private Ponto ptFinal;
    private double dimensao;
    
    public SegmentoReta(Ponto P1, Ponto P2) {
        this.ptInicial = P1;
        this.ptFinal = P2;
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