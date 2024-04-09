package Exercise05;
import java.util.*;
public class List
{
	private String[] words = new String[20];
	private int cmp_count; // Number of comparisons
	private int mov_count; // Number of data movements
	// Number of elements in array
	private int n;
	public List()
	{
		cmp_count = 0;
		mov_count = 0;
	}
	private void read()
	{
		while (true)
		{
			System.out.print("Enter the number of strings to be sorted: ");
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
		System.out.println("\n--------------------------");
		System.out.println(" Enter strings (1 word each)");
		System.out.println("----------------------------");
		for (int i = 0; i < n; i++)
		{

			System.out.print("Enter string " + (i + 1) + ": ");
			words[i] = new Scanner(System.in).nextLine();
		}
	}

private void swap(int x, int y) /* Swaps the element at index x with
 the element at index y */
	{
		String temp;
		temp = words[x];
		words[x] = words[y];
		words[y] = temp;
	}

	public final void q_sort(int low, int high)
	{
		String pivot;
		int i, j;

		if (low > high)
		{
			return;
		}
		/* Partition the list into two parts:
		 One containing elements less than or equal to pivot
		 Other containing elements greater than pivot */

		i = low + 1;
		j = high;

		pivot = words[low];

		while (i <= j)
		{
			// Search for an element greater than pivot
			while ((pivot.compareTo(words[i]) >= 0) && (i <= high))
			{
				i++;
				cmp_count++;
			}
			cmp_count++;

			// Search for an element less than or equal to pivot
			while ((words[j].compareTo(pivot) > 0) && (j >= low))
			{
				j--;
				cmp_count++;
			}
			cmp_count++;

			if (i < j) /* If the greater element is on the
                		      left of the smaller element */
			{
				/* Swap the element at index i with the element at index j */
				swap(i, j);
				mov_count++;
			}
		}

		/* j now contains the index of the last element in the sorted list. */

		if (low < j)
		{
			swap(low, j); // Move the pivot to its correct position in the list
			mov_count++;
		}

		//Sort the list on the left of pivot using quick sort
		q_sort(low, j - 1);

		//Sort the list on the right of pivot using quick sort
		q_sort(j + 1, high);
	}

	private void display()
	{
		System.out.println("\n-----------------------");
		System.out.println(" Sorted strings ");
		System.out.println("-----------------------");


		for (int j = 0; j < n; j++)
		{
			System.out.println(words[j]);
		}

		System.out.println("\nNumber of comparisons: " + cmp_count);
		System.out.println("\nNumber of data movements: " + mov_count);
	}

	private int getSize()
	{
		return (n);
	}

	public static void main(String[] args)
	{
		// Declaring the object of the class
		List myList = new List();

		// Accept array elements
		myList.read();

		// Calling the sorting function
		myList.q_sort(0, myList.getSize() - 1); // First call to Quick Sort Algorithm

		// Display sorted array
		myList.display();

		// To exit from the console
		System.exit(0);
	}
}
