package Exercicio8;

import java.util.ArrayList;
import base.*;

public class Agendamento 
{
    private String nome;
    private Data data;
    private Hora horaInicio, duracao;
    private ArrayList<Contato> participantes;

    public Agendamento(String nome, int d, int m, int a, int hInicio, int mInicio, int sInicio, 
                       int hDuracao, int mDuracao, int sDuracao, Contato participante)
    {
        this.nome = nome;
        this.data = new Data(d, m, a);
        this.horaInicio = new Hora(hInicio, mInicio, sInicio);
        this.duracao = new Hora(hDuracao, mDuracao, sDuracao);
        this.participantes = new ArrayList<>();
        addParticipante(participante);
    }

    public void addParticipante(Contato participante)
    {
        this.participantes.add(participante);
    }

    public void prtAgendamentos() {
        System.out.format("> %s - %s\n  Inicio: %s, Duracao: %s\n", 
                             nome, data.toString(), horaInicio.toString(), duracao.toString());      
        
        System.out.format("  Participantes:\n");
        for (Contato contato : participantes) {
            System.out.format("\t%s\n", contato.toString());
        }
    }
}
