/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho2;

/**
 *
 * @author netoc
 */
public class Quadrado extends Quadrilatero{
    
    public Quadrado(int lado) { 
            super(lado,lado,lado,lado);
            if (lado<=0){
                System.out.println("Valor inválido. O valor esperado é maior que zero");
                IllegalArgumentException erro = new IllegalArgumentException();
                throw erro;
            }
    }
    
    @Override
    public void calcularArea(){
        area = lado1 * lado2;
    }
    
    @Override
    public void calcularPerimetro(){
        perimetro = lado1 + lado2 + lado3 + lado4;
    }
    
}
