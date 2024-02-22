#include<iostream>
using namespace std;

int main()
{
    int arr[]={10,20,340,56,88,56,20,30,67};

    int len=sizeof(arr)/sizeof(int);
    cout<<"Length of array :"<<len<<endl;

    int arr2[len];
    //logic
    for (int i = len-1; i >=0; i--)
    {
        arr2[len-i-1]=arr[i];
    }
    cout<<"the copied Array is :[";
    for (int i = 0; i < len; i++)
    {
        cout<<arr2[i];
        if (i<len-1)
        {
            cout<<",";
        }
    }
    cout<<"]\n";
    return 0;
}
/*
    H.W.
    1.take 10 no. from user and find maximum number.
    2.take 10 no. from user and find minimum number.
    3.take 10 no. from user and take a number to search from array and find the index of that number.(linear search)
    4.copy one array's elements to another array.
    5.copy one array's elements to another array in reverse order.
    6.Write a c++ program to find the common elements between two arrays of integers.  
    7.Write a c++ program to find the second largest element in an array.  
    8.Write a c++ program to test the equality of two arrays.  
    9. Write a c++ program to find the number of even and odd integers in a given array of integers.  
    10.Write a c++ program to get the difference between the largest and smallest values in an array of integers.
    11.take a matrix from user and print that.
    12.find the sum of all elements in a matrix.
    13.take a matrix dimension from user and get value in that matrix and print them.
    14.count all even elements in an matrix.
    15.take 2 matrix from user and subtract them.
    16.count non-zero elements in a matrix.
*/