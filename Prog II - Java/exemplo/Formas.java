import java.util.ArrayList;
import java.util.List;

public class Formas<T>{
    private List<T> formas;

    public Formas(){
        this.formas = new ArrayList<>();
    }

    public void adicionarForma(T forma){
        formas.add(forma);
    }

    public void mostrarFormas(){
        for(T forma : formas){
            System.out.println(forma);
        }
    }
}