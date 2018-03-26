import java.io.Serializable;

public class Element implements Serializable
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = 5575699296262255060L;
	protected int rowNumber;//The number of row the element in the board
	protected int colNumber;//The number of column the element in the board
	protected Box box;//The box the element associated to
	protected Row row;//The row the element associated to
	protected Column column;//The column the element associated to
	protected Character value;//The given value of the element
	protected Alphabet alphabet;//The alphabet the element use
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * Coordinate of the point
	 * @param x
	 * @param y
	 * @param val
	 * @param box
	 * @param row
	 * @param col
	 * @param alphabet
	 */
	public Element(int x, int y, Character val, Box box, Row row, Column col, Alphabet alphabet) 
	{
		this.rowNumber = x;
		this.colNumber = y;
		this.value = val;
		this.box = box;
		this.row = row;
		this.column = col;
		this.alphabet = alphabet;
		
		this.box.associate(this);
		this.row.associate(this);
		this.column.associate(this);
	}
	
	/*---------------METHODS---------------*/
	/**
	 * Get the row number of the element. (0-based)
	 * @return the row number of the element. (0-based)
	 */
	public int getX() 
	{
		return this.rowNumber;
	}

	/**
	 * Get the column number of the element. (0-based)
	 * @return the column number of the element. (0-based)
	 */
	public int getY() 
	{
		return this.colNumber;
	}

	/**
	 * Get the value entered in the element. Null if the element is empty.
	 * @return the value entered in the element
	 */
	public Character getVal() 
	{
		if(this.value == null)
		{
			return null; //
		}
		else
		{
			return this.value;
		}
	}

	/**
	 * Get the alphabet of the element
	 */
	protected Alphabet getAlphabet() 
	{
		return this.alphabet;
	}
}
	