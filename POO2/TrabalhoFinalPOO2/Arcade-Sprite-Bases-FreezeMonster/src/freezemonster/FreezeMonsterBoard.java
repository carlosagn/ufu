package freezemonster;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.KeyEvent;
import java.util.LinkedList;
import java.util.Random;

import javax.swing.ImageIcon;

import freezemonster.sprite.Cowboy;
import freezemonster.sprite.Gosma;
import freezemonster.sprite.Monster;
import freezemonster.sprite.Ray;
import spriteframework.AbstractBoard;
import spriteframework.sprite.BadSprite;
import spriteframework.sprite.Sprite;
import spriteframework.sprite.XYPlayer;

public class FreezeMonsterBoard extends AbstractBoard {
	private Ray shot;

	private int deaths = 0;

	private String explImg = "images/monster@bg.png";

	protected void createBadSprites() { // create sprites
		for (int i = 0; i < 9; i++) {
			Monster monstro = new Monster(Commons.ALIEN_INIT_X + 18 * i, Commons.ALIEN_INIT_Y + 30 * i,
					"images/monster" + (i + 1) + ".png");
			badSprites.add(monstro);
		}
	}

	protected void createOtherSprites() {
		shot = new Ray();
	}

	private void drawShot(Graphics g) {

		if (shot.isVisible()) {

			g.drawImage(shot.getImage(), shot.getX(), shot.getY(), this);
		}
	}

	// Override
	protected void drawOtherSprites(Graphics g) {
		drawShot(g);
	}

	protected void processOtherSprites(XYPlayer player, KeyEvent e) {
		int x = player.getX();
		int y = player.getY();

		int key = e.getKeyCode();

		if (key == KeyEvent.VK_SPACE) {

			if (inGame) {

				if (!shot.isVisible()) {

					shot = new Ray(x, y, player.lastDirection);
				}
			}
		}
	}

	protected void update() {
		
		verfiyGameWon();
		
		for (XYPlayer player : players)
			player.act();
		
		shotUpdate();
		
		updateMonster();

		updateOtherSprites();

	}

	private void updateOtherSprites() {
		Random generator = new Random();

		for (BadSprite monster : badSprites) {

			int rdm = generator.nextInt(15);
			Gosma gosma = ((Monster) monster).getBomb();

			monsterShot(monster, rdm, gosma);

			int gosmax = gosma.getX();
			int gosmay = gosma.getY();

			checkCollisionGosmaAndCowboy(gosma);

			gosmaMovement(gosma, gosmax, gosmay);

			destroyGosma(gosma, gosmax, gosmay);
		}
	}

	private void monsterShot(BadSprite monster, int rdm, Gosma gosma) {
		if (rdm == Commons.CHANCE && !monster.isFreezing() && gosma.isDestroyed()) {
			gosma.setVisible(true);
			gosma.setDestroyed(false);
			gosma.setX(monster.getX());
			gosma.setY(monster.getY());
			gosma.setDx(monster.getDx() * -2);
			gosma.setDy(monster.getDy() * -2);
		}
	}

	private void checkCollisionGosmaAndCowboy(Gosma gosma) {
		if (players.get(0).isVisible() && !gosma.isDestroyed()) {

			if(checkCollision(gosma, players.get(0))) {
				players.get(0).setDying(true);
				gosma.setDestroyed(true);
			}
		}
	}

	private void destroyGosma(Gosma gosma, int gosmax, int gosmay) {
		if (!gosma.isDestroyed()) { //se tiro pega na gosma ambos destroem-se
			if (gosmax >= (shot.getX() - 10) && gosmax <= (shot.getX() + 10) && gosmay >= (shot.getY() - 10)
					&& gosmay <= (shot.getY() + 10)) {
				shot.die();
				gosma.setDestroyed(true);
			}
		}
	}

	private void gosmaMovement(Gosma gosma, int gosmax, int gosmay) {
		if (!gosma.isDestroyed()) { //movimento da gosma
			gosma.setY(gosmay + gosma.getDy());
			gosma.setX(gosmax + gosma.getDx());

			if (gosma.getY() >= Commons.BOARD_HEIGHT - 60 || gosma.getX() >= Commons.BOARD_WIDTH - 35
					|| gosma.getX() <= 0 || gosma.getY() <= 0) {

				gosma.setDestroyed(true);
			}

		}
	}
	
	private boolean checkCollision(Sprite s, Sprite z) {
		if(s.getX() >= z.getX() && s.getX() <= z.getX() + z.getImageWidth() && s.getY() >= z.getY() && s.getY() <= z.getY() + z.getImageHeight())
			return true;
		if(s.getX() + s.getImageWidth() >= z.getX() && s.getX() + s.getImageWidth() <= z.getX() + z.getImageWidth() && s.getY() >= z.getY() && s.getY() <= z.getY() + z.getImageHeight())
			return true;
		if(s.getY() + s.getImageHeight() >= z.getY() && s.getY() + s.getImageHeight() <= z.getY() + z.getImageHeight() && s.getX() >= z.getX() && s.getX() <= z.getX() + z.getImageWidth())
			return true;
		if(s.getY() + s.getImageHeight() >= z.getY() && s.getY() + s.getImageHeight() <= z.getY() + z.getImageHeight() && s.getX() + s.getImageWidth() >= z.getX() && s.getX() + s.getImageWidth() <= z.getX() + z.getImageWidth())
			return true;
		return false;
	}


	@Override
	protected void setBoardColor(Graphics g) {
		g.setColor(new Color(176,196,222));
		g.fillRect(0, 0, d.width, d.height);
	}

	@Override
	protected XYPlayer player() {
		// TODO Auto-generated method stub
		return new Cowboy();
	}


	public void verfiyGameWon() {
		if (deaths == Commons.NUMBER_OF_ALIENS_TO_DESTROY) {

			inGame = false;
			timer.stop();
			message = "Cowboy wins!";
		}
	}
	
	public void shotUpdate() {
		if (shot.isVisible()) {

			// matar o monstro com o tiro
			for (BadSprite monster : badSprites) { //checar colisao do tiro com os etes

				if (!monster.isFreezing() && shot.isVisible()) {
				
					if(checkCollision(shot,monster)) {

						freezeMonster(monster);
					}
				}
			}
			shotMovement();
		}
	}

	private void freezeMonster(BadSprite monster) {
		ImageIcon ii = new ImageIcon(explImg.replace('@', Integer.toString(monster.Id - 9).charAt(0)));
		Image scaledImage = ii.getImage().getScaledInstance(30, 50, Image.SCALE_SMOOTH);
		monster.setImage(scaledImage);
		monster.setFreezing(true);
		monster.setVisible(true);
		deaths++;
		shot.die();
	}

	private void shotMovement() {
		int y = shot.getY();
		int x = shot.getX();
		if (shot.lastDirection == 1) {
			x -= 4;
		} else if (shot.lastDirection == 2) {
			y -= 4;
		} else if (shot.lastDirection == 3) {
			x += 4;
		} else {
			y += 4;
		}
		if (y < (0 - shot.getImageHeight()) || y > spriteframework.Commons.BOARD_HEIGHT
				|| x < (0 - shot.getImageWidth()) || x > spriteframework.Commons.BOARD_WIDTH) {
			shot.die();
		} else {
			shot.setY(y);
			shot.setX(x);
		}
	}
	
	public void updateMonster() {
		Random random = new Random(); 
		for (BadSprite monster : badSprites) {
			if (!monster.isFreezing()) {
				monsterMovement(random, monster);
				if(checkCollision(monster, players.get(0))) {
					players.get(0).setDying(true);
				}
			}
		}
	}

	private void monsterMovement(Random random, BadSprite monster) {
		if (1 == random.nextInt(100)) {
			int Dx = 0;
			int Dy = 0;
			while (Dx + Dy == 0) {
				Dx = (random.nextInt(5) - 2);
				Dy = (random.nextInt(5) - 2);
			}

			monster.setDx(Dx);
			monster.setDy(Dy);
		}

		if (monster.getY() + monster.getDy() + monster.getImageHeight() >= spriteframework.Commons.BOARD_HEIGHT || monster.getY() + monster.getDy() <= 0) {
				monster.setDy(monster.getDy() * -1);
		}

		if (monster.getX() + monster.getDx() + monster.getImageWidth()   >= spriteframework.Commons.BOARD_WIDTH || monster.getX() + monster.getDx() <= 0) {
				monster.setDx(monster.getDx() * -1);
		}

		monster.setX(monster.getX() + monster.getDx());
		monster.setY(monster.getY() + monster.getDy());
	}
}