/**
 * The column type of sequence
 *
 */
public class Column extends Sequence 
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = -9172599321818777827L;
	private int colNumber;
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * @param i The column ID
	 */
	public Column(int i) 
	{
		colNumber = i;
	}
	
	/*---------------METHODS---------------*/
	/*
	 * (non-Javadoc)
	 * @see edu.cityu.zhilinyin2.Sequence#offer(edu.cityu.zhilinyin2.Element)
	 */
	@Override
	public void associate(Element readOnlyElement) 
	{
		setElement(readOnlyElement.getX(), readOnlyElement);
	}

	/**
	 * Get the column ID
	 * @return the column ID
	 */
	public int getColId() 
	{
		return colNumber; //
	}
	
	@Override
	public String toString() 
	{
		String output = "Column: " + colNumber + "\n";
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