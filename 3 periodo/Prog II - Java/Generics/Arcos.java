public class Arcos {
    private String nome;
    private int dano;

    public Arcos(String nome, int dano){
        this.nome = nome;
        this.dano = dano;
    }

    public int getDano(){
        return this.dano;
    }
    public String getNome(){
        return this.nome;
    }

}