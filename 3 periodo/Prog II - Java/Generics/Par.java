public class Par<K, V>{
    private String chave;
    private Integer valor;

    public Par(String chave, Integer valor){
        this.chave = chave;
        this.valor = valor;
    }

    public String getChave(){
        return this.chave;
    }

    public Integer getValor(){
        return this.valor;
    }
    
}