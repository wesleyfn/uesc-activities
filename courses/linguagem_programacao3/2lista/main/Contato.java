package main;

public class Contato 
{
    private String nome;
    private String email;
    private String telefone;
    
    public String getNome(){
        return this.nome;
    }
    
    public String getEmail(){
        return this.email;
    }
    
    public String getTelefone(){
        return this.telefone;
    }
    
    public void inicializaContato(String nome, String email, String telefone){
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
    }
    
    public void mostrarContato() {
        System.out.println(this.nome);
        System.out.println(this.email);
        System.out.println(this.telefone);
    }
    
    
}
