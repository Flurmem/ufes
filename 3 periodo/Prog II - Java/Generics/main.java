import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.List;




class main{
    public static void main(String[] args){
        // List<Pessoa> pessoas = new ArrayList<>();
        // pessoas.add(new Pessoa("Pedro", 10));
        // pessoas.add(new Pessoa("Riana", 9));
        // Collections.sort(pessoas);
        // for(Pessoa pessoa:pessoas){
        //     System.out.println(pessoa.getNome() + ' ' + pessoa.getIdade());
        // }
        
        // Comparator<Pessoa> porNome = new Comparator<>(){
        //     @Override
        //     public int compare(Pessoa p1, Pessoa p2){
        //         return p1.getNome().compareTo(p2.getNome());
        //     }
        // };

        // Collections.sort(pessoas, porNome);
        // for(Pessoa pessoa:pessoas){
        //     System.out.println(pessoa.getNome() + ' ' + pessoa.getIdade());
        // }

        // List<String> palavras = new ArrayList<>();

        // palavras.add("Pedro");
        // palavras.add("Luciana");

        // Iterator<String> it = palavras.iterator();

        // while (it.hasNext()){
        //     String nome = it.next();

        //     if (nome.startsWith("A")){
        //         it.remove();
        //     }
        // }
        // List<Par> pares = new ArrayList<>();
        // pares.add(new Par<>("Pedro", 10));
        // pares.add(new Par<>("Luciana", 9));

        // Comparator<Par> porIdade = new Comparator<>(){
        //     @Override
        //     public int compare(Par p1, Par p2){
        //         if (p1.getValor() > p2.getValor()){
        //             return 1;
        //         }
        //         else if (p1.getValor() < p2.getValor()){
        //             return -1;
        //         }
        //         else{
        //             return 0;
        //         }
        //     }
        // };
        
        // Collections.sort(pares, porIdade);
        // for ( Par par : pares){
        //     System.out.println(par.getChave());
        // }

        List<Armas<String>> armas = new ArrayList<>();
        armas.add(new Armas("St jhon", 10));
        armas.add(new Armas("Arco de fogo", 9));
        armas.add(new Armas("Espada de gelo", 8));
        armas.add(new Armas("Arco de gelo", 7));
        armas.add(new Armas("Espada de fogo", 14));
        armas.add(new Armas("Arco de madeira", 18));
        armas.add(new Armas("Espada de madeira", 12));

        Iterator<Armas<String>> it = armas.iterator();
        while (it.hasNext()){
            String arma = (String) it.next().getArma();
            if (arma.contains("Arco")){
                it.remove();
            }
        }

        Collections.sort(armas);

        for(Armas a: armas){
            System.out.println(a.getArma() + " " + a.getDano());
        }

        // Comparator<Armas<String>> peloNome = new Comparator<>(){
        //     @Override
        //     public int compare(Armas<String> a1, Armas<String> a2){
        //         return  a1.getArma().compareTo(a2.getArma());
        //     }
        // };

        // Collections.sort(armas, peloNome);

        
        // for(Armas a: armas){
        //     System.out.println(a.getArma() + " " + a.getDano());
        // }

        
        }
}