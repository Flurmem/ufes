public class Bola {
    private double raio;

    public Bola(double raio) {
        this.raio = raio;
    }

    public double getRaio() {
        return raio;
    }
    
    public void setRaio(double raio){
        this.raio = raio;
    }

    @Override
    public String toString() {
        return "Bola com raio: " + raio;
    }
}