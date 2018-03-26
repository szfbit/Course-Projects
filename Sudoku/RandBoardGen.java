import java.util.ArrayList;
import java.util.Random;



public class RandBoardGen {
	private static final int TRIALS = 20;
	public static Character [][] gen(Alphabet alp)
	{

		Board b = new Board();
		Random rand = new Random();
		for(int i=0; i<TRIALS; i++)
		{
			int x, y;
			//do{
				x = rand.nextInt(Board.DIMENSION*Board.DIMENSION);
				y = rand.nextInt(Board.DIMENSION*Board.DIMENSION);
			//}while(b.getVal(x, y) != null);
			if(b.getVal(x, y) == null )
			{
				ArrayList<Character> cands = b.getCandidates(x, y);
				if(cands.size() > 0)
					try {
						b.setVal(x, y, cands.get(rand.nextInt(cands.size())));
					} catch (OutOfBoundaryException e) {
						// should not happen
						e.printStackTrace();
					} catch (DuplicateException e) {
						// should not happen
						e.printStackTrace();
					} catch (ReadOnlyException e) {
						// should not happen
						e.printStackTrace();
					}
			}
		}
		Character [][] res = new Character[Board.DIMENSION*Board.DIMENSION][Board.DIMENSION*Board.DIMENSION];
		for(int i=0; i<Board.DIMENSION*Board.DIMENSION; i++)
			for(int j=0; j<Board.DIMENSION*Board.DIMENSION; j++)
			{
				Integer val = null;
				if(b.getVal(i,j) != null)
					val = b.getAlphabet().getPosition(b.getVal(i, j));
				res[i][j] = b.getVal(i, alp.get(val));
			}
		return res;
	}
	
}
