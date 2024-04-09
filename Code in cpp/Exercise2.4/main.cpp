#include <iostream>
# include <cstring>
using namespace std;

class List
{
 public:

char  tname[20], words[20][20];

       int   i, j, n;
    // Function to accept array elements
    void read()
    {
        // Get the number of elements to store in the array
        while (true)
        {
             cout<<"Enter the number of strings:  ";
       cin>>n;

            if (n > 0 && n <= 20)
                break;
            else if (n > 20)
                cout<<"\nYou can enter maximum 20 strings.\n";
        }

        cout<<"";
        cout<<"-----------------------------------------------";
        cout<<" \nEnter the strings to be sorted (each one word)";
        cout<<"\n-----------------------------------------------";


        // User inputs for the array
        for (int i = 0; i < n; i++)
        {
            cout<<"\nEnter the string " << (i + 1)<<":";

            cin>>words[i];
        }
    }

    void display()
    {
        // Display the sorted array
        cout<<"";
        cout<<"\n-----------------------";
        cout<<" \nSorted strings ";
        cout<<"\n-----------------------";

        for (int j = 0; j < n; j++)
        {
            cout<<"\n"<<words[j];
        }
    }



    // Function to sort using Insertion sort
    void InsertionSort()
    {
        for (int i = 1; i <= n - 1; i++)
        {char temp[20];
            strcpy(temp,words[i]);
            int j = i - 1;


            while ((j >= 0) && (strcmp(words[j],temp)>0))
            {
               strcpy(words[j + 1],words[j]);
                j=j - 1;
            }
            strcpy(words[j + 1],temp);
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
      myList.InsertionSort();  /* First call to Insertion Sort Algorithm */

      // Display sorted array
	  myList.display();
return 0;
}





