package Exercicio8;

import java.util.ArrayList;

public class App {
    public static void main(String[] args) 
    {
        ArrayList<Agendamento> agenda = new ArrayList<>();
        Contato contato = new Contato("Alex", "alx21@gmail.com", 988686130);
        Contato contato2 = new Contato("Heitor", "htr22@gmail.com", 988859466);
        
        Agendamento agendamento = new Agendamento(
            "Encontro com Heitor e Alex", 
            1,1,2001, 7,30,0, 1,0,0, contato
        );

        agendamento.addParticipante(contato2);
        agenda.add(agendamento);

        agendamento = new Agendamento(
            "Encontro com Heitor", 
            8,1,2001, 9,0,0, 1,0,0, contato2
        );

        agenda.add(agendamento);

        for (Agendamento agendamentos : agenda) {
            agendamentos.prtAgendamentos();
            System.out.println();
        }
    }
}
