package main;

import java.util.ArrayList;

import construtorData.Data;

public class Agendamento 
{
    private String nome;
    private Data data;
    private ArrayList<Contato> participantes;
    private Hora horaInicio;
    private Hora duracao;

    public void inicializarAgendamento(String nome, Data data, Hora horaInicio, Hora duracao, Contato participante){
        this.nome = nome;
        this.data = data;
        this.horaInicio = horaInicio;
        this.duracao = duracao;
        this.participantes.add(participante);
    }

    public void mostrarAgenda(){
        for (Contato contato : participantes) {
            //System.out.println(contato);
            System.out.println(contato.getNome());
            System.out.println(contato.getEmail());
        }
    }
}
