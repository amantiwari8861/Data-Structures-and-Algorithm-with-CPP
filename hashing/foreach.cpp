#include<iostream>
using namespace std;

int main()
{
    int arr[]={10,20,34,5,8,9,90};

    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i];
    }
    
    for(int e : arr)
    {
        cout<<e<<endl;
    }


    return 0;
}
