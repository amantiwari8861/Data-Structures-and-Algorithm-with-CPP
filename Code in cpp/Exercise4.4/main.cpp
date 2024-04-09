#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;


class Node
{
   /*Node class represents the node of doubly linked list. It consists of the
   information part and links to its succeeding and preceeding nodes
   in terms of next and previous nodes.*/
   public:
   int rollNumber;
   char name[20];
   Node * next;/*points to the succeeding node*/
   Node *prev;/*points to the preceeding node*/
};

class DoubleLinkedList
{

  Node *START;
  public:
  DoubleLinkedList();
  bool Search(int rollNo, Node **previous, Node **current);
  bool listEmpty();
  void addNode();
  bool delNode(int rollNo);
  void traverse();
  void revtraverse();
};

DoubleLinkedList :: DoubleLinkedList()
{
   START=NULL;
}
void DoubleLinkedList :: addNode()/*Adds a new node*/
{
   Node *newnode=new Node;
   int rollNo;
   char nm[20];
   cout<<"\nEnter the roll number of the student: ";
   cin>>rollNo;
   cout<<"\nEnter the name of the student: ";
   cin>>nm;
   newnode->rollNumber=rollNo;
   strcpy(newnode->name,nm);
   if(START == NULL || rollNo <= START->rollNumber)/*Checks if the list is empty*/
   {
	if((START != NULL) && ( rollNo == START->rollNumber))
	{
		cout<<"\nDuplicate roll numbers not allowed\n";
		return;
	}
	newnode->next=START;
	if(START !=NULL)
		START->prev=newnode;
	newnode->prev=NULL;
	START=newnode;
	return;
   }
   Node *previous, *current;
   for(previous=current=START;current!=NULL && rollNo >= current->rollNumber;previous=current,current=current->next)
   {
	   if(rollNo == current->rollNumber)
	   {
			cout<<"\nDuplicate roll numbers not allowed\n";
			return;
	   }

   }
   /*On the execution of the above for loop, prev and current will point to those nodes
   between which the new node is to be inserted.*/
   newnode->next=current;
   newnode->prev=previous;
   if (current != NULL)
        current->prev=newnode;
   previous->next=newnode;
}

bool DoubleLinkedList :: Search(int rollNo, Node **previous, Node **current)/*Checks wheteher the specified node is present*/
{

 for(*previous=*current=START;*current !=NULL && rollNo != (*current)->rollNumber;*previous=*current,*current=(*current)->next){}
  return(*current!=NULL);
}

bool DoubleLinkedList :: listEmpty()
{
	if (START == NULL)
                return true;
            else
                return false;
}
bool DoubleLinkedList :: delNode(int rollNo)/*Deletes the specified node*/
{
  Node *previous, *current;
  if(Search(rollNo, &previous, &current)==false)
  return false;
  if(current==START)/*If the first node is to be deleted*/
  {

    START=START->next;
	if(START !=NULL)
		START->prev=NULL;
    delete current;
    return true;
  }

  previous->next=current->next;
  if (current->next != NULL) /* If the node to be deleted is not the last node of the list */
  {
    current->next->prev=previous;
  }
  delete current;
  return true;
}

void DoubleLinkedList :: traverse()/*Traverses the list*/
{
   if(listEmpty())
	cout<<"\nList is empty.\n";
   else
   {
   cout<<"\nRecords in the ascending order of roll numbers are:\n"<<endl;
    Node * currentNode;
    for(currentNode=START;currentNode!=NULL;currentNode=currentNode->next)
    {
        cout<<currentNode->rollNumber<<"   "<<currentNode->name<<"\n";
    }
   }
}

void DoubleLinkedList :: revtraverse()/*traverses the list in the reverse direction*/
{

  if(listEmpty())
	  cout<<"\nList is empty.\n";
  else
  {
   cout<<"\nRecords in the descending order of roll numbers are:\n"<<endl;
    Node * currentNode;
    for(currentNode=START;currentNode->next!=NULL;currentNode=currentNode->next)
    {}
   while(currentNode!=NULL)
   {
      cout<<currentNode->rollNumber<<"   "<<currentNode->name<<"\n";
      currentNode=currentNode->prev;
   }
  }
}

int main()
{
   DoubleLinkedList obj;
   int rollNo;
   char ch;
   while(1)
   {
     cout<<endl<<"Menu";
	 cout<<endl<<"1. Add a record to the list"<<endl;
     cout<<"2. Delete a record from the list"<<endl;
     cout<<"3. View all records in the ascending order of roll numbers"<<endl;
	 cout<<"4. View all records in the descending order of roll numbers"<<endl;
     cout<<"5. Search for a record in the list"<<endl;
     cout<<"6. Exit"<<endl;
	 cout<<"\nEnter your choice (1-6): ";
     cin>>ch;
     switch(ch)
     {
        case '1':
	        {
				obj.addNode();
			}
			break;
		case '2':
		{
		    if(obj.listEmpty())
			{
				cout<<endl<<"List is empty"<<endl;
				break;
			}
			cout<<"\nEnter the roll number of the student whose record is to be deleted: ";
		    cin>>rollNo;
		    if(obj.delNode(rollNo)==false)
		    cout<<"\nRecord not found"<<endl;
			else
				cout<<endl<<"Record with roll number "<<rollNo<<" deleted \n"<<endl;
		}
		break;
	case '3':
		{
		   obj.traverse();
		}
		break;

	case '4':
		{
		    obj.revtraverse();
		}
		break;
        case '5':
		{
		   if(obj.listEmpty()==true)
		   {
			   cout<<"\nList is empty\n";
			   break;
		   }
		   Node *prev,*curr;
		   cout<<"\nEnter the roll number of the student whose record you want to search: ";
		   cin>>rollNo;
		   if(obj.Search(rollNo, &prev, &curr)==false)
   		   cout<<"\nRecord not found"<<endl;
		   else
		   {
		      cout<<"\nRecord found"<<endl;
			  cout<<"\nRoll number: "<<curr->rollNumber;
			  cout<<"\n\nName: "<<curr->name;
			  cout<<"\n";
		}
		break;
	case '6':
		{
			exit(0);
		}
		break;
	default:
		{
			cout<<"\nInvalid option\n";
		}
		break;
     }
	 }
	 }
	 return(0);
}
