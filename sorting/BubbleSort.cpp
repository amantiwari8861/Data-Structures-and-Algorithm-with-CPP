#include<iostream>
using namespace std;

int main()
{
    // int arr[]={45,6576,878,23,12,67};
    // int len=sizeof(arr)/sizeof(int);

    string arr[]={"aman","udit","Pankaj","udita","pankaj","kasak","pinki","Aman","1Aman"};
    int len=sizeof(arr)/sizeof(string);

    for (int pass = 0; pass < len-1; pass++)
    {
        for (int i = 0; i < len-pass-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                // int temp=arr[i];
                string temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
        }   
    }
    cout<<"The sorted Array is :";
    for (int i = 0; i < len; i++)
    {
        cout<<arr[i];
        if (i<len-1)
        {
            cout<<",";
        }
    }
    return 0;
}
