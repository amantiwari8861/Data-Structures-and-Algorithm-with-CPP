#include <iostream>
#include <conio.h>
#include <windows.h>
#include <sstream>
#include <vector>
#include<iomanip>
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
        root = NULL;
        totalNodes = 0;
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
        if (root == NULL)
        {
            root = add(root, getData());
            totalNodes++;
        }
        else
        {
            add(root, getData());
            totalNodes++;
        }
    }
    void addNode(T data)
    {
        if (root == NULL)
        {
            root = add(root, data);
            totalNodes++;
        }
        else
        {
            add(root, data);
            totalNodes++;
        }
    }
    Node<T> *add(Node<T> *root, T data)
    {
        if (root == NULL)
        {
            return new Node<T>(data);
        }
        if (data < root->getData())
        {
            root->left = add(root->left, data);
        }
        else if (data >= root->getData())
        {
            root->right = add(root->right, data);
        }
        return root;
    };
    void preOrder(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        cout << root->getData() << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    void inOrder(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        inOrder(root->left);
        cout << root->getData() << " ";
        inOrder(root->right);
    }
    void postOrder(Node<T> *root)
    {
        if (!root)
        {
            return;
        }
        postOrder(root->left);
        postOrder(root->right);
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
    void printTotalNodes()
    {
        cout << "Total Nodes are :" << totalNodes << endl;
    }
    void printTree(Node<T> *root, int depth)
    {
        if (root == nullptr)
            return;

        const int INDENT = 5;
        printTree(root->right, depth + 1);
        cout << setw(INDENT * depth) << "" << root->getData() << endl;
        printTree(root->left, depth + 1);
    }

    void printTree()
    {
        printTree(root, 0);
    }
};
int main()
{
    BinarySearchTree<int> bst;
    int choice;
    char status[2];
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
            bst.printTree();
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

    return 0;
}