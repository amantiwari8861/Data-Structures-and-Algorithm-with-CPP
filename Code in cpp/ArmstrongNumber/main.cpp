#include <iostream>
using namespace std;
int main()
{

   int num, temp, rem, arm=0;
    cout<<"Enter a number: ";
    cin>>num;
    temp = num;
    while(num>0)
    {
        rem = num%10;
        arm = arm + (rem*rem*rem);
        num = num/10;
    }

    if(temp==arm)
    cout<<"It is an Armstrong number"<<endl;
    else
    cout<<"It is not an Armstrong number";
    return 0;
}
