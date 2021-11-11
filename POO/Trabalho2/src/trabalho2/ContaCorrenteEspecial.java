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
public class ContaCorrenteEspecial extends ContaCorrente {
    
    double limiteExtra;
    double limiteMax;
       
    @Override
    public void sacar(double valor){
        if(this.saldoTotal < valor){
            if(this.limiteExtra > valor){
                this.limiteExtra = this.limiteExtra - valor;
            }
            if(valor > this.limiteExtra){
                System.out.println("Limite do extra extrapolado");
                IllegalArgumentException erro = new IllegalArgumentException();
                throw erro;
            }
        }
        else{
            this.saldoTotal = this.saldoTotal - valor ;
        }
    }
    
    @Override
    public void depositar(double valor){
        if(this.limiteExtra == this.limiteMax){
            this.saldoTotal = this.saldoTotal + valor;
        }
        else{
            this.limiteExtra = this.limiteExtra + valor;
        }
    }
    
}
