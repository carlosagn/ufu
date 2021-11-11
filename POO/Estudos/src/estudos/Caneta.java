package estudos;

/**
 *
 * @author netoc
 */
public class Caneta {
    
    private String modelo;
    private String cor;
    private float ponta;
    private Boolean tampada = true;
    
    public Caneta(){
        this.tampar();
        this.cor = "Azul";
        this.modelo = "bic";
        this.ponta = 0.5f;
    }
    
    public String getModelo(){
        return modelo;
    }
    
    public void setModelo(String m){
        this.modelo = m;
    }
    
    public float getPonta(){
        return ponta;
    }
    
    public void setPonta(float p){
        this.ponta = p;
    }
    
    public String getCor(){
        return cor;
    }
    
    public void status(){
        System.out.println("Modelo: " + this.getModelo() + "\nPonta: " + this.getPonta() + "mm\nA cor é: " + this.getCor());
    }
    
    public void tampar(){
        this.tampada = true;
        System.out.println("Está tampada");
    }
    
    public void destampar(){
        this.tampada = false;
        System.out.println("Está destampada");
    }
    
}
