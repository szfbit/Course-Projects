import java.util.ArrayList;
import java.util.List;
/**
 * Represents a grid in the board that can be modified
 *
 */
public class ModifiableElement extends Element 
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = 8025282256821727988L;
	
	/*---------------CONSTRUCTORS---------------*/
	/**
	 * Constructs a new element
	 * @param i x coordinate (row number) of the element
	 * @param j y coordinate (column number) of the element
	 * @param seqs the sequences that the element relates to
	 */
	public ModifiableElement(int i, int j, Box box, Row row, Column col, Alphabet alphabet) 
	{
		super(i, j, null, box, row, col, alphabet);
	}
	
	/*---------------METHODS---------------*/
	/**
	 * Set value to the element. The value will not be set if any of the
	 * following exceptions happen
	 * @param val the value to be set. Null if you want to empty the 
	 * element.
	 * @throws OutOfBoundaryException The entered value is out-of-boundary
	 * @throws DuplicateException The entered value conflicts with some of
	 * the related sequences. The information of the conflicts is included
	 * in the DuplicateException object.
	 */
	public void setVal(Character val) throws OutOfBoundaryException, DuplicateException
	{
		if(val != null && !this.alphabet.isValidChar(val.charValue()))
		{
			throw new OutOfBoundaryException("Out-Of-Boundary");
		}
		
		ArrayList<Sequence> seq = new ArrayList<Sequence>();
		ArrayList<Element> conflictEleList = new ArrayList<Element>();
		
		if(row.findElement(val) != null)
		{
			seq.add(row);
			conflictEleList.add(row.findElement(val));
		}
		
		if(column.findElement(val) != null)
		{
			seq.add(column);
			conflictEleList.add(column.findElement(val));
		}	
		
		if(box.findElement(val) != null)
		{
			seq.add(box);
			conflictEleList.add(box.findElement(val));
		}
		
		if(seq.size() != 0)
		{
			throw new DuplicateException(seq, conflictEleList);
		}
		
		this.value = val;
	}
	
	/**
	 * Gets a list of candidate values for the element
	 * @return
	 */
	public ArrayList<Character> getCandidates()
	{
		ArrayList<Character> temp1 = row.getEnteredVals();
		ArrayList<Character> temp2 = column.getEnteredVals();
		ArrayList<Character> temp3 = box.getEnteredVals();
		ArrayList<Character> candidate = new ArrayList<Character>();
		
		for(int i = 0; i < Board.DIMENSION*Board.DIMENSION;i++)
		{
			if(!temp1.contains(alphabet.get(i)) && !temp2.contains(alphabet.get(i)) &&!temp3.contains(alphabet.get(i)))
			{
				candidate.add(alphabet.get(i));
			}
		}
		
		return candidate;
	}
	
	/**
	 * Gets the value of the element
	 */
	public Character getVal() 
	{
		return value;
	}
	
}