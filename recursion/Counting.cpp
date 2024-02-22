#include<iostream>
using namespace std;

void counting(int num)
{
    if (num>0)
    {
        // counting(num-1);     
        cout<<" Num = "<<num<<endl;
        // counting(num-1);     
        counting(num-1);     
    }
}
int main()
{
    counting(3);
    return 0;
}
