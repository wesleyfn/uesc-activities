package Exercicio8;

public class Contato 
{
    private String nome;
    private String email;
    private long telefone;

    public Contato(){
        this(null, null, 0);
    }
    
    public Contato(String nome, String email, long telefone){
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
    }

    public String getNome(){
        return this.nome;
    }
    
    public String getEmail(){
        return this.email;
    }
    
    public long getTelefone(){
        return this.telefone;
    }
    
    @Override
    public String toString() {
        return String.format("Nome: %s, Email: %s, Telefone: %d", nome, email, telefone);
    }
}
