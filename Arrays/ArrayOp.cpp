#include <iostream>
#include<conio.h>
#define GREEN "\x1B[92m"
#define RESET "\033[0m"

using namespace std;

class ArrayOp
{
    int n;
    int *arr;

public:
    ArrayOp()
    {
        cout << "enter the array size:";
        cin >> n;
        arr = new int[n];
        inputArr();
    }
    void insertAtPos(int pos, int element)
    {
        arr=(int*)realloc(arr,sizeof(int)*(n+1));
        for (int i = n; i >= pos; i--)
        {
            arr[i + 1] = arr[i];
        }
        arr[pos] = element;
        n++;
        cout<<"succesfully inserted at position :"<<pos<<endl;
    }
    void printArr()
    {
        cout <<GREEN<<"The Array is :[";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i < n-1)
            {
                cout << ",";
            }
        }
        cout << "]"<<RESET<<endl;
    }
    void inputArr()
    {
        cout << "enter values in array " << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
    }
    int linearSearch(int key)
    {
        int pos = -1;
        for (int i = 0; i < n; i++)
        {
            if (key == arr[i])
            {
                pos = i;
                break;
            }
            // else  //do not use this
            // {
            //     cout<<"element not found at "<<i<<endl;
            // }
        }
        return pos;
    }
    void updateInArr()
    {
    }
    void deleteInArr()
    {
    }
    ~ArrayOp()
    {
        // cout<<"destructor called";
        delete arr;
    }
};
int main()
{
    ArrayOp arrObj;
    int choice,pos,element,key;
    do
    {
        system("cls");
        cout << "1.insert at position in array " << endl;
        cout << "2.update in array " << endl;
        cout << "3.delete in array " << endl;
        cout << "4.search in array " << endl;
        cout << "5.print array " << endl;
        cout << "0.exit " << endl;

        cout << "enter the choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "enter pos :";
            cin >> pos;
            cout << "enter element :";
            cin >> element;
            arrObj.insertAtPos(pos, element);
            break;
        case 2:
            arrObj.updateInArr();
            break;
        case 3:
            arrObj.deleteInArr();
            break;
        case 4:
            cout << "enter the key to be searched:";
            cin >> key;
            pos = arrObj.linearSearch(key);
            if (pos != -1)
            {
                cout << "found at index position " << pos << endl;
            }
            else
            {
                cout << "Not found in array " << endl;
            }
            break;
        case 5:
            arrObj.printArr();
            break;
        case 0:
            cout << "Thank You ...";
            exit(0);
            break;
        default:
            cout << "invalid choice!";
            break;
        }
        cout<<"press any key to continue...";
        // char ch=getch();
        // cout<<"the hidden input is "<<ch<<(int)ch<<endl;
        getch();
    } while (choice != 0);

    return 0;
}

// H.w revise structure,Loops,functions,pointers,array,dynamic memory allocation