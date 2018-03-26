import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.NoSuchElementException;
import java.util.Scanner;

/**
 * The controller of the sudoku board.
 *
 */
public class Board implements Serializable
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = 6136897931786320404L;
	public static final int DIMENSION = 3;//DIMENSION used for the whole package
    protected Row [] row;//Sequence-row
    protected Column [] col;//Sequence-column
    protected Box [] box;//Sequence-box
    protected Alphabet alphabet;//Alphabet
    protected Character [][] grid = new Character[DIMENSION*DIMENSION][DIMENSION*DIMENSION];//For checking whether the element is modifiable and used for reseting
    
    /*---------------CONSTRUCTORS---------------*/
	/**
	 * Creates a new game
	 */
	public Board()
	{	
		grid = new Character[DIMENSION*DIMENSION][DIMENSION*DIMENSION];	
		this.alphabet =  new Alphabet();
		initSequences();
	}
	
	/**
	 * Constructs a game with given characters specified in the ¡®initBoard¡¯ parameter together with an initial alphabet
	 * @param initBoard
	 * @param alphabet
	 */
	public Board(Character [][] initBoard, Alphabet alphabet)
	{
		this.alphabet = alphabet;
		grid = initBoard;	
		initSequences();
	}
	
	/**
	 * Read a game from a saved file
	 * @param path the path of the game
	 * @throws FileNotFoundException the file cannot be found
	 * @throws CorruptedSaveFileException the format of the file is invalid
	 */
	public Board(String path) throws FileNotFoundException, CorruptedSaveFileException//throws FileNotFoundException, CorruptedSaveFileException
	{
		initSequences();
		open(path);
	}
	
	/*---------------METHODS---------------*/
	/**
	 * Initialize all sequences
	 */
	private void initSequences() 
	{	
		this.row = new Row[DIMENSION*DIMENSION];
		this.col = new Column[DIMENSION*DIMENSION];
		this.box = new Box[DIMENSION*DIMENSION];
		
		
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			row[i] = new Row(i);
			col[i] = new Column(i);
			box[i] = new Box(i/DIMENSION*DIMENSION, i%DIMENSION*DIMENSION);
		}
		
		for(int i= 0; i< DIMENSION*DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION*DIMENSION; j++)
			{
				if(grid[i][j] == null)
				{
					ModifiableElement newMem = new ModifiableElement(i, j, box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], this.alphabet);
				}
				else
				{
					Element newMem = new Element(i, j, grid[i][j], box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], this.alphabet);
				}
			}
		}
	}
	
    /**
     * Sets a value on one grid of the board
     * @param x
     * @param y
     * @param val
     * @throws OutOfBoundaryException
     * @throws DuplicateException
     * @throws ReadOnlyException
     */
	public void setVal(int x, int y, Character val) throws OutOfBoundaryException, DuplicateException, ReadOnlyException
	{			
		if(grid[x][y] == null)
		{
			((ModifiableElement)row[x].element[y]).alphabet = this.alphabet;
			((ModifiableElement)row[x].element[y]).setVal(val);
		}
		else
		{
			throw new ReadOnlyException();
		}
	}	
	
	/**
	 * Get the element at position (i, j)
	 * @param i the row number of the element
	 * @param j the column number of the element
	 * @return the element at position (i, j)
	 */
	public Character getVal(int i, int j) 
	{
		if(row[i].element[j] != null)
		{
			return row[i].element[j].getVal();
		}
		return  null; 
	}
	
	/**
	 * Get a list of candidate input at a certain position
	 * @param x the row number
	 * @param y the column number
	 * @return the list of all candidates for the position
	 */
	public ArrayList<Character> getCandidates(int x, int y)
	{
		if(row[x].element[y] instanceof ModifiableElement)
		{
			return ((ModifiableElement)row[x].element[y]).getCandidates();
		}	
		return null;
	}
	
	/**
	 * Get the character set for the game
	 * @return the character set for the game
	 */
	public Alphabet getAlphabet() 
	{
		return this.alphabet;
	}
	
	/**
	 * Set the character set for the game
	 * @param alphabet2 the character set for the game
	 */
	public void setAlphabet(Alphabet alphabet2) 
	{
		this.alphabet = alphabet2;
		
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION*DIMENSION; j++)
			{
				if(grid[i][j] != null)
				{
					int pos = row[i].element[j].alphabet.getPosition(row[i].element[j].getVal().charValue());
					grid[i][j] = alphabet2.get(pos);
					row[i].element[j] = new Element(i, j, alphabet2.get(pos), box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], alphabet2);
				}
				
				if(row[i].element[j].getVal() != null && grid[i][j] == null)
				{
					int pos = row[i].element[j].alphabet.getPosition(row[i].element[j].getVal().charValue());
					
					row[i].element[j] = new ModifiableElement(i, j, box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], alphabet2);
					try {
						((ModifiableElement)row[i].element[j]).setVal(alphabet2.get(pos));
					} catch (OutOfBoundaryException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					} catch (DuplicateException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
				}
			}
		}
	}
	
	/**
	 * Save the game in text format
	 * @param path the path in dist
	 * @throws IOException if the path is invalid
	 */
	public void save(String path) throws IOException
	{
		File fstream = new File(path);
		FileWriter out = new FileWriter(fstream.getAbsoluteFile());
		
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION*DIMENSION; j++)
			{
				if(grid[i][j] != null)
				{
					out.write(new String("U-" + grid[i][j].charValue() + " "));
				}
				else if(grid[i][j] == null && row[i].element[j].getVal() != null)
				{
					out.write(new String("M-" + row[i].element[j].getVal().charValue() + " "));
				}
				else if(grid[i][j] == null && row[i].element[j].getVal() == null)
				{
					out.write(new String("M-?" + " "));
				}
			}
			out.write(new String("\n"));
		}

		out.write(new String(this.alphabet.alphabet));	
		out.close();
	}
	
	/**
	 * Constructs a game from a previously saved game
	 */
	private void open(String path) throws FileNotFoundException,CorruptedSaveFileException 
	{
		Scanner in;
		
		try
		{
			File fstream = new File(path);
			in = new Scanner(fstream);
		}
		catch(FileNotFoundException e)
		{
			throw new FileNotFoundException();
		}

		ArrayList<String> tempA = new ArrayList<String>();

		while(in.hasNextLine())
		{	
			String tempS =  in.nextLine();
			tempA.add(tempS);
		}
		in.close();
		
		if((tempA.size()-1) != DIMENSION*DIMENSION)
		{
			in.close();
			throw new CorruptedSaveFileException();
		}

		String tempAlph = tempA.get(DIMENSION*DIMENSION);

		try {
			char [] newT = new char[DIMENSION*DIMENSION];
			for(int i = 0; i < DIMENSION*DIMENSION; i++)
			{
				newT[i] = tempAlph.charAt(i);
			}
			Alphabet newAlph = new Alphabet(newT);
			this.alphabet = newAlph;
		} catch (InvalidAlphabetException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		
		
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION*DIMENSION; j++)
			{
				String ele = tempA.get(i).split(" ")[j];
				if(ele.split("-")[0].charAt(0) != 'U' && ele.split("-")[0].charAt(0) != 'M')
				{
					throw new CorruptedSaveFileException();
				}
				
				if(ele.split("-")[1].charAt(0) != '?' && !alphabet.isValidChar(ele.split("-")[1].charAt(0)))
				{
					throw new CorruptedSaveFileException();
				}
				
				if(ele.split("-")[0].charAt(0)== 'U')
				{
					row[i].element[j] =  new Element(i, j, ele.split("-")[1].charAt(0),box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], alphabet);
				}
				else if(ele.split("-")[0].charAt(0)== 'M')
				{
					if(ele.split("-")[1].charAt(0) == '?')
					{
						row[i].element[j] = new ModifiableElement(i, j, box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], alphabet);
					}
					else
					{
						row[i].element[j] = new ModifiableElement(i, j, box[i/DIMENSION*DIMENSION + j/DIMENSION], row[i], col[j], alphabet);
						try {
							((ModifiableElement)row[i].element[j]).setVal(ele.split("-")[1].charAt(0));
						} catch (OutOfBoundaryException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						} catch (DuplicateException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					}
				}
			}
		}
	}
	
	
	/*
	 * (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() 
	{	
		String output = "\n\nRows\n\n";
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			output += row[i].toString();
		}
		output += "\n\n";
		output += "Columns\n\n";
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			output += col[i].toString();
		}
		
		output += "\n\n";
		output += "Boxes\n\n";
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			output += box[i].toString();
		}
		
		output += "\n\n";
		output += "Alphabet\n\n";
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			output += this.alphabet.alphabet[i];
		}
		
		output += "\n\n";
		output += "Overview: ";
		output += "\n\n";
		for(int i = 0 ; i < DIMENSION*DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION*DIMENSION; j++)
			{
				output += row[i].element[j].getVal() + " ";
			}
			output += "\n";
		}
		output += "\n";
		
		return output;
	}
	
	/**
	 * Checks if the game has finished
	 * @return true if the game has finished
	 */
	public boolean isSolved()
	{
		for(int i = 0; i < DIMENSION*DIMENSION; i++)
		{
			for(int j = 0; j < DIMENSION*DIMENSION; j++)
			{
				if(row[i].element[j].getVal() == null)
				{
					return false;
				}
			}
		}
		return true;
	}
	
	/**
	 * Checks if a grid can be modified
	 * @param r the row number
	 * @param c the column number
	 * @return true if it can be modified
	 */
	public boolean canModify(int r, int c) 
	{
		if(grid[r][c] != null)
		{
			return false;
		}
		return true;
	}
	
	/**
	 * Reset the game to its original state
	 */
	public void reset()
	{
		initSequences();
	}
}
	