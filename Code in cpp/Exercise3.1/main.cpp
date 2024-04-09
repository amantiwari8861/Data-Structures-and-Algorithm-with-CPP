
#include<iostream>
#include<cstring>

using namespace std;

class Names_List
{
    public:

    char arr[20][20];    //Array to be searched
    int n;      	 //Number of elements in the array

    // Function to obtain the value of n
    void getTotalElements()
    {
        while (1)
        {
            cout << "Enter the number of elements in the array: ";
            cin >> n;
            if ((n>0) && (n <= 20))
                break;
            else
                cout << "\nArray should have minimum 1 and maximum 20 elements.\n\n";
        }
    }

    //Function to read array elements
    void read()
    {
        cout << "\n-----------------------\n";
        cout << " Enter the names\n";
        cout << "-----------------------\n";

        for (int i = 0; i < n; i++)
        {
            cout << "<" << (i + 1) << "> ";
            cin >> arr[i];
        }
    }

    //Function to apply linear search

    void linear_search(char item[20])
    {
	    int i;
	    int cmp_count = 0;

	    for (i = 0;i < n; i++)
	    {
		    cmp_count++;

		    if (strcmp(item, arr[i]) == 0)
		    {
			    cout<<endl<<item<<" found at position "<<(i+1)<<endl;
			    break;
		    }
	    }

	    if (i == n)
	    {
		    cout<<endl<<item<< " not found\n";
	    }

	    cout << "Number of comparisons: " << cmp_count << endl << endl;
    }

};

int main()
{
    Names_List nameList;

    nameList.getTotalElements();
    nameList.read();


    char ch;

    do
    {
        //Accept the name to be searched
        char item[20];

        cout<<endl<<"Enter the name to be searched: ";
        cin>>item;

        nameList.linear_search(item);

    cout << "\nContinue search (y/n):";
        cin >> ch;

    } while ((ch == 'y') || (ch == 'Y'));
    return 0;
}

