#include <iostream>

using namespace std;

class MergedArray
{
    public:

    int arr[20];
    void display()
    {
        cout << "\nThe merged list is:" << endl;
        for (int i = 0; i < 20; i++)
            cout << arr[i] << endl;
        cout << endl;
    }
};

class Array
{
    int arr[10];

    public:

    void accept()
    {
        for (int i = 0; i < 10; i++)
        {
            while(1)
            {
                cout << "<" << (i+1) << "> ";
                cin >> arr[i];
                if ((i>0) && (arr[i] < arr[i-1]))
                    cout << "\nNumbers must be entered in ascending order. Try again.\n";
                else
                    break;
            }
        }
    }

    MergedArray merge(Array A)
    {
        MergedArray result;
        int i, j, k;
        i = 0;
	j = 0;
	k = 0;
        while ((i < 10) && (j < 10))
        {
            if (arr[i] <= A.arr[j])
                result.arr[k++] = arr[i++];
            else
                result.arr[k++] = A.arr[j++];
        }

        while (i < 10 )
        {
            result.arr[k++] = arr[i++];
        }

        while (j < 10)
        {
            result.arr[k++] = A.arr[j++];
        }

        return (result);
    }
};

int main()
{
    Array A1;
    Array A2;
    MergedArray A3;

    cout << "\nEnter the first list of numbers in ascending order.\n";
    A1.accept();

    cout << "\nEnter the second list of numbers in ascending order.\n";
    A2.accept();

    A3 = A1.merge(A2);
    A3.display();

    return 0;
}
