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
public abstract class Quadrilatero implements FiguraGeometrica {
    
    int lado1,lado2,lado3,lado4,area,perimetro;
        public Quadrilatero (int lado1,int lado2,int lado3,int lado4){ 
                this.lado1 = lado1; 
                this.lado2 = lado2; 
                this.lado3 = lado3; 
                this.lado4 = lado4; 
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
