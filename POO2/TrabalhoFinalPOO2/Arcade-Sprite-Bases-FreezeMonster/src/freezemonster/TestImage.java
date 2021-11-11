package freezemonster;

import java.awt.Graphics;
import java.awt.Image;
import java.util.Iterator;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel; 
public class TestImage extends JPanel {	 

   // Colocar a pasta image na raiz do projeto 
   String imageLocation = "images/player.png";   
   ImageIcon ii = new ImageIcon("images/player.png"); 
   Image scaledImage = ii.getImage().getScaledInstance(30, 50, Image.SCALE_SMOOTH); 
 
    
   public static void main (String args[]) {
	   Random randomForDirection = new Random();
	   for(int i = 0 ; i< 100;i++) {
		   System.out.println(randomForDirection.nextInt(15));
	   }
	   
	   String teste = "oi@oi";
	   int oi = 1;
	   
	   System.out.println(teste.replace('@', Integer.toString(oi).charAt(0)));
      JFrame i = new JFrame(); 
      TestImage ip = new TestImage(); 
      i.add(ip); 
      i.setSize(200, 200); 
      i.setVisible(true); 
      i.repaint(); 
   } 
     
   public void paintComponent (Graphics g) { 
      g.drawImage(scaledImage, 40, 60, this); 
   } 
} 