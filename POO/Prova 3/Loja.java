
import javax.swing.JOptionPane;

/**
 *
 * @author Victor Borges Zuccolotto
 */
public class Loja {
    public static void main(String[] args) {
        int i;
        Produto[] itens = new Produto[5];
        try{
            itens[0] = new Produto("613653");
            itens[0].setDescricao("Travesseiro");
            itens[0].setPreco(17);
            itens[1] = new Produto("513853");
            itens[1].setDescricao("Colchao inflavel");
            itens[1].setPreco(59.99);
            itens[2] = new Produto("675033");
            itens[2].setDescricao("Barraca");
            itens[2].setPreco(168.49);
            itens[3] = new Produto("635532");
            itens[3].setDescricao("Cobertor");
            itens[3].setPreco(30);
            itens[4] = new Produto("645531");
            itens[4].setDescricao("Lampada LED");
            itens[4].setPreco(20);
          
        }        
        catch(Exception e){
            System.out.println(e.getMessage());
        }
       for( i = 0; i < 5; i++)
       		System.out.println(itens[i].toString());  

        try{
            Produto a = itens[0];
            Produto b = new Produto("617332");
            b.setDescricao("Barraca");
            i = busca(a,itens);
            if(i >= 0)
                System.out.println("Posição: " + i);
            i = busca(b,itens);
            if(i >= 0)
                System.out.println("Posição: " + i);
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }
        
        java.util.Arrays.sort(itens);
        for( i = 0; i < 5; i++)
                System.out.println(itens[i].toString());       
    }

    public static int busca(Produto a, Produto[] b){
        for(int i = 0; i<b.length;i++){
            if(a.equals(b[i])){
                return i;
            }
        }
        JOptionPane.showMessageDialog(null,"Item não encontrado");
        return -1;
    }
}