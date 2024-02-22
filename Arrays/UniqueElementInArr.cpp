#include<iostream>
#include<unistd.h>
using namespace std;

int main()
{
    //find unique elements in array ?
    int noOfTimes;
    // int arr[]={10,20,340,56,88,56,20,30,10};
    int arr[]={10,20,340,10};

    int len=sizeof(arr)/sizeof(int);
    cout<<"Length of array :"<<len<<endl;

    for (int i = 0; i < len ; i++)
    {
        noOfTimes=0;
        for (int j = 0; j < len; j++)
        {
            cout<<"comparing "<<arr[i]<<" with "<<arr[j]<<endl;
            sleep(2);
            if (arr[i]==arr[j])
            {
                noOfTimes++;
                cout<<"both "<<arr[i]<<" and "<<arr[j]<<" are equal:"<<noOfTimes<<endl;
            }
        } 
        if (!(noOfTimes>1))
        {
            cout<<arr[i]<<" is unique!"<<endl;
        }
        sleep(10);
    }
    return 0;
}
//count no. of occurence of every element in array ?
