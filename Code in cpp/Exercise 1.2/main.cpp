#include <iostream>

using namespace std;

int isPrime(int num)
{
	int prime = 1;
        for (int i = 2; i <= num/2; i++)
        {
           	if (num % i == 0)
                {
                    prime = 0;
                    break;
                }
        }
      	return (prime);
}

int main()
{
	int count = 0;

	cout << "The first 10 prime numbers are:\n";

        for (int num=2; count<10; num++)
        {
        	if (isPrime(num))
                {
                    cout<< num<< endl;
                    count++;
                }

        }
        return(0);
}
