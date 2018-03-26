import java.util.List;

/**
 * Represents a conflict of entering a new value to the grid
 *
 */
public class DuplicateException extends Exception 
{
	/*---------------FIELDS---------------*/
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = -2517791178834377773L;
	List<Sequence> seq;//Sequence List storing the sequences causing conflict
	List<Element> conflictEleList;//Element List storing the element causing conflict

	/*---------------CONSTRUCTORS---------------*/
	/**
	 * The list of sequences that the exception happen
	 * @param seq
	 * @param conflictEleList
	 */
	public DuplicateException(List<Sequence> seq, List<Element> conflictEleList)
	{
		this.seq = seq;
		this.conflictEleList = conflictEleList;
	}

	/*---------------METHODS---------------*/
	/**
	 * Get one sequence that has the exception
	 * @param pos the position of the exception (0-based)
	 * @return the sequence that has the exception in position pos.
	 */
	public Sequence getSequence(int pos) 
	{
		return seq.get(pos); 
	}
	
	/**
	 * Get one element that that the new value conflicts
	 * with in the sequence getSequence(pos) 
	 * @param pos the position of the element (0-based)
	 * @return the element that has the exception in position pos.
	 */
	public Element getConflictElement(int pos)
	{
		return conflictEleList.get(pos);
	}
	
	/**
	 * Get the total number of conflicts happen to the value
	 * @return the total number of conflicts happen to the value
	 */
	public int getNumConflicts()
	{
		return seq.size(); 
	}
}