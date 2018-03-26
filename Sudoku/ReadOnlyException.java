/**
 * The element is read only and cannot be modified
 *
 */
public class ReadOnlyException extends Exception 
{
	public ReadOnlyException() 
	{
		super();
		System.out.println("Read-Only");
	}

	public ReadOnlyException(String message) 
	{
		super(message);
		System.out.println("Read-Only Reason: " + message);
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = 7436642474756656778L;
}