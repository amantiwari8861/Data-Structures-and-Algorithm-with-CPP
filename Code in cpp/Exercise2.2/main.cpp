#include <iostream>

using namespace std;
# include <cstring>
int main()
{

       char  tname[20], word[20][20];

       int   i, j, n;
       cout<<"Enter the number of strings:  ";
       cin>>n;
cout<<"\nEnter the strings to be sorted:";
       for(i=0; i<n; i++)
       {
              cout<<"\nEnter the string "<<(i+1)<<": ";
              cin>>word[i];
       }
        // For n – 1 passes
       for(i=1; i<n; i++)
   // In pass i, compare the first n – i elements with their next elements

       for(j =0; j<n-1; j++)
// If the elements are not in the correct order

       if(strcmp(word[j], word[j+1])>0)
       {

              // swap the two elements
              strcpy(tname, word[j]);
              strcpy(word[j], word[j+1]);
              strcpy(word[j+1], tname);
       }
       cout<<"\nSorted strings:\n";
       for (i =0; i<n; i++)
       cout<<"\n"<<word[i];
       cout<<endl;
       return 0;
}
