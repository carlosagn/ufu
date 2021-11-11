/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author netoc
 * Nome: Carlos Augusto Gomes Neto
 * Matricula: 11821BCC016
 */
public  abstract class ContaBancaria {
    private int conta;
    private double saldo;
    
    public void sacar (double saque){
        if (this.saldo - saque < 0){
            System.out.println("Nao é possivel fazer o saque");
        }
        else{
            this.saldo = this.saldo - saque;
            System.out.println("Novo saldo: " + this.saldo);
        }
    }
    
    public void depositar (double deposito){
        if (deposito <= 0){
            System.out.println("Não é possivel fazer o depósito");
        }
        else{
            this.saldo = this.saldo + deposito;
            System.out.println("Novo saldo: " + this.saldo);
        }
    }
    
    abstract class ContaEspecial extends ContaBancaria{
        private double limite;

    public void sacar(double saque) {
      if(saldo - saque < 0){
          if(saldo + limite - saque < 0)
            System.out.println("Insuficiente");
          else{
              saldo = saldo - saque;
              System.out.println("Novo saldo: " + saldo);
              System.out.println("Limite Utilizado");
          }
        }
        else{
            saldo = saldo - saque;
            System.out.println("Novo saldo:" + saldo);
        }
    }

    public void depositar(double deposito) {
        if(deposito < 0){
            System.out.println("Invalido");
        }
        else{
            saldo = saldo + deposito;
            System.out.println("Novo saldo: " + saldo);
        }
    }
    }
    
    abstract class ContaCorrente extends ContaBancaria{
         private float taxaDeOperação;
         public void sacar (float saque){
        if(saldo - (saque + taxaDeOperação) < 0){
            System.out.println("Saldo Insuficiente");
        }
        else{
            saldo = saldo - (saque + taxaDeOperação);
            System.out.println("Novo saldo: " + saldo);
        }
    }
    public void depositar (float deposito){
         if(deposito - taxaDeOperação < 0){
            System.out.println("Valor não permitido");
        }
        else{
            saldo = saldo + (deposito - taxaDeOperação);
            System.out.println("Novo Saldo: " + saldo);
        }
    }
    }
}
