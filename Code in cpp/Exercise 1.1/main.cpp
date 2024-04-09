#include <iostream>

using namespace std;

int isPrime(int num)
{
	int prime = 1;
        for (int i=2; i<=num/2; i++)
        {
	        if (num%i == 0)
                {
                    prime = 0;
                    break;
                }
        }
        return(prime);
}

int main()
{
    int num;
    char ch='y';

    while (ch == 'y')
    {
        cout<< "\nEnter a number :";
        cin>> num;
        if (isPrime(num))
            cout<< "\nEntered number is a prime number."<< endl;
        else
            cout<< "\nEntered number is not a prime number."<< endl;
        cout<< "\nContinue? (y/n): ";
        cin>> ch;
    }
    return(0);
}

