package freezemonster.sprite;

import java.awt.Image;

import javax.swing.ImageIcon;

import freezemonster.Commons;
import spriteframework.sprite.XYPlayer;

public class Cowboy extends XYPlayer {

	@Override
	protected void loadImage() {
//		width = Commons.PLAYER_WIDTH;// scaledImage.getWidth(null);
//		height = Commons.PLAYER_HEIGHT;
		ImageIcon ii = new ImageIcon("images/cowboy.png");
		Image scaledImage = ii.getImage().getScaledInstance(Commons.PLAYER_WIDTH, Commons.PLAYER_HEIGHT, Image.SCALE_SMOOTH);
		setImage(scaledImage);
		
		imageWidth = Commons.PLAYER_WIDTH;
		imageHeight = Commons.PLAYER_HEIGHT;
	}

}
