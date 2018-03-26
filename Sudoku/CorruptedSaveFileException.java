/**
 * The format of the save file of Board is incorrect.
 *
 */
public class CorruptedSaveFileException extends Exception 
{
	public CorruptedSaveFileException() 
	{
		super();	
		System.out.println("The format of the file is not correct!");
	}

	public CorruptedSaveFileException(String message, Throwable cause) 
	{
		super(message, cause);
		System.out.println("The format of the file is not correct! Reason: " + cause.getMessage());
	}

	public CorruptedSaveFileException(String message) 
	{
		super(message);
		// 
	}

	public CorruptedSaveFileException(Throwable cause) 
	{
		super(cause);
		// 
	}

	/**
	 * 
	 */
	private static final long serialVersionUID = 5345986390239853518L;
}