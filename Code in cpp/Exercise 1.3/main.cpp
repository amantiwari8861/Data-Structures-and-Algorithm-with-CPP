#include <iostream>

using namespace std;

void display(int num)
{
    for (int i = 1; i <= num; i++)
    {
        for (int j = i; j >= 1; j--)
            cout << j << "    ";
        cout << endl;
    }
}

int main()
{
    int num;
    do
    {
        cout << "\nEnter a number between 1 and 9: ";
        cin >> num;
        if ((num < 1) || (num > 9))
            cout << "\nNumber should be between 1 and 9.\n";
    } while ((num < 1) || (num > 9));

    display(num);
    return(0);
}
