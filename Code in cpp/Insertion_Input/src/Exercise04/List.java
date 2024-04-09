package Exercise04;

import java.util.*;
public class List
{
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
		System.out.println(" Enter the strings to be sorted (each one word)");
		System.out.println("-----------------------------------------------");


		// User inputs for the array 
		for (int i = 0; i < n; i++)
		{
			System.out.print("Enter the strings " + (i + 1) + ":");

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



	// Function to sort using Insertion sort
	public final void InsertionSort()
	{
		for (int i = 1; i <= n - 1; i++)
		{
			String temp = words[i];
			int j = i - 1;


			while ((j >= 0) && (words[j].compareTo(temp) > 0))
			{
				words[j + 1] = words[j];
				j = j - 1;
			}
			words[j + 1] = temp;
		}


	}

	public static void main( String [] args)
	{
		// Creating the object of the InsertionSort class
		List myList = new List();
		// Function call to accept array elements
		myList.read();
		// Function call to sort array
		myList.InsertionSort();
		// Function call to display the sorted array
		myList.display();
		// To exit from the console
		System.exit(0);
	}
}