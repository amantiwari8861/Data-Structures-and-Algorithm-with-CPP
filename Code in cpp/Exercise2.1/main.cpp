#include <iostream>

using namespace std;

class sortTechniques
{
	private:

		int arr[20]; //array declaration
		int arr_copy[20]; //Copy of the original array. This is required
                                  //because you need to sort the same array using
                                  //different sorting techniques. Once the array is
                                  //sorted using one sorting technique, the array would
                                  //contain the elements in sorted order. Therefore, you
                                  //need to maintain a copy of the original array. The sorting
                                  //will be performed on the original array. Before sorting the
                                  //array again using another technique, you need to restore
                                  //the contents of the original array from the contents of
                                  //the duplicate copy.
		int n;	     //length of the array
		int stype;   //indicates which sort was used

	public:

		void takeValues()
		{
			while (1)
			{

				cout<<"\nEnter the number of integers in the array: ";
				cin>>n;

					if (n>0 && n<= 20)
                break;




            else if(n>20)
                cout<<"\nArray can have maximum 20 integers.\n";
            else if (n < 0)
                cout<<"\nEnter positive number.\n";
            }



			cout << endl;

			for (int i = 0; i < n; i++)
			{
				cout<<"<"<<i+1<<"> ";
				cin>>arr[i];
				arr_copy[i] = arr[i];
			}
		}


		void swap(int x, int y)  //Swaps the element at index x with the element at index y
		{
			int temp;

			temp = arr[x];
			arr[x] = arr[y];
			arr[y] = temp;

		}

		void bubbleSort()
		{
			int cmp_ctr=0;	//Counter to store the number of comparisons.
			int mov_ctr=0;	//Counter to store the number of data movements.

			for (int i = 1; i < n; i++)	//For n-1 passes
			{
				//In pass i, compare the first n-i elements
				//with their next elements

				for (int j = 0; j < n - i; j++)
				{
					if (arr[j] > arr[j+1]) //If the elements are not in the correct order
					{
						//Swap the elements
						swap (j, j+1);
						mov_ctr++;	//Increment number of data movements by 1.
					}
					cmp_ctr++;	//Increment number of comparisons by 1.
				}

			}

			cout<<"\nTotal number of comparisons: "<<cmp_ctr<<endl;
			cout<<"\nTotal number of data movements: "<<mov_ctr<<endl;

			stype = 1;
		}


		void insertionSort()
		{
			int cmp_ctr=0; 	//Counter to store the number of comparisons.
			int mov_ctr=0;	//Counter to store the number of data movements.

			for (int i = 1; i < n; i++)	//For n-1 passes
			{
				int temp = arr[i];	//Store the first element of the unsorted list in temp

				int j = i-1;		//j is the index of the last element in the sorted list

				//Starting from the last element in the sorted list
				//shift all elements that are greater than temp in the sorted list
				//one position forward.
				while ((j >= 0) && (arr[j] > temp))
				{
					arr[j+1] = arr[j];
					j--;
					cmp_ctr++;	//Increment number of comparisons by 1.
					mov_ctr++;	//Increment number of data movements by 1.

				}

				cmp_ctr++;	//Increment number of comparisons by 1.


				//Index j contains an element less than temp.
				//All elements to the right of j in the sorted list are greater than temp
				//and have been moved one position forward.

				//Store temp at index j+1.

				arr[j+1] = temp;
				mov_ctr++;		//Increment number of data movements by 1.
			}
			cout<<"\nTotal number of comparisons: "<<cmp_ctr<<endl;
			cout<<"\nTotal number of data movements: "<<mov_ctr<<endl;
			stype = 2;
		}




		void showValues()
		{
			switch ( stype )
			{
				case 1: { cout<<"\nThe array integers sorted by bubble sort are:\n"; break; }
				case 2: { cout<<"\nThe array integers sorted by insertion sort are:\n"; break; }

			}

			for ( int i = 0 ; i < n ; i++ )
				cout<<arr[i]<<endl;
		}

		void copyElements()
	        {
        	    for (int i = 0; i < n; i++)
            	    {
                	arr[i] = arr_copy[i];
            	    }
        	}
};


int main()
{

	int choice;

	sortTechniques obj;
	obj.takeValues();

	do
	{

		cout<<"\nMenu\n";
		cout<<"=============================================\n";
		cout<<"1.Bubble Sort\n";
		cout<<"2.Insertion Sort\n";
		cout<<"3.Exit\n";

		cout<<"\nEnter your choice (1,2,3):";
		cin>>choice;

		switch(choice)
		{
			case 1: { 	obj.copyElements();
					obj.bubbleSort();
					obj.showValues();
					break; 			}
			case 2: { 	obj.copyElements();
					obj.insertionSort();
					obj.showValues();
					break; 			}

			case 3: { 	break;			}
			default:{ 	cout<<"\nInvalid choice.\n";
					break; 			}
		}





	} while (choice != 3);
}





















