#include <iostream>
using namespace std;
#include <cstring>

class List
{
    public:

        char str[20][20];

        int cmp_count;  // Number of comparisons
        int mov_count;  // Number of data movements
        int n; // Number of elements in the array

        List()
        {
            cmp_count = 0;
            mov_count = 0;
        }

	void read()
	{
		// Get the number of elements to store in the array
		while (true)
		{
			cout << "\nEnter the number of strings to be sorted: ";
			cin >> n;
			    if (n>0 && n<= 20)
                break;
            else if(n>20)
                cout<<"\nYou can enter maximum 20 strings.\n";
		}

		cout << "\n----------------------------\n";
		cout << " Enter strings (1 word each)  \n";
		cout << "------------------------------\n";

		// Get array elements
		for (int i = 0; i < n; i++)
		{
		    cout<<"Enter string "<<i+1<<": ";
			cin>>str[i];
		}
	}

		void swap(int x, int y) /* Swaps the element at index x
	   				     	    with the element at index y */
     	{
               char tname[20];

               strcpy(tname, str[x]);
              strcpy(str[x], str[y]);
              strcpy(str[y], tname);

         }

        void q_sort(int low, int high)
        {
            int i, j;

            char pivot[20];
            if (low > high)
                return;

            // Partition the list into two parts:
            // One containing elements less than or equal to pivot
            // Other containing elements greater than pivot
            i = low+1;
            j = high;
            strcpy(pivot,str[low]);
            while (i <= j)
            {
              // Search for an element greater than pivot


              while ((strcmp(pivot, str[i])>=0)&&(i <= high))

              {
                   i++;
			  cmp_count++;
              }
			  cmp_count++;

                // Search for an element less than or equal to pivot
while ((strcmp(str[j],pivot)>0)&& (j >= low))

             {
                    j--;
			   cmp_count++;
              }
		    cmp_count++;

              if (i < j)  // If the greater element is on the
                            // left of the smaller element
              {
             /* Swap the element at index i with the element at index j */
                 swap(i, j);
 			 mov_count++;
                }
              }

            /* j now contains the index of the last element in the
   			sorted list. */

            if (low < j)
		  {
              swap(low,j);    // Move the pivot to its correct
 // position in the list
		    mov_count++;
            }

            // Sort the list on the left of the pivot using quick sort
            q_sort(low, j - 1);

            // Sort the list on the right of the pivot using quick sort
            q_sort(j + 1, high);
        }

        void display()
	   {
		cout << "\n-----------------------\n";
		cout << " Sorted strings are: \n";
		cout << "-----------------------\n";

		for (int j = 0; j < n; j++)
		{
			cout << str[j] << endl;
		}

		cout << "\nNumber of comparisons: " << cmp_count;
		cout << "\nNumber of data movements: " << mov_count;
	   }

   	   int getSize()
	   {

		return (n);

	   }
};

int main()
{
       // Declaring the object of the class
       List myList;

	   // Accept array elements
	   myList.read();



      // Calling the sorting function
      myList.q_sort(0, myList.getSize() - 1);  /* First call to Quick
                                                  Sort Algorithm */
     // Display sorted array
	  myList.display();
	  return 0;
}
