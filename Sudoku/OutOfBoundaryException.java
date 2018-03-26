/**
 * Represents a value that is out of the numeric bound of the dimension
 *
 */
public class OutOfBoundaryException extends Exception 
{
	/**
	 * For serialization
	 */
	private static final long serialVersionUID = -6623588475205485027L;
	/*
	 * (non-Javadoc)
	 * @see java.lang.Throwable#getMessage()
	 */
	public OutOfBoundaryException() 
	{
		System.out.println("Out-Of-Range");
	}
	
	public OutOfBoundaryException(String message) 
	{
		System.out.println("Out-Of-Range Reason: " + message);
	}
}