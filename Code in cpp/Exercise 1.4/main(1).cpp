
#include <iostream>

using namespace std;

int main()
{
    int n;
    while (1)
    {
        cout << "\nEnter the number of lines in the pyramid:";
        cin >> n;

        if ((n < 1) || (n > 9))
            cout << "\nNumber should be between 1 to 9."<< endl << endl;
        else
            break;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j=1; j<=n-i; j++)
            cout << "  ";
        for (int j=1; j<=i; j++)
            cout << j << " ";
        for (int j=i-1; j>0; j--)
            cout << j << " ";
        cout << endl;
    }
    return(0);
}
