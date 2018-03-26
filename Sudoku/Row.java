/**
 * The row type of sequence
 *
 */
public class Row extends Sequence 
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = 8046294874695168279L;
	private int rowNumber;//The number of the row in the board
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * The ID of the row
	 * @param i
	 */
	public Row(int i) 
	{
		rowNumber = i;
	}

	/*---------------METHODS---------------*/
	/*
	 * (non-Javadoc)
	 */
	@Override
	public void associate(Element element) 
	{
		setElement(element.getY(), element);
	}
	
	/**
	 * Get the ID of the row
	 * @return the ID of the row
	 */
	public int getRowId() 
	{
		return rowNumber;
	}

	@Override
	public String toString() 
	{
		String output = "Row: " + rowNumber + "\n";
		for(int i = 0; i < ((Sequence)this).getEnteredVals().size(); i++)
		{
			if(i != ((Sequence)this).getEnteredVals().size()-1)
			{
				output += ((Sequence)this).getEnteredVals().get(i) + "-";
			}
			else
			{
				output += ((Sequence)this).getEnteredVals().get(i);
			}
		}
		output += "\n";
		return output;
	}
}