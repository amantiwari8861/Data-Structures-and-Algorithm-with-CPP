#include<iostream>
using namespace std;

int main()
{
    int arr[6],i,j;
    cout<<" enter 6 variables :"<<endl;
    for ( i = 0; i < 6; i++)
    {
        cin>>arr[i];
    }
    
    //logic
    for(i=1;i<6;i++)
    {
        for(j=0;j<6;j++)
        {
            if (arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }   
        }
    }
    cout<<"the Sorted array is :"<<endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<arr[i]<<" "<<endl;
    }
    
    return 0;
}
