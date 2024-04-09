#include <iostream>
#include <cstring>
using namespace std;
class Search
{
    char arr[20][20];    //Array to be searched
    int n;      //Number of elements in the array

    public:

    void read_elements()
    {

        int i;

            // Get the number of elements to store in the array
            while (true)
            {
                cout<<"Enter the total number of names in the array: ";
               cin>>n;
                if ((n > 0) && (n <= 20))
                    break;
                else
                    cout<<"\nArray should have minimum 1 and maximum 20 elements.\n";
            }

            //Accept array elements
            cout<<"\n";
            cout<<"-----------------\n";
            cout<<" Enter the names\n ";
            cout<<"-----------------\n";

            for (i = 0; i < n; i++)
            {
                cout <<"<" <<(i + 1) << "> ";
                cin>> arr[i];
            }
        }


    void bubble_sort()
        {
            for (int i = 1; i < n; i++)	// For n - 1 passes
            {
                // In Pass i, compare the first n - i elements
                // with their next elements

                for (int j = 0; j < n - i; j++)
                {
                    if (strcmp(arr[j],arr[j + 1])>0) // If the elements
                    // are not in the correct order
                    {
                        // Swap the elements
                        char temp[20];
                        strcpy(temp,arr[j]);
                        strcpy(arr[j],arr[j + 1]);
                        strcpy(arr[j + 1],temp);
                    }
                }

            }
        }


        void binary_search(char item[20])
        {
            //Apply binary search
            int lowerbound = 0;
            int upperbound = n - 1;
            int count = 1;
            //Obtain the index of the middlemost element
            int mid = (lowerbound + upperbound) / 2;

            while ((strcmp(item, arr[mid]) != 0) && (lowerbound <= upperbound))
            {
                if (strcmp(item, arr[mid]) > 0)
                    lowerbound = mid + 1;
                else
                    upperbound = mid - 1;

                mid = (lowerbound + upperbound) / 2;
                count++;
            }

      cout <<"\n";
           if (strcmp(item, arr[mid]) == 0)
            cout << endl << item << " found at position " << (mid + 1) << " in the sorted array" << endl;
        else
            cout << endl << item << " not found in the array\n";

 cout<<"\nNumber of comparisons: " << count<<"\n";
        }

void display()
        {
            for (int i = 0; i < n; i++)
            {
                cout<<arr[i]<<"\n";
            }
        }

};

int main()
{



            Search obj;

            obj.read_elements();
            obj.bubble_sort();

            cout<<"\nThe sorted list is:\n";
            obj.display();

            cout<<"\n";
            char ch;

            do
            {
                //Accept the name to be searched
            cout << "\nEnter the name to be searched: ";

       char item[20];
       cin >> item;

                obj.binary_search(item);
                cout << "\nContinue search (y/n):";
       cin >> ch;

            } while ((ch == 'y') || (ch == 'Y'));
        }













