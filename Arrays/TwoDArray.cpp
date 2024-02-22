#include<iostream>
using namespace std;

int main()
{
    //1 dimension -> country name
    //2 dimension -> states name in countries
    //3 dimension -> city name in states in countries
    //4 dimension -> district name in city in state in country
    // and so on
    // N dimension

    //1D Array
    string country[3]={"india","America","Australia"};
    // cout<<"Countries Name :";
    // for (int i = 0; i < 3; i++)
    // {
    //     cout<<country[i]<<" , ";
    // }
    // cout<<endl;

    //2D array
    string states[3][4]={
                            {"UP","MP","UK","Goa"},
                            {"NYC","California","Texas","W. DC"},
                            {"sydney","south wales","Queensland","victoria"}
                        };

    // cout<<"States Name :"<<endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout<<states[i][j]<<"\t";
    //     }
    //     cout<<"\n";
    // }

    int covidCases[3][4];
    for (int i = 0; i < 3; i++)
    {
        cout<<"enter the data of "<<country[i]<<":"<<endl;
        for (int j = 0; j < 4; j++)
        {
            cout<<"\tenter covid cases in "<<states[i][j]<<":";
            cin>>covidCases[i][j];
        }
    }
    
    cout<<"Total covid Cases as follows \n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<"\t"<<covidCases[i][j];
        }
        cout<<endl;
    }
    return 0;
}
