
package binarysearch;
import java.util.*;
public class BinarySearch
{
	public static void main(String[] args)
	{
		int[] arr = new int[20]; // Array to be searched
		int n; // Number of elements in the array
		int i;

		// Get the number of elements to store in the array
		while (true)
		{
			System.out.print("Enter the number of elements in the array: ");
			String s = new Scanner(System.in).nextLine();
			n = Integer.parseInt(s);
			if ((n > 1) && (n <= 20))
			{
				break;
			}
			else
			{
				System.out.println("\nArray should have minimum 1 and maximum 20 elements.\n");
			}
		}

		// Accept array elements
		System.out.println("");
		System.out.println("--------------------------------");
		System.out.println(" Enter array elements in ascending order ");
		System.out.println("--------------------------------");
		for (i = 0; i < n; i++)
		{
			System.out.print("<" + (i + 1) + "> ");
			String s1 = new Scanner(System.in).nextLine();
			arr[i] = Integer.parseInt(s1);
		}

		char ch; //  Variable to store the choice(y/n) for continuing search



		do
		{
			// Accept the number to be searched
			System.out.print("\nEnter the element you want to search: ");
			int item = Integer.parseInt(new Scanner(System.in).nextLine());

			// Apply binary search
			int lowerbound = 0;
			int upperbound = n - 1;

			// Obtain the index of the middlemost element
			int mid = (lowerbound + upperbound) / 2;
			int ctr = 1; // Variable to count the number of comparisons


			while ((item != arr[mid]) && (lowerbound <= upperbound)) // Loop to search for the element in the array
			{
				if (item > arr[mid])
				{
					lowerbound = mid + 1;
				}
				else
				{
					upperbound = mid - 1;
				}
				mid = (lowerbound + upperbound) / 2;
				ctr++;
			}

			if (item == arr[mid])
			{
				System.out.println("\n" + (new Integer(item)).toString() + " found at position " + (new Integer(mid + 1)).toString());
			}
			else
			{
				System.out.println("\n" + (new Integer(item)).toString() + " not found in the array\n");
			}
				System.out.println("\nNumber of comparisons: " + ctr);
				System.out.print("\nContinue search (y/n):");
				ch = new Scanner(System.in).nextLine().charAt(0);
		} while ((ch == 'y') || (ch == 'Y'));
	}
}