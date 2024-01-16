package exercicio2;

public class Funcionario extends Pessoa
{
    private Data admissao;
    double salario;

    Funcionario(String nome, int id, Data nascm, Data adm, double sal) {
        super(nome, id, nascm);
        admissao = adm;
        salario = sal;
    }

    //private, protected, package
    public String toString(){
        String resultado;
        resultado = super.toString1()+"\n"; // chama o método toString da classe Pessoa.Pessoa
        resultado = resultado + "Data de admissão: "+admissao.toStringLong()+"\n";
        resultado = resultado + "Salário: R$ "+salario;

        return resultado;
    }

    final public double qualSalario(){
        return salario;
    }

    double calcEmprestimo() {
        if((salario*0.75f) > super.calcEmprestimo()) {
            return salario;
        }
        return super.calcEmprestimo();
    }
}
