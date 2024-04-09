package Exercise01;
import java.util.*;
public class SortTechniques {

  	private int[] arr = new int[20]; //array declaration
		private int[] arr_copy = new int[20]; //Copy of the original array. This is required
		//because you need to sort the same array using
		//different sorting techniques. Once the array is 
		//sorted using one sorting technique, the array would
		//contain the elements in sorted order. Therefore, you 
		//need to maintain a copy of the original array. The sorting  
		//will be performed on the original array. Before sorting the 
		//array again using another technique, you need to restore
		//the contents of the original array from the contents of
		//the duplicate copy.

		private int n; //length of the array
		private int stype; //indicates which sort was used

		public final void takeValues()
		{
			while (true)
			{
				System.out.print("\nEnter the number of integers in the array: ");
				n = Integer.parseInt(new Scanner(System.in).nextLine());

			  if (n > 0 && n <= 20)
			  {
					break;
			  }
				else if (n > 20)
				{
					System.out.println("\nArray can have maximum 20 integers.\n");
				}
				else if (n < 0)
				{
					System.out.println("\nEnter positive number.\n");
				}


			}


			for (int i = 0; i < n; i++)
			{
				System.out.print("<" + (i + 1) + "> ");
				arr[i] = Integer.parseInt(new Scanner(System.in).nextLine());
				arr_copy[i] = arr[i];
			}
		}

		private void copyElements()
		{
			for (int i = 0; i < n; i++)
			{
				arr[i] = arr_copy[i];
			}
		}


		private void swap(int x, int y) //Swaps the element at index x with the element at index y
		{
			int temp;

			temp = arr[x];
			arr[x] = arr[y];
			arr[y] = temp;

		}

		private void bubbleSort()
		{
			int cmp_ctr = 0; //Counter to store the number of comparisons.
			int mov_ctr = 0; //Counter to store the number of data movements.

			for (int i = 1; i < n; i++) //For n-1 passes
			{
				//In pass i, compare the first n-i elements
				//with their next elements

				for (int j = 0; j < n - i; j++)
				{
					if (arr[j] > arr[j + 1]) //If the elements are not in the correct order
					{
						//Swap the elements
						swap(j, j + 1);
						mov_ctr++; //Increment number of data movements by 1.
					}
					cmp_ctr++; //Increment number of comparisons by 1.
				}

			}

			System.out.println("\nTotal number of comparisons: " + cmp_ctr);
			System.out.println("\nTotal number of data movements: " + mov_ctr);

			stype = 1;
		}


		private void insertionSort()
		{
			int cmp_ctr = 0; //Counter to store the number of comparisons.
			int mov_ctr = 0; //Counter to store the number of data movements.

			for (int i = 1; i < n; i++) //For n-1 passes
			{
				int temp = arr[i]; //Store the first element of the unsorted list in temp

				int j = i - 1; //j is the index of the last element in the sorted list

				//Starting from the last element in the sorted list
				//shift all elements that are greater than temp in the sorted list
				//one position forward.
				while ((j >= 0) && (arr[j] > temp))
				{
					arr[j + 1] = arr[j];
					j--;
					cmp_ctr++; //Increment number of comparisons by 1.
					mov_ctr++; //Increment number of data movements by 1.

				}

				cmp_ctr++; //Increment number of comparisons by 1.


				//Index j contains an element less than temp.
				//All elements to the right of j in the sorted list are greater than temp
				//and have been moved one position forward.

				//Store temp at index j+1.

				arr[j + 1] = temp;
				mov_ctr++; //Increment number of data movements by 1.
			}
			System.out.println("\nTotal number of comparisons: " + cmp_ctr);
			System.out.println("\nTotal number of data movements: " + mov_ctr);
			stype = 2;
		}





		private void showValues()
		{
			switch (stype)
			{
				case 1:
				{
					System.out.println("\nThe array integers sorted by bubble sort are:\n");
					break;
				}
				case 2:
				{
					System.out.println("\nThe array integers sorted by insertion sort are:\n");
					break;
				}

			}

			for (int i = 0; i < n; i++)
			{
				System.out.println(arr[i]);
			}
		}
		private int getSize()
		{
			return (n);
		}


	public	static void main(String[] args)
		{
			int choice;
			SortTechniques obj = new SortTechniques();
			obj.takeValues();
			do
			{
				System.out.println("Menu");
				System.out.println("====================");
				System.out.println("1.Bubble Sort");
				System.out.println("2.Insertion Sort");
				 System.out.println("3.Exit");
				System.out.print("\nEnter your choice (1,2,3):");

				choice = Integer.parseInt(new Scanner(System.in).nextLine());
				switch (choice)
				{
					case 1:
					{
							obj.copyElements();
							obj.bubbleSort();
							obj.showValues();
							break;
					}
					case 2:
					{
							obj.copyElements();
							obj.insertionSort();
							obj.showValues();
							break;
					}

					case 3:
					{
						System.exit(0);
						break;
					}
					default:
					{
							System.out.println("\nInvalid choice.");
							break;
					}
				}

				System.out.println("\nPress Enter to continue");
				new Scanner(System.in).nextLine();
			} while (choice != 3);
		}
}
