public class Caixa<T>{
    private T item;

    public Caixa(T item){
        this.item = item;
    }

    public void guardar(T obj){
        this.item = obj;
    };

    public T pegar(){
        return item;
    };
}