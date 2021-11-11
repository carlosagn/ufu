package freezemonster;

import spriteframework.AbstractBoard;
import spriteframework.MainFrame;

public class FreezeMonsterGame extends MainFrame{

	public FreezeMonsterGame(String t) {
		super(t);
		// TODO Auto-generated constructor stub
	}

	@Override
	protected AbstractBoard createBoard() {
		// TODO Auto-generated method stub
		return new FreezeMonsterBoard();
	}

}
