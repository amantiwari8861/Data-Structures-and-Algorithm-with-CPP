#include<iostream>
using namespace std;

void printArr(int len,int arr[])
{
    cout<<"[";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i];
        if (i<len-1)
        {
            cout<<",";
        }
    }
    cout<<"]"<<endl;
}

int main()
{
    // int arr[]={70,80,30,10,20};
    int arr[]={4,3,2,10,12,1,5,6};
    int len=sizeof(arr)/sizeof(int);
    int pivot,j;
    cout<<"The unsorted array is :";
    printArr(len,arr);
    for (int i = 1; i < len; i++)
    {
        pivot=arr[i];
        cout<<"pivot="<<pivot<<endl;
        j=i-1;
        cout<<"at i="<<i<<" ";
        while (j>=0 && arr[j]>pivot)
        {
            arr[j+1]=arr[j];
            j--;
            cout<<"\t";
            printArr(len,arr);
        }
        arr[j+1]=pivot;
        cout<<"final array is :";
        printArr(len,arr);
    }
    cout<<"the sorted array is :";
    printArr(len,arr);

    return 0;
}
