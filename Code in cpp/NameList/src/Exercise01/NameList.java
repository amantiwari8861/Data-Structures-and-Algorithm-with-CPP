/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Exercise01;
import java.util.*;
public class NameList {

private String[] arr = new String[20]; //Array to be searched
		private int n; //Number of elements in the array

		// Function to obtain the value of n
		private void getTotalElements()
		{
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

		}

		//Function to read array elements
		private void read()
		{
			//Accept array elements
			System.out.println("");
			System.out.println("-----------------");
			System.out.println(" Enter the names ");
			System.out.println("-----------------");

			for (int i = 0; i < n; i++)
			{
				System.out.print("<" + (i + 1) + "> ");
				arr[i] = new Scanner(System.in).nextLine();
			}
		}

		//Function to apply linear search

		private void linear_search(String item)
		{
			int i;
			int cmp_count = 0;

			for (i = 0; i < n; i++)
			{
				cmp_count++;
				if (item.compareTo(arr[i]) == 0)
				{
					System.out.println(item + " found at position " + (i + 1));
					break;
				}

			}

			if (i == n)
			{
				System.out.println(item.toString() + " not found in the array\n");
			}

			System.out.println("Number of comparisons: " + cmp_count);

		}


	public static void main(String[] args)
		{
			NameList obj = new NameList();

			obj.getTotalElements();
			obj.read();
			char ch;
			do
			{
				//Accept the name to be searched
				System.out.print("\nEnter the name you want to search: ");
				String item = new Scanner(System.in).nextLine();

				System.out.println();
				obj.linear_search(item);
				System.out.print("\nContinue search (y/n):");
				ch = new Scanner(System.in).nextLine().charAt(0);

			} while ((ch == 'y') || (ch == 'Y'));
		}  
}
