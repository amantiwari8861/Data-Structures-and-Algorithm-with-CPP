/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package linearsearch;
import java.util.*;
public class LinearSearch
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
			if ((n > 0) && (n <= 20))
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
		System.out.println("-----------------------");
		System.out.println(" Enter array elements  ");
		System.out.println("-----------------------");

		for (i = 0; i < n; i++)
		{
			System.out.print("<" + (i + 1) + "> ");
			String s1 = new Scanner(System.in).nextLine();
			arr[i] = Integer.parseInt(s1);
		}

		char ch; //  Variable to store the choice(y/n) for continuing search
		int ctr; // Variable to count the number of comparisons

		do
		{
			// Accept the number to be searched
			System.out.print("\nEnter the element you want to search: ");
			int item = Integer.parseInt(new Scanner(System.in).nextLine());

			// Apply linear search
			ctr = 0;
			for (i = 0; i < n; i++)
			{
				ctr++;
				if (arr[i] == item)
				{
					System.out.println("\n" + (new Integer(item)).toString() + " found at position " + (new Integer(i + 1)).toString());
					break;
				}
			}
			if (i == n)
			{
				System.out.println("\n" + (new Integer(item)).toString() + " not found in the array");
			}

				System.out.println("\nNumber of comparisons: " + ctr);
				   System.out.print("\nContinue search (y/n):");
				   ch = new Scanner(System.in).nextLine().charAt(0);
		} while ((ch == 'y') || (ch == 'Y'));
	}

}
