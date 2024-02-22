#include<iostream>
#include<conio.h>
using namespace std;
class Node 
{
    public:
    int data;
    Node* next;//self-referential pointer
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
class singly
{
    public:
    Node *head,*tail;
    int temp;
    singly()
    {
        head=NULL;
    }
    Node* getNode()
    {
        cout<<"enter data:";
        cin>>temp;
        return new Node(temp);//dynamic memory allocation
    }
    void insertAtLast()
    {
        Node *newnode=getNode();
        if (head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=tail->next;
        }
    }
    void insertAtBegining()
    {
        if(head!=NULL)
        {
            Node *newnode=getNode();
            newnode->next=head;
            head=newnode;
        }
        else
        {
            insertAtLast();
        }
    }
    void insertAtPos()
    {
        int pos;
        cout<<"enter position:";
        cin>>pos;

        if (pos<=0)
        {
            cout<<"invalid position\n";
        }
        else if (pos==1)
        {
            insertAtBegining();
        }
        else
        {
            Node *cn=head;
            Node *newnode=getNode();
            for (int i = 1; i <= pos; i++)
            {
                if(i==pos-1)
                {
                    newnode->next=cn->next;
                    cn->next=newnode;
                    cout<<"inserted at "<<i+1<<" position succesfully!!\n";
                }
                else
                {
                    cn=cn->next;
                }
            }
        }
    }
    void printLL()
    {
        cout<<"The List is :[";
        Node *cn=head;
        while (cn!=NULL)
        {
            cout<<cn->data;
            if (cn->next!=NULL)
            {
                cout<<",";
            }            
            cn=cn->next;
        }
        cout<<"]\n";
    }
    int countNodes()
    {
        Node* cn=head;
        int count=0;
        while (cn!=NULL)
        {
            cn=cn->next;
            count++;
        }
        return count;        
    }
    int search(int num)
    {
        Node* cn=head;
        for (int i=1;cn!=NULL;i++)
        {
            if (cn->data==num)
            {
                return i;
            }
            cn=cn->next;
        }
        return -1;
    }
    void deleteFromBeggining()
    {
        if (head==NULL)// 
        {
            cout<<"List doesn't exist!!\n";
            return;
        }
        else if (head->next==NULL)
        {
            Node* cn=head;
            head=NULL;
            delete cn;
        }
        else
        {
            Node* cn=head;
            head=head->next;
            delete cn;
        }
        cout<<"deleted from starting succesfully!!\n";
    }
    void deleteFromlast()
    {
        Node* cn=head;
        while (cn!=NULL)
        {
            if(cn->next->next==NULL)
            {
                delete cn->next;
                cn->next=NULL;
                tail=cn;
                cout<<"Last Node Deleted !\n";
                break;
            }
            cn=cn->next;
        }
    }
    void deleteFromPos()
    {
        int pos;
        cout<<"enter the position:";
        cin>>pos;

        if (pos==1)
        {
            deleteFromBeggining();
        }
        else
        { 
            Node* cn=head;
            Node* delNode;
            for (int i = 1; (i <= pos || cn!=NULL) ; i++)
            {
                if (i==pos-1)
                {
                    delNode=cn->next;
                    cn->next=cn->next->next;
                    if(delNode->next==NULL)
                    {
                        cout<<"deleting end node!\n";
                        tail=cn;
                    }
                    delete delNode;
                    cout<<i+1<<"th element deleted!\n";
                    break;
                }
                cn=cn->next;
            }            
        }
    }
    void printLLUsingRec(Node* cn)
    {        
        if (cn!=NULL) //Base condition
        {
            printLLUsingRec(cn->next);
            cout<<cn->data;
            cout<<",";
        }
    }
};
int main()
{
    int choice;
    singly ll;
    do
    {
        system("cls");
        cout<<" 1. insert at last \n";
        cout<<" 2. print list \n";
        cout<<" 3. insert at begining \n";
        cout<<" 4. insert at position \n";
        cout<<" 5. count no. of nodes \n";
        cout<<" 6. search in list \n";
        cout<<" 7. delete from beggining \n";
        cout<<" 8. delete from last \n";
        cout<<" 9. delete from pos \n";
        cout<<"10. print reversed linked list \n";
        cout<<"0. exit \n";
        cout<<"enter ur choice :";
        cin>>choice;
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
            cout<<"There are total "<<ll.countNodes()<<" Nodes\n";
            break;
        case 6:
            int temp,pos;
            cout<<"enter element to be searched:";
            cin>>temp;
            pos=ll.search(temp);
            if (pos!=-1)
            {
                cout<<"found at position "<<pos<<endl;
            }
            else
            {
                cout<<"not found in list\n";
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
            cout<<"The List is :[";
            ll.printLLUsingRec(ll.head);
            cout<<"\b]\n";
            break;
        case 0:
            cout<<"Thank you visit again.";
            exit(0);
            break;
        default:cout<<"invalid choice!";
            break;
        }
        cout<<"Press any key to continue.....";
        getch();
    } while (1);
    
    return 0;
}