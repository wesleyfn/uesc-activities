package itens;
public abstract class Itens 
{
    protected String nome;
    protected int quantidade;

    public String getNome() {
        return nome;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public Itens() {
        this(null, 0);
    }

    public Itens(String nome, int qtd) {
        this.nome = nome;
        this.quantidade = qtd;
    }

    
}
