import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;


public class test {
	public static boolean testChangeAlphaManualIO() throws IOException
	{
		Board b = new Board();
		try {
			b.setVal(0, 1, '1');
			b.setVal(3, 2, '2');
			b.setVal(4, 3, '3');
			String newAlpha = "abcdefghi";
			
			b.setAlphabet(new Alphabet(newAlpha.toCharArray()));
			if(b.getVal(0, 1) != 'a')
				return false;
			if(b.getVal(3, 2) != 'b')
				return false;
			if(b.getVal(4, 3) != 'c')
				return false;
			b.setVal(0, 2, 'd');
				
			try
			{
				b.setVal(0, 3, '5');
				return false;
			}catch(OutOfBoundaryException e)
			{
				
			}
			
		} catch (OutOfBoundaryException e) {

			e.printStackTrace();
			return false;
		} catch (DuplicateException e) {

			e.printStackTrace();
			return false;
		}catch (InvalidAlphabetException e) {
			e.printStackTrace();
			return false;
		}catch (ReadOnlyException e) {
			e.printStackTrace();
			return false;
		}
		String path = "temp.o";
		b.save(path);
		try {
			Board newb = new Board(path);
			if(newb.getVal(0, 1) != 'a')
				return false;
			if(newb.getVal(3, 2) != 'b')
				return false;
			if(newb.getVal(4, 3) != 'c')
				return false;
			if(newb.getVal(0, 2) != 'd')
				return false;
			return true;
		} catch (CorruptedSaveFileException e) {
			e.printStackTrace();
			return false;
		}
		finally
		{
//			ois.close();
			new  File(path).delete();
		}
	}
	
	public static boolean testReadOnlyManualIO() throws IOException, ClassNotFoundException, CorruptedSaveFileException
	{
		int [][] grid = 
			 {
				 {5,3,4,6,7,8,9,1,2},
				 {6,7,2,1,9,5,3,4,8},
				 {1,9,8,3,4,2,5,6,7},
				 {8,5,9,7,6,1,4,2,3},
				 {4,2,6,8,5,3,7,9,1},
				 {7,1,3,9,2,4,8,5,6},
				 {9,6,1,5,3,7,2,8,4},
				 {2,8,7,4,1,9,6,3,5},
				 {3,4,5,2,8,6,1,7,9}
			 };
		Alphabet alp = new Alphabet();
		Character [][] table = new Character[Board.DIMENSION*Board.DIMENSION][Board.DIMENSION*Board.DIMENSION];
		for(int i=0; i<grid.length;i++)
			for(int j=0; j<grid[i].length; j++)
			{
				if(grid[i][j] == 1)
					table[i][j] = null;
				else 
					table[i][j] = alp.get(grid[i][j]-1);
			}
		Board b = new Board(table,alp);
		String path = "temp.o";
		b.save(path);
        
		b = new Board(path);
		for(int i=0; i<grid.length;i++)
			for(int j=0; j<grid[i].length; j++)
			{
				if(grid[i][j] == 1)
					try {
						b.setVal(i, j, b.getAlphabet().get(0));
						//return false;
					} catch (OutOfBoundaryException e) {
						e.printStackTrace();
						return false;
					} catch (DuplicateException e) {
						e.printStackTrace();
						return false;
					} catch (ReadOnlyException e) {
						//e.printStackTrace();
						return false;
					}
				
			}
		new File(path).delete();
		return true;
	}	
	
	public static boolean testManualIO() throws IOException
	{
		Board b = new Board();
		for(int i=0; i<Board.DIMENSION*Board.DIMENSION; i++)
			try {
				b.setVal(i, 0,(char) ('0'+i+1));
			} catch (OutOfBoundaryException e) {
				e.printStackTrace();
				return false;
			} catch (DuplicateException e) {
				e.printStackTrace();
				return false;
			}catch (ReadOnlyException e) {
				e.printStackTrace();
				return false;
			}
		String path = "temp.o";
		
        
        b.save(path);
		try {
			Board newb = new Board(path);
			for(int i=0; i<Board.DIMENSION*Board.DIMENSION; i++)
				if(newb.getVal(i, 0) != '0'+i+1)
					return false;
			
			return true;
		} catch (CorruptedSaveFileException e) {
			
			e.printStackTrace();
			return false;
		}finally
		{
			new File(path).delete();
		}
		
	}	
	
	public static void main(String[] args)
	{
		//testChangeAlphaManualIO()
		try {
			
			System.out.println("1:" + testChangeAlphaManualIO());
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
//		//testReadOnlyManualIO()
//		try {
//			System.out.println("2:" + testReadOnlyManualIO());
//		} catch (ClassNotFoundException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		} catch (CorruptedSaveFileException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//		
//		//testManualIO()
//		try {
//			System.out.println("3:" + testManualIO());
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
	}
}
