#include <iostream>
using namespace std;
class List
{
    public:
        int arr[20];    // Array of integers to hold values


        int n; // Number of elements in the array


	void read()
	{
		// Get the number of elements to store in the array
		while (1)
		{
			cout << "\nEnter the number of elements in the array: ";
			cin >> n;
		            if (n>0 && n<= 20)
                break;
            else if(n>20)
                cout<<"\nArray can have maximum 20 elements.\n";
            else if (n < 0)
                cout<<"\nEnter positive number.\n";



		}

		cout << "\n-----------------------\n";
		cout << " Enter array elements  \n";
		cout << "-----------------------\n";

		// Get array elements
		for (int i = 0; i < n; i++)
		{
			cout << "<" << (i + 1) << "> ";
			cin >> arr[i];
		}
	}


        void insertion_sort()
        {


        for (int i = 1; i <= n-1; i++)
        {
            int temp = arr[i];
            int j= i-1;

            while ((j >= 0) && (arr[j] > temp))
            {
                arr[j+1] = arr[j];
                j = j - 1;
            }
            arr[j+1] = temp;

        }
        }

        void display()
	   {
		cout << "\n-----------------------\n";
		cout << " Sorted array elements \n";
		cout << "-----------------------\n";

		for (int j = 0; j < n; j++)
		{
			cout << arr[j] << endl;
		}


	   }


};

int main()
{
        // Declaring the object of the class
        List myList;

	   // Accept array elements
	   myList.read();

        // Calling the sorting function
        myList.insertion_sort();  /* First call to
     Insertion Sort Algorithm */

        // Display sorted array
	   myList.display();
	   return 0;
}
