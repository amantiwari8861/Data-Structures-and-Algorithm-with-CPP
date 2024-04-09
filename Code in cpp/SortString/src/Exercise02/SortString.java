package Exercise02;
import java.util.*;
public class SortString {
   	private String[] words = new String[20];
	// Number of elements in array
	private int n;
	// Function to accept array elements
	public final void read()
	{
		// Get the number of elements to store in the array
		while (true)
		{
			System.out.print("Enter the number of strings: ");
			String s = new Scanner(System.in).nextLine();
			n = Integer.parseInt(s);

			if (n > 0 && n <= 20)
			{
				break;
			}
			else if (n > 20)
			{
				System.out.println("\nYou can enter maximum 20 strings.\n");
			}


		}

		System.out.println("");
		System.out.println("-----------------------------------------------");
		System.out.println(" Enter the strings to be sorted:");
		System.out.println("-----------------------------------------------");
		// User inputs for the array 
		for (int i = 0; i < n; i++)
		{
			System.out.print("Enter the string " + (i + 1) + ":");

			words[i] = new Scanner(System.in).nextLine();
		}
	}

	public final void display()
	{
		// Display the sorted array
		System.out.println("");
		System.out.println("-----------------------");
		System.out.println(" Sorted strings ");
		System.out.println("-----------------------");

		for (int j = 0; j < n; j++)
		{
			System.out.println(words[j]);
		}
	}

	// Function to sort using Bubble sort
	public final void BubbleSort()
	{
		for (int i = 1; i < n; i++) // For n – 1 passes
		{
			// In pass i, compare the first n – i elements
			// with their next elements
			for (int j = 0; j < n - i; j++)
			{
                            	if (words[j].compareTo(words[j + 1]) > 0)
				// If the elements are not in 
				// the correct order
				{
					// Swap the elements
					String temp;

					temp = words[j];
					words[j] = words[j + 1];
					words[j + 1] = temp;

				}
			}

		}
	}

	public static void main(String [] args)
	{
		// Creating the object of the BubbleSort class
		SortString obj = new SortString();

		// Function call to accept array elements
		obj.read();

		// Function call to sort array
		obj.BubbleSort();

		// Function call to display the sorted array
		obj.display();

		// To exit from the console
		System.exit(0);
	}
    
}
