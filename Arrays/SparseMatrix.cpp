#include<iostream>
using namespace std;
class SparseMatrix
{
    int row,col,count;
    int **matrix,**sparse;
    public:
    SparseMatrix()
    {
        count=0;
        cout<<"enter row :";
        cin>>row;
        cout<<"enter col :";
        cin>>col;
        inputMatrix(row,col);
    }
    void inputMatrix(int row,int col)
    {
        matrix=new int*[row];
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
        // cout<<"Row :"<<row<<" Col:"<<col<<" Count : "<<count<<endl;
        int r=0;
        sparse=new int*[count+1];
        for (int i = 0; i < count; i++)
            sparse[i]=new int[3];
        
        for (int i = 0; i < row; i++)
        {
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
                    r++;
                    sparse[r][0]=i;
                    sparse[r][1]=j;
                    sparse[r][2]=matrix[i][j];
                }                
            }
        }
        cout<<"the sparse matrix is \n";
        for (int i = 0; i <= count; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout<<"  "<<sparse[i][j];
            }
            if(i==0)
                cout<<"\n---------------------\n";
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
    sm.printMatrix();
    sm.generateSparse();
    cout<<"thank you !!";
    return 0;
}
