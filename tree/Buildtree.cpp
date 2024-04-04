#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <vector>
using namespace std;

template <typename T>
class Node
{
    T data;
public:
    Node *left;
    Node *right;
    Node() {}
    Node(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    T getData()
    {
        return data;
    }
};
template <typename T>
class BinarySearchTree
{
public:
    Node<T> *root;
    int totalNodes;
    BinarySearchTree()
    {
        root=NULL;
        totalNodes=0;
    }
    T getData()
    {
        T data;
        cout << "Enter data in node:";
        cin >> data;
        return data;
    }
    void addNode()
    {
        if(root==NULL)
        {
            root=add(root, getData());
            totalNodes++;
        }
        else
        {
            add(root,getData());
            totalNodes++;
        }
    }
    void addNode(T data)
    {
        if(root==NULL)
        {
            root=add(root,data);
            totalNodes++;
        }
        else
        {
            add(root,data);
            totalNodes++;
        }
    }
    Node<T> *add(Node<T> *cn,T data)
    {
        if (cn == NULL) //Base condition
        {
            cout<<"Root or Leaf Node added :"<<data<<endl;
            return new Node<T>(data);
        }
        if (data < cn->getData())
        {
            cout<<"going left "<<endl;
            cn->left = add(cn->left, data);
        }
        else if (data >= cn->getData())
        {
            cout<<"going right "<<endl;
            cn->right = add(cn->right, data);
        }
        return cn;
    };
    void preOrder(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->getData() << " ";
        cout<<"going left\n";
        preOrder(root->left);
        cout<<"going right\n";
        preOrder(root->right);
        cout<<"returned from right\n";
    }
    void inOrder(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout<<"going left\n";
        inOrder(root->left);
        cout<<"returned from left\n";
        cout << root->getData() << " ";
        cout<<"going right\n";
        inOrder(root->right);
        cout<<"returned from right\n";
    }
    void postOrder(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout<<"going left\n";
        postOrder(root->left);
        cout<<"going right\n";
        postOrder(root->right);
        cout<<"Returned from right\n";
        cout << root->getData() << " ";
    }
    void buildTreeFromArray()
    {
        string inp;
        cout << "Enter values (separated with commas): ";
        cin.ignore();
        getline(cin, inp);

        istringstream iss(inp);
        vector<int> values;
        int value;
        while (iss >> value)
        {
            values.push_back(value);
            if (iss.peek() == ',')
                iss.ignore();
        }
        for (int i = 0; i < values.size(); i++)
        {
            addNode(values[i]);
        }
    }
    void printTree(Node<T> *root)
    {
        int indent=33;
        for (int j = indent+2; j >0; j--)
        {
            for (int i = 0; i < indent*2; i++)
            {
                cout<<"-";
            }
            if (j%2==0)
            {
                cout<<"--/";
            }
            else
            {
                cout<<"(";
                cout<<j;
                cout<<")";
            }
            indent--;
            cout<<endl;
        }
    }
    void printTotalNodes()
    {
        cout<<"Total Nodes are :"<<totalNodes<<endl;
    }
};
int main()
{
    BinarySearchTree<int> bst;
    int choice;
    do
    {
        system("cls");
        cout << "\n1.Add node" << endl;
        cout << "2.remove node" << endl;
        cout << "3.Traverse Preorder" << endl;
        cout << "4.Traverse Inorder" << endl;
        cout << "5.Traverse Postorder" << endl;
        cout << "6.Build Tree from Array" << endl;
        cout << "7.Print Tree" << endl;
        cout << "8.Print Total nodes" << endl;
        cout << "0.Exit" << endl;
        cout << "Enter ur choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bst.addNode();
            break;
        case 3:
            bst.preOrder(bst.root);
            break;
        case 4:
            bst.inOrder(bst.root);
            break;
        case 5:
            bst.postOrder(bst.root);
            break;
        case 6:
            bst.buildTreeFromArray();
            break;
        case 7:
            bst.printTree(bst.root);
            break;
        case 8:
            bst.printTotalNodes();
            break;
        default:
            cout << "Invalid choice!!\n";
            break;
        }
        cout << "\nPress Any key to continue....";
        getch();

    } while (choice != 0);

    //inserted values:100,500,20,10,30
    //pre-order  : 100,20,10,30,500
    //in-order   : 10,20,30,100,500
    //post-order : 10,30,20,500,100

    return 0;
}