#include<iostream>
using namespace std;

struct Node0
{
    int data;
    Node0* next;
};
class Node1
{
    public:
    int data;
    Node1* next;
};
class Node
{
    int data;
    Node* next;
    public:
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
    int getData()
    {
        return data;
    }
    void setData(int data)
    {
        this->data=data;
    }
};
class Node2
{
    int data;
    Node2* next;
    friend void insert(Node2 n2);
};
void insert(Node2 n2)
{
    
}

int main()
{
    Node n1(100);
    // cout<<n1.getData();
    n1.setData(101);
    cout<<n1.getData();

    return 0;
}
