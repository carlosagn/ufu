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
public abstract class ContaCorrente {
    
    double saldoTotal;
    
    public void sacar(double valor){
        this.saldoTotal = this.saldoTotal - valor;
    }
    
    public void depositar(double valor){
        this.saldoTotal = this.saldoTotal + valor;
    }
    
    public double obterSaldo(){
        return saldoTotal;
    }
}
