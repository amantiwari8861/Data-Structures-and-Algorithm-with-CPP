#include <iostream>
using namespace std;

int main()
{
    /*
            1
           121
          12321
         1234321
        123454321
    */
    // 1st approach
    /* for (int i = 1; i <= 5; i++)
    {
        for (int sp = 5; sp > i; sp--)
        {
            cout<<" ";
        }
        for (int f1 = 1; f1 <= i; f1++)
        {
            cout<<f1;
        }
        for (int f2 = i-1; f2 > 0; f2--)
        {
            cout<<f2;
        }
        cout<<"\n";
    } */

    int val, sp;
    for (int i = 1; i <= 5; i++)
    {
        val = 1;
        sp = 5 - i;
        for (int j = 1; j <= 9; j++)
        {
            if (sp > 0)
            {
                cout << " ";
            }
            else
            {
                if (j <= 5 && val > 0)
                {
                    cout << val;
                    val++;
                }
                if (j == 5)
                {
                    val--;
                }
                if (j > 5 && val > 1)
                {
                    val--;
                    cout << val;
                }
            }
            sp--;
        }
        cout << "\n";
    }
    // int val,sp;
    // for (int i = 1; i <= 5; i++)
    // {
    //     val=1;
    //     sp=5-i;
    //     for (int j = 1; j <= 9; j++)
    //     {
    //         if(j<5)
    //         {
    //             if(sp>0)
    //             {
    //                 cout<<" ";
    //             }
    //             else
    //             {
    //                 cout<<val;
    //                 val++;
    //             }
    //         }
    //         if(j>=5)
    //         {
    //             if(val>=1)
    //             {
    //                 cout<<val;
    //             }
    //             val--;
    //         }
    //         sp--;
    //     }
    //     cout<<"\n";
    // }

    return 0;
}
