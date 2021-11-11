/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho2;
import java.util.Scanner;

/**
 *
 * @author netoc
 */
public class Trabalho2 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
         
        Scanner entrada;
        int lad1;
        int lad2;
        int per;
        int area;  
        
        entrada = new Scanner(System.in);
        
        
        System.out.println("Informe o lado do quadrado:");
        lad1 = entrada.nextInt();
        Quadrado q = new Quadrado(lad1);
        System.out.println("Informe o lado do quadrado:");
        lad2 = entrada.nextInt();
        
        area = lad1 * lad2;  
        per = 2*lad1 + 2*lad2;  
                
        System.out.println("A area do quadrado eh " + area + " unid. area");
        System.out.println("O perimetro do quadrado eh " + per);  
    }
        
     
        
        /**    Testando o Banco
        Scanner entrada = new Scanner(System.in);
        ContaCorrenteEspecial a = new ContaCorrenteEspecial();
        a.saldoTotal = 1000;
        a.limiteExtra = 300;
        a.limiteMax = 300;
        a.sacar(500);
        a.sacar(500);
        a.depositar(400);
        a.sacar(400);
        a.sacar(400);
        **/

   
}
