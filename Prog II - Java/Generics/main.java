
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

class main{
    public static void main(String[] args){
        List<Pessoa> pessoas = new ArrayList<>();
        pessoas.add(new Pessoa("Pedro", 10));
        pessoas.add(new Pessoa("Riana", 9));
        Collections.sort(pessoas);
        for(Pessoa pessoa:pessoas){
            System.out.println(pessoa.getNome() + ' ' + pessoa.getIdade());
        }
        
        Comparator<Pessoa> porNome = new Comparator<>(){
            @Override
            public int compare(Pessoa p1, Pessoa p2){
                return p1.getNome().compareTo(p2.getNome());
            }
        };

        Collections.sort(pessoas, porNome);
        for(Pessoa pessoa:pessoas){
            System.out.println(pessoa.getNome() + ' ' + pessoa.getIdade());
        }
        }
}