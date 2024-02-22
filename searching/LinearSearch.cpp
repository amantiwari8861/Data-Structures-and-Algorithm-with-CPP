#include<iostream>
using namespace std;


int main()
{
    int n;
    cout<<"enter the size :";
    cin>>n;

    int arr[n];
    cout<<"enter the elements in array :\n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    int key;
    cout<<"enter a key to be searched:";
    cin>>key;
    
    bool isFound=0;
    for (int i = 0; i < n; i++)
    {
        if (key==arr[i])
        {
            cout<<"found at index position "<<i<<endl;
            isFound=1;
            break;
        }
        // else  //do not use this
        // {
        //     cout<<"element not found at "<<i<<endl;
        // }   
    }
    if (!isFound)
    {
        cout<<"Not found in array "<<endl;
    }
    return 0;
}
