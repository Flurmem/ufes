public class Quadrado {
    private double lado;

    public Quadrado(double lado) {
        this.lado = lado;
    }

    public double getLado() {
        return lado;
    }
    
    public void setLado(double lado){
        this.lado = lado;
    }

    @Override
    public String toString() {
        return "Quadrado com lado: " + lado;
    }
}