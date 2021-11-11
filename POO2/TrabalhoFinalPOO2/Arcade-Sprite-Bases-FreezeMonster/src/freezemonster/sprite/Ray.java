package freezemonster.sprite;

import java.awt.Image;

import javax.swing.ImageIcon;

import freezemonster.Commons;
import spriteframework.sprite.BadSprite;

public class Ray extends BadSprite {

	public int lastDirection = 1;
	
	
	public Ray() {
		
	}
	
	public Ray(int x, int y, int lastDirection) {
		initShot(x, y);
		this.lastDirection = lastDirection;
	}

	private void initShot(int x, int y) {
			ImageIcon ii = new ImageIcon("images/ray.png");
			Image scaledImage = ii.getImage().getScaledInstance(Commons.GOSMA_WIDTH, Commons.GOSMA_HEIGHT, Image.SCALE_SMOOTH); 
			setImage(scaledImage);

			super.imageWidth = Commons.GOSMA_WIDTH -10;
			super.imageHeight = Commons.GOSMA_HEIGHT -10;
		int H_SPACE = 6;
		setX(x + H_SPACE);

		int V_SPACE = 1;
		setY(y - V_SPACE);
	}
}
