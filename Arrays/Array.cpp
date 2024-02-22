#include <iostream>
using namespace std;
void insertAtPos(int, int *, int, int);
void printArr(int*,int);
void inputArr(int*,int);
int main()
{
    int n;    
    cout << "enter the array size:";
    cin >> n;
    int arr[n + 1];
    inputArr(arr,n);
    
    int pos, element;
    cout << "enter pos :";
    cin >> pos;
    cout << "enter element :";
    cin >> element;

    insertAtPos(pos, arr, n, element);
    printArr(arr,n);
    return 0;
}
void insertAtPos(int pos, int arr[], int n, int element)
{
    for (int i = n; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = element;
}
void printArr(int arr[], int n)
{
    cout << "The Array is :[";
    for (int i = 0; i < n + 1; i++)
    {
        cout << arr[i];
        if (i < n)
        {
            cout << ",";
        }
    }
    cout << "]";
}
void inputArr(int arr[],int n)
{
    cout << "enter values in array " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}