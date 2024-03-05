#include<iostream>
using namespace std;

template<typename T>
class Node
{
    T data;
    Node* left;
    Node* right;
    public:
    Node(){}
    Node(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
template<typename T>
class BinarySearchTree
{
    Node<T>* root;
    public:
    


};
int main()
{
    BinarySearchTree<int> bst;
    char choice;
    do
    {
        cout<<"";
    } while (choice!=0);
    return 0;
}