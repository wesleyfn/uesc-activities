public class Contato 
{
    private String nome;
    private String email;
    private long telefone;
    static private int num_contatos = 0;
    
    public Contato() {
        this("Fulano",null,0);
    }
    public Contato(String nome, String email, long tel) {
        this.nome = nome;
        this.email = email;
        this.telefone = tel;
        num_contatos++;
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

    public static int getNumContatos() {
        return num_contatos;
    }

    public void setNome(String nome){
        this.nome = nome;
    }
    
    public void setEmail(String email){
        this.email = email;
    }
    
    public void setTelefone(long tel){
        this.telefone = tel;
    }
    
    public void mostrarContato() {
        System.out.println(this.nome);
        System.out.println(this.email);
        System.out.println(this.telefone);
    }
    
    
}
