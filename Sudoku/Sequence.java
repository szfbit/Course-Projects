import java.io.Serializable;
import java.util.ArrayList;
/**
 * Represents a group of elements whose number cannot be the same
 *
 */
public abstract class Sequence implements Serializable 
{
	/*---------------FIELDS---------------*/
	/**
	 * for serialization
	 */
	private static final long serialVersionUID = 4911806490982002779L;
	protected Element [] element;//The elements owned by the sequence
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * Creates an empty array of elements with the size Board.DIMENSION*Board.DIMENSION
	 */
	public Sequence()
	{
		element = new Element[Board.DIMENSION*Board.DIMENSION];
	}
	
	/*---------------METHODS---------------*/
	/**
	 * Add an element to the sequence (for initialization only)
	 * @param element the element to be added
	 */
	public abstract void associate(Element element);
	
	/**
	 * Retrieve a list of all entered numbers in the sequence
	 * @return a list of all entered numbers in the sequence
	 */
	public ArrayList<Character> getEnteredVals()
	{
		ArrayList<Character> temp = new ArrayList<Character>();
		for(int i = 0; i < element.length; i++)
		{
			if(element[i].getVal() != null)
			{
				temp.add(element[i].getVal());
			}
		}
		return temp;
	}
	
	/**
	 * Get an element with value = val
	 * @param val the value to be searched
	 * @return The element with value = val. Null if no such element exists
	 */
	public Element findElement(Character val) 
	{
		for(int i = 0; i < element.length; i++)
		{
			if(val == element[i].getVal())
			{
				return element[i];
			}
		}
		return null;
	}
	
	/**
	 * Set an element to the sequence
	 * @param pos the position of the element (0 ~ DIMENSION^2-1)
	 * @param element the element to be set
	 */
	protected void setElement(int pos, Element element)
	{
		this.element[pos] = element;
	}
}
	