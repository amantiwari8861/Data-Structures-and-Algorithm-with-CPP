#include<iostream>
#include<conio.h>
#define MAX_SIZE 5
using namespace std;

struct Node
{
    int data;
    struct Node* next;
}*head=NULL,*tail=NULL;
int top=-1;

bool isEmpty()
{
    if(head==NULL)
    {
        cout<<"Stack is Empty !"<<endl;
        return true;
    }
    else
        return false;
}
bool isFull()
{
    if(top==MAX_SIZE-1)
    {
        cout<<"Stack is Full "<<endl;
        return true;
    }
    else
        return false;
}
void push(){

    if(isFull())
        return;
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    cout<<"enter data :";
    cin>>newNode->data;
    newNode->next=NULL;

    if (head==NULL)
    {
        head=newNode;
        tail=newNode;
        cout<<"the list is created! "<<endl; 
    }
    else
    {
        newNode->next=head;
        head=newNode;
        cout<<head->data<<" added into stack "<<endl;
    }    
    top++;
}
void pop()
{
    if (isEmpty())
        return;
    
    struct Node* temp=head;
    head=head->next;
    cout<<temp->data<<" popped !"<<endl;
    free(temp);
    top--;
}
void peek(){
    
    cout<<head->data<<" is on the top"<<endl;
}

int main()
{
    int choice;
    do
    {
        system("cls");
        cout<<"1.push in stack"<<endl;
        cout<<"2.pop from stack"<<endl;
        cout<<"3.peek in stack"<<endl;
        cout<<"4.is stack empty"<<endl;
        cout<<"5.is stack full"<<endl;
        cout<<"6.exit"<<endl;
        cout<<"Enter the choice :";
        cin>>choice;

        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            if(!isEmpty())
                cout<<"Stack is not Empty!"<<endl;
            break;
        case 5:
            if(!isFull())
                cout<<"Stack is not Full! "<<endl;
            break;
        case 6:
            exit(0);
            break;
        default:cout<<"invalid choice! "<<endl;
            break;
        }
        cout<<"press any key to continue...";
        getch();
    } while (1);
    
    return 0;
}