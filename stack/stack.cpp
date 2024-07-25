#include<iostream>
using namespace std;

template<typename T>
class Stack
{
    T *arr;
    int top,len;
    public:
    Stack()
    {
        arr=new T[5];
        top=-1;
        len=5;
    }
    int push(T data)
    {
        // cout<<"adding the data of size:"<<sizeof(T)<<endl;
        if(top==len-1)
        {
            cout<<"Stack is full!\n";
            return -1;
        }
        arr[++top]=data;
        // cout<<"data inserted succesfully\n";
        return 1;
    }
    void print()
    {
        cout<<"[";
        for (int i = 0; i <= top; i++)
        {
            cout<<arr[i];
            if (i<top)
            {
                cout<<",";
            } 
        }
        cout<<"]\n";
    }
    T pop() 
    {
        if (top == -1) {
            cout << "stack is empty!\n";
            return T();
        }
        T temp = arr[top];
        arr[top--]= T();
        return temp;
    }
    T peek()
    {
        return arr[top];
    }
    ~Stack()
    {
        delete[] arr;
        // cout<<"deleted  array!";
    }
};
int main()
{
    Stack <int>list;
    list.push(100);
    list.print();

    Stack <char>list1;
    list1.push('A');
    list1.push('B');
    list1.push('C');
    list1.print();

    Stack <string>list2;
    list2.pop();
    list2.push("C");
    list2.push("C++");
    list2.push("Java");
    list2.push("Python");
    list2.push("C#");
    list2.push("Delphi");
    cout<<"Removed :"<<list2.pop()<<endl;
    cout<<" Top element :"<<list2.peek()<<endl;
    list2.print();

    return 0;
}
