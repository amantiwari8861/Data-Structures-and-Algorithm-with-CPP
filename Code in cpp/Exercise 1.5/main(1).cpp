#include <iostream>

using namespace std;

int main()
{
    char str[50];  //The string in which substring is to be searched
    char substr[50]; //The substring to be searched

    cout << "\nEnter the string in which substring is to be searched: ";

cin.getline (str,50);

    cout << "\nEnter the substring to be searched: ";

cin.getline (substr,50);
    int i = 0;
    int len1,len2;
    for (len1=0; str[len1]!= '\0'; len1++); //len1 is the length of str
    for (len2=0; substr[len2]!= '\0'; len2++); //len2 is the length of substr

    int match = 0;

    while (i < len1)
    {
        while ((i < len1) && (str[i] != substr[0]))
            i++;

        if (i+len2 > len1)
            break;
        else
        {
            int j = i;
            int k = 0;
            while ((j < len1) && (k < len2) && (str[j] == substr[k]))
            {
                j++;
                k++;
            }

            if (k == len2)
            {
                match = 1;
                break;
            }
        }
        i++;
    }

    if (match)
        cout << "\nSubstring found at position " << (i + 1) << " in the string.\n";
    else
        cout << "\nSubstring not found in the string.\n";
        return(0);
}
