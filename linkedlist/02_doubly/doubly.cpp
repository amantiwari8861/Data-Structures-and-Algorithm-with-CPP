#include <iostream>
#include <conio.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next; // self-referential pointer
    Node *prev;
    Node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
class doubly
{
public:
    Node *head, *tail;
    int temp;
    doubly()
    {
        head = NULL;
        tail = NULL;
    }
    Node *getNode()
    {
        cout << "enter data:";
        cin >> temp;
        return new Node(temp); // dynamic memory allocation
    }
    void insertAtBegining()
    {
        Node *newNode = getNode();
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            cout << "List is Created!\n";
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            cout << "Added at Begining of List!\n";
        }
    }
    void insertAtLast()
    {
        if (head == NULL)
        {
            insertAtBegining();
        }
        else
        {
            Node *newNode = getNode();
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            cout << "Added at Last of List!\n";
        }
    }
    void insertAtPos()
    {
        int pos;
        cout<<"Enter the position:";
        cin>>pos;

        if (pos<=0)
        {
            cout<<"invalid position!\n";
            return;
        }
        else if (pos==1)
        {
            insertAtBegining();
        }
        else
        {
            Node* newNode=getNode();
            Node* cn=head;
            for(int i=1;(i<=pos && cn!=NULL);i++)
            {
                if(i==pos-1)
                {
                    newNode->prev=cn;
                    if (cn->next!=NULL)
                    {
                        newNode->next=cn->next;
                        cn->next->prev=newNode; 
                        cn->next=newNode;
                    }
                    else
                    {
                        cn->next=newNode;
                        tail=newNode;
                    }
                    cout<<"inserted at position :"<<i+1<<endl;
                }
                cn=cn->next;
            }
        }
    }
    void printLL()
    {
        cout << "The List is :[";
        Node *cn = head;
        while (cn != NULL)
        {
            cout << cn->data;
            if (cn->next != NULL)
            {
                cout << ",";
            }
            cn = cn->next;
        }
        cout << "]\n";
    }
    int countNodes()
    {
        Node *cn = head;
        int count = 0;
        while (cn != NULL)
        {
            cn = cn->next;
            count++;
        }
        return count;
    }
    int search(int num)
    {
        Node *cn = head;
        for (int i = 1; cn != NULL; i++)
        {
            if (cn->data == num)
            {
                return i;
            }
            cn = cn->next;
        }
        return -1;
    }
    void deleteFromBeggining()
    {
        if (head==NULL)
        {
            cout<<"List doesn't Exist!\n";

        }
        else
        {
            Node* temp=head;
            if (temp->next!=NULL)
            {
                head=head->next;
                head->prev=NULL;
            }
            else
            {
                head=NULL;
                tail=NULL;
            }
            delete temp;

            cout<<"Deleted from begining succesfully!!\n";
        }
    }
    void deleteFromlast()
    {
        Node* temp=tail;
        if(head==NULL)
        {
            cout<<"List doesn't Exist!\n";
            return;
        }
        else if (tail->prev==NULL)
        {
            head=NULL;
            tail=NULL;
        }
        else
        {
            tail=tail->prev;
            tail->next=NULL;
        }
        delete temp;
        cout<<"deleted from the last succesfully!!\n";
    }
    void deleteFromPos()
    {

    }
    void printReverse()
    {
        cout << "The List is :[";
        Node *cn = tail;
        while (cn != NULL)
        {
            cout << cn->data;
            if (cn->prev != NULL)
            {
                cout << ",";
            }
            cn = cn->prev;
        }
        cout << "]\n";
    }
};
int main()
{
    int choice;
    doubly ll;
    do
    {
        system("cls");
        cout << " 1. insert at last \n";
        cout << " 2. print list \n";
        cout << " 3. insert at begining \n";
        cout << " 4. insert at position \n";
        cout << " 5. count no. of nodes \n";
        cout << " 6. search in list \n";
        cout << " 7. delete from beggining \n";
        cout << " 8. delete from last \n";
        cout << " 9. delete from pos \n";
        cout << "10. print reversed linked list \n";
        cout << " 0. exit \n";
        cout << "enter ur choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            ll.insertAtLast();
            break;
        case 2:
            ll.printLL();
            break;
        case 3:
            ll.insertAtBegining();
            break;
        case 4:
            ll.insertAtPos();
            break;
        case 5:
            cout << "There are total " << ll.countNodes() << " Nodes\n";
            break;
        case 6:
            int temp, pos;
            cout << "enter element to be searched:";
            cin >> temp;
            pos = ll.search(temp);
            if (pos != -1)
            {
                cout << "found at position " << pos << endl;
            }
            else
            {
                cout << "not found in list\n";
            }
            break;
        case 7:
            ll.deleteFromBeggining();
            break;
        case 8:
            ll.deleteFromlast();
            break;
        case 9:
            ll.deleteFromPos();
            break;
        case 10:
            ll.printReverse();
            break;
        case 0:
            cout << "Thank you visit again.\n";
            exit(0);
            break;
        default:
            cout << "invalid choice!\n";
            break;
        }
        cout << "Press any key to continue.....";
        getch();
    } while (1);

    return 0;
}