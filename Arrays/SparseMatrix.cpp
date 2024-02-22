#include<iostream>
using namespace std;
class SparseMatrix
{
    int row,col,count;
    int **matrix;
    public:
    SparseMatrix()
    {
        cout<<"enter row :";
        cin>>row;
        cout<<"enter col :";
        cin>>col;
        matrix=new int*[row];
        inputMatrix(matrix,row,col);
    }
    void inputMatrix(int **matrix,int row,int col)
    {
        cout<<"enter the elements in matrix :\n";
        for (int i = 0; i < row; i++)
        {
            matrix[i]=new int[col];
            for (int j = 0; j < col; j++)
            {
                cin>>matrix[i][j];
                if(matrix[i][j]!=0)
                {
                    count++;
                }
            }            
        }
    }
    void printMatrix()
    {
        cout<<"the matrix is :\n";
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                cout<<"\t"<<matrix[i][j];
            }
            cout<<"\n";
        }
    }
};
int main()
{
    SparseMatrix sm;
    sm.printMatrix();
    return 0;
}
