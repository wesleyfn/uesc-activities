package exercicio2;
class App {
    public static void main(String[] args) {
        Data dataNasc = new Data(30, 11, 1975);
        //Pessoa pessoaSimple = new Pessoa("Jose Cuervo", 234517, dataNasc);
        //System.out.println("PESSOA:\n"+pessoaSimple.toString()+"\n\n");

        Data dataAdm = new Data(18, 2, 2005);
        //Funcionario pessoaFuncionario = new Funcionario("Jose Cuervo", 234517, dataNasc, dataAdm, 3500.00);
        //System.out.println("FUNCIONARIO:\n"+pessoaFuncionario.toString()+"\n\n");

        Data dataChefe = new Data(22, 3, 2018);
        ChefeDepartamento pessoaChefe = new ChefeDepartamento("Jose Cuervo", 234517, dataNasc, dataAdm, 3500.00, "CCAM", dataChefe);
        System.out.println("CHEFE DE DEPARTAMENTO:\n"+pessoaChefe.toString1());
    }
}
