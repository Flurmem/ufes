
public class main{
    public static void main(String[] args) {

        Formas<Object> formas = new Formas<>();

        formas.adicionarForma(new Bola(5));
        formas.adicionarForma(new Quadrado(56));
        formas.mostrarFormas();
    }
}