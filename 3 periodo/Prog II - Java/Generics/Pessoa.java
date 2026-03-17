public class Pessoa implements Comparable<Pessoa> {
    private String nome;
    private int idade;

    public Pessoa(String nome, int idade){
        this.nome = nome;
        this.idade = idade;
    }

    public void setIdade(int idade){
        this.idade = idade;
    }

    public int getIdade(){
        return idade;
    }

    public String getNome(){
        return nome;
    }

    public void setNome(String nome){
        this.nome = nome;
    }

    @Override
    public int compareTo(Pessoa p){
        int result = 0;

        if(this.idade < p.getIdade()){
            result = -1;
        }
        else if(this.idade > p.getIdade()){
            result = 1;
        }
        return result;
    }
}