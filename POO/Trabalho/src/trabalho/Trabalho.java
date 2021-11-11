/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalho;
import java.util.Scanner;
import java.util.Random;

/**
 * @author netoc
 * Nome do aluno: Carlos Augusto Gomes Neto
 * Matricula: 11821BCC016
 */
public class Trabalho {

    public static void main(String[] args) {
        
        String [] palavras = {"borboleta","ave","madeira","navio","palavra","macarronada","complexidade","amigo","amizade","ferro","objeto","humano","guarda","policial","besteira","groselha","picareta","estudante","rabanete","viagem","europa","oceano","sabonete","doente","dermatologista","pneumonia","respirar","garganta","amazonia","palmeiras","futebol","barcelona","madrinha","porcelana","psicologia","medicina"};
        
        int quantPalavras = palavras.length;
        char letra;
        boolean ganhou = false;
        
        Random random = new Random();
        Scanner in = new Scanner(System.in);
        
        int indiceSorteado = random.nextInt(quantPalavras);
        String palavraSorteada = (palavras[indiceSorteado]);
        String letrasUsadas = "";
        char[] acertos = new char[palavraSorteada.length()];
        for(int i = 0 ; i < acertos.length;i++){
            acertos[i] = 0;
        }
        int vidas = ((palavraSorteada.length())/2) + 1;
        
        //while true faz com que seja para sempre
        while(!ganhou && vidas > 0){
        System.out.println("\nVoce tem " + vidas + " vida(s)a" + "\nLetras utilizadas: " + letrasUsadas + "\nQual letra você palpita?");
        letra = in.next().charAt(0);
        letrasUsadas += " " + letra;
        boolean perdeVida = true;
        
        for (int i = 0; i<palavraSorteada.length() ;i++){
            if(letra == palavraSorteada.charAt(i)){
            acertos[i] = 1;
            perdeVida = false;
            }
        }
        
        if(perdeVida)
            vidas--;
        
        ganhou = true;
        for (int i = 0; i<palavraSorteada.length() ;i++){
            if(acertos[i] == 0){
                System.out.print(" _ ");
                ganhou = false;
            }
            else{
                System.out.print(" " + palavraSorteada.charAt(i) + " ");
            }
        }
        
        
    }
        System.out.println("");
        if(ganhou)
            System.out.println("Voce ganhou!!!!!");
        else
            System.out.println("Voce perdeu!\n" + "A palavra era: " + palavraSorteada + "\nTente novamente!!!" );
    }   
}
