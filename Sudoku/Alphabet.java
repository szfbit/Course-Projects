import java.io.Serializable;

public class Alphabet implements Serializable
{
	/*---------------FIELDS---------------*/
	private static final long serialVersionUID = -6906385698060963797L;
	
	/**
	 * Array of alphabet stored in the class
	 */
	protected char [] alphabet = new char[Board.DIMENSION*Board.DIMENSION]; 
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * Initialize the alphabet with the default values
	 */
	public Alphabet()
	{
		for(int i = 1; i <= Board.DIMENSION*Board.DIMENSION; i++)
		{
			alphabet[i-1] = (char)('0' + i);
		}
	}
	
	/**
	 * Constructs an alphabet with a user input of values as an array
	 * @param input
	 * @throws InvalidAlphabetException
	 */
	public Alphabet(char [] input) throws InvalidAlphabetException
	{
		if(input.length < Board.DIMENSION*Board.DIMENSION)
		{
			throw new InvalidAlphabetException();
		}
		
		if(isDuplic(input))
		{
			throw new InvalidAlphabetException();
		}
		
		this.alphabet = input;
	}
	
	/*---------------METHODS---------------*/
	/**
	 * Check whether the a character in the alphabet array is duplicate
	 * @param input
	 * @return
	 */
	public boolean isDuplic(char [] input)
	{
		for(int i = 0; i < Board.DIMENSION*Board.DIMENSION; i++)
		{
			for(int j = 0; j < Board.DIMENSION*Board.DIMENSION; j++)
			{
				if(input[j] == input[i] && i!= j)
				{
					return true;
				}
			}
		}
		return false;
	}
	
	/**
	 * Converts a character into integer for processing in Element
	 * @param c
	 * @return
	 */
	public int getPosition(char c)
	{
		for(int i = 0; i < alphabet.length; i++)
		{
			if(c == alphabet[i])
			{
				return i;
			}
		}
		return -1;
	}
	
	/**
	 * Checks if a character is contained in the alphabet
	 * @param c
	 * @return
	 */
	public boolean isValidChar(char c)
	{
		for(int i = 0; i < alphabet.length; i++)
		{
			if(c == alphabet[i])
			{
				return true;
			}
		}
		return false; 
	}
	
	/**
	 * Converts an integer into a character for displaying for the Board class
	 * @param pos
	 * @return
	 */
	public Character get(int pos) 
	{
		return alphabet[pos];
	}
	
	/**
	 * Copy the content from another alphabet
	 * @param alphabet2
	 */
	public void copy(Alphabet alphabet2) 
	{
		this.alphabet = alphabet2.alphabet;
	}
}