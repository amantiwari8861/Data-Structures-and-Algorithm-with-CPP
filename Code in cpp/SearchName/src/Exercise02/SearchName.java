/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Exercise02;
import java.util.*;
/**
 *
 * @author Ashish.Srivastav
 */
public class SearchName {

   		private String[] arr = new String[20]; //Array to be searched
		private int n; //Number of elements in the array
		public final void read_elements()
		{
			int i;
			// Get the number of elements to store in the array
			while (true)
			{
				System.out.print("Enter the total number of names in the array: ");
				String s = new Scanner(System.in).nextLine();
				n = Integer.parseInt(s);
				if ((n > 0) && (n <= 20))
				{
					break;
				}
				else
				{
					System.out.println("\nArray should have minimum 1 and maximum 20 elements.\n");
				}
			}
			//Accept array elements
			System.out.println("");
			System.out.println("-----------------");
			System.out.println(" Enter the names ");
			System.out.println("-----------------");
			for (i = 0; i < n; i++)
			{
				System.out.print("<" + (i + 1) + "> ");
				arr[i] = new Scanner(System.in).nextLine();
			}
		}
		public final void bubble_sort()
		{
			for (int i = 1; i < n; i++) // For n - 1 passes
			{
				// In Pass i, compare the first n - i elements
				// with their next elements
				for (int j = 0; j < n - i; j++)
				{
					if (arr[j].compareTo(arr[j + 1]) > 0) // If the elements
					{
					// are not in the correct order
						// Swap the elements
						String temp;
						temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
					}
				}

			}
		}
		public final void binary_search(String item)
		{
			//Apply binary search
			int lowerbound = 0;
			int upperbound = n - 1;
			int count = 1;
			//Obtain the index of the middlemost element
			int mid = (lowerbound + upperbound) / 2;
			while ((item.compareTo(arr[mid]) != 0) && (lowerbound <= upperbound))
			{
				if (item.compareTo(arr[mid]) > 0)
				{
					lowerbound = mid + 1;
				}
				else
				{
					upperbound = mid - 1;
				}

				mid = (lowerbound + upperbound) / 2;
				count++;
			}
			System.out.println();
			if (item.compareTo(arr[mid]) == 0)
			{
				System.out.println(item.toString() + " found at position " + (new Integer(mid + 1)).toString() + " in the sorted array.");
			}
			else
			{
				System.out.println(item.toString() + " not found in the array");
			}
			System.out.println("\nNumber of comparisons: " + count);
		}
		public final void display()
		{
			for (int i = 0; i < n; i++)
			{
				System.out.println(arr[i]);
			}
		}
	 public static void main(String[] args)
	 {
			SearchName obj = new SearchName();
			obj.read_elements();
			obj.bubble_sort();
			System.out.println("\nThe sorted list is:");
			obj.display();
			System.out.println();
			char ch;
			do
			{
				//Accept the name to be searched
				System.out.print("\nEnter the name to be searched: ");
				String item = new Scanner(System.in).nextLine();
				obj.binary_search(item);
				System.out.print("\nContinue search (y/n):");
				ch = new Scanner(System.in).nextLine().charAt(0);
			} while ((ch == 'y') || (ch == 'Y'));
	 }
    
}
