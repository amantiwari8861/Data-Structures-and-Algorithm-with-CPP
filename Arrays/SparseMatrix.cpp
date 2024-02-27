#include<iostream>
using namespace std;
class SparseMatrix
{
    int row,col,count;
    int **matrix,**sparse;
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
    void generateSparse()
    {
        int r=0;
        sparse=new int*[count+1];
        for (int i = 0; i < row; i++)
        {
            sparse[i]=new int[3];
            if (r==0)
            {
                sparse[r][0]=row;
                sparse[r][1]=col;
                sparse[r][2]=count;
            }
            for (int j = 0; j < col; j++)
            {
                if (matrix[i][j]!=0)
                {
                    cout<<"hii";
                    sparse[r][0]=i;
                    sparse[r][1]=j;
                    sparse[r][2]=matrix[i][j];
                    r++;
                }                
            }
        }
        cout<<"the sparse matrix is \n";
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout<<"  "<<sparse[i][j];
            }
            cout<<endl;
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
    // sm.printMatrix();
    sm.generateSparse();
    return 0;
}
