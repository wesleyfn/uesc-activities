package exercicio2;

public class Pessoa
{
    private String nome;
    private long id;
    private Data nascimento;

    //Pessoa(){
    //    nascimento = new Data();
    //}

    Pessoa(String n, int i, Data d){
        nome = n;
        id = i;
        nascimento = d;
    }

    double calcEmprestimo() {
        return 1000f;
    }

    String toString1(){
        String resultado;
        resultado = "Nome: "+nome+"\nIdentidade: "+id+"\n";
        if (this.nascimento != null)
               resultado += "Data de Nascimento: "+nascimento.toStringLong();

        return resultado;
   }

}
