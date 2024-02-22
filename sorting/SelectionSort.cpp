#include<iostream>
#define BGR "\x1B[92m"
#define RESET "\033[0m"
using namespace std;

int main()
{
    int arr[]={45,6576,878,23,12,67};
    // int min=arr[0];
    // for (int i = 1; i < 6; i++)
    // {
    //     if(arr[i]<min)
    //     {
    //         min=arr[i];
    //     }
    // }
    //cout<<"the minimum element is :"<<min;
    
    cout<<"\nThe UnSorted Array is :";
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i];
        if (i<6-1)
        {
            cout<<",";
        }
    }
    cout<<"\n";
    int min_index;
    for (int i = 0; i < 6-1; i++)
    {
        min_index=i;
        for (int j = i+1; j < 6; j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        cout<<" index :"<<min_index<<endl;
        if(min_index != i)
        {
            cout<<"Swapping "<<arr[min_index]<<" with "<<arr[i]<<endl;
            int temp=arr[min_index];
            arr[min_index]=arr[i];
            arr[i]=temp;
        }
        cout<<"------after step "<<i<<" Array is :";
        for (int k = 0; k < 6; k++)
        {
            if(k<=i)
                cout<<BGR<<arr[k]<<RESET;
            else
                cout<<arr[k];
            if (k<6-1)
            {
                cout<<",";
            }
        }
        cout<<endl;
    }
    cout<<"\nThe Sorted Array is :";
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i];
        if (i<6-1)
        {
            cout<<",";
        }
    }
    return 0;
}
