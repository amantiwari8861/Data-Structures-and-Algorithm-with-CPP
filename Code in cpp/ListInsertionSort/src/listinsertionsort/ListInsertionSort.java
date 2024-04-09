package listinsertionsort;
import java.util.*;
public class ListInsertionSort {
// Array of integers to hold values
	private int[] a = new int[20];
	// Number of elements in array
	private int n;

	// Function to accept array elements
	public final void read()
	{
		// Get the number of elements to store in the array
		while (true)
		{
			System.out.print("Enter the number of elements in the array: ");
			String s = new Scanner(System.in).nextLine();
			n = Integer.parseInt(s);
			if (n > 0 && n <= 20)
			{
				break;
			}
			else if (n > 20)
			{
				System.out.println("\nArray can have maximum 20 elements.\n");
			}
			else if (n < 0)
			{
				System.out.println("\nEnter positive number.\n");
			}
		}
		System.out.println("");
		System.out.println("-----------------------");
		System.out.println(" Enter array elements  ");
		System.out.println("-----------------------");


		// User inputs for the array 
		for (int i = 0; i < n; i++)
		{
			System.out.print("<" + (i + 1) + "> ");
			String s1 = new Scanner(System.in).nextLine();
			a[i] = Integer.parseInt(s1);
		}
	}

	public final void display()
	{
		// Display the sorted array
		System.out.println("");
		System.out.println("-----------------------");
		System.out.println(" Sorted array elements ");
		System.out.println("-----------------------");

		for (int j = 0; j < n; j++)
		{
			System.out.println(a[j]);
		}
	}

	// Function to sort using Insertion sort
	public final void InsertionSort()
	{
		for (int i = 1; i <= n - 1; i++)
		{
			int temp = a[i];
			int j = i - 1;

			while ((j >= 0) && (a[j] > temp))
			{
				a[j + 1] = a[j];
				j = j - 1;
			}
			a[j + 1] = temp;
		}


	}
    public static void main(String[] args) {
     // Creating the object of the InsertionSort class
		ListInsertionSort myList = new ListInsertionSort();
		// Function call to accept array elements
		myList.read();
		// Function call to sort array
		myList.InsertionSort();
		// Function call to display the sorted array
		myList.display();
        	// To exit from the console
		System.out.println("\n\nPress the Enter key to exit.");
		System.exit(0);

        
    }
    
}
