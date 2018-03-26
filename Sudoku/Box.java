/**
 * The box type of sequence
 *
 */
public class Box extends Sequence 
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = 3381374557853843834L;
	private int rowNumber; //Row number of box
	private int colNumber;//Column number of box
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * The position of the box
	 * @param i
	 * @param j
	 */
	public Box(int i, int j) 
	{
		rowNumber = i;
		colNumber = j;
	}
	
	/*---------------METHODS---------------*/
	/*
	 * (non-Javadoc)
	 */
	@Override
	public void associate(Element element) 
	{
		setElement(element.getX()%Board.DIMENSION*Board.DIMENSION + element.getY()%Board.DIMENSION, element);
	}
	
	/**
	 * Get the row number of the box
	 * @return the row number of the box
	 */
	public int getX() 
	{
	   return rowNumber;
    }
	
	/**
	 * Get the column number of the box
	 * @return the column number of the box
	 */
	public int getY()
	{
        return colNumber;
	}
	
	@Override
	public String toString() 
	{
		String output = "Box: " + (rowNumber/Board.DIMENSION*Board.DIMENSION + colNumber/Board.DIMENSION) + "\n";
		for(int i = 0; i < ((Sequence)this).getEnteredVals().size(); i++)
		{
			if((i+1)%Board.DIMENSION == 0)
			{
				output += ((Sequence)this).getEnteredVals().get(i) +"\n";
			}
			else
			{
				output += ((Sequence)this).getEnteredVals().get(i) + "-";
			}
		}
		output += "\n";
		return output;
	}
}