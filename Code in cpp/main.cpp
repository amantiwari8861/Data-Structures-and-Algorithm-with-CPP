#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Node
{
/* Create a class to represent a node in the linked list.Each node consists of the information part and a link to the next node. */
   public:
   int rollNumber;
   char name[20];
   Node * next;
};
/* Create a class to represent the linked list. To represent a linked list, you only need a reference to the first node of the list. */
class List
{
  Node *START; //Reference to the first node of the list.
  public:
  List();
  void addNode();
  bool Search(int rollNo, Node **current, Node **previous);
  bool listEmpty();
  bool delNode(int element);
  void traverse();
};
List :: List()
{
   START=NULL;
}
void List :: addNode() /* Adds a Node in the list */
{
  int rollNo;
  char nm[20];
  cout<<"\nEnter the roll number of the student: ";
  cin>>rollNo;
  cout<<"\nEnter the name of the student: ";
  cin>>nm;
  Node *newnode = new Node;
  newnode->rollNumber = rollNo;
  strcpy(newnode->name,nm);
 /* Locate the position of the new node in the list */
   Node *previous, *current;
   previous = NULL;
   current = START;
/* Scan through the linked list until you find a node whose roll number is greater than the roll number of the new node.*/
   while ((current!=NULL) && (rollNo>=current->rollNumber))
   {
   if (rollNo == current->rollNumber)
   {
    cout<<"\nDuplicate roll numbers not allowed\n";
	return;
   }
	   previous=current;
	   current=current->next;
   }
/* Once the preceding for loop is executed, previous and current are positioned in such a manner that the position for the new node is in between them. */
   newnode->next=current;
   if(previous==NULL)
       START=newnode;
   else
      previous->next=newnode;
}
bool List :: listEmpty()/* Checks whether the list is empty */
{
	if (START == NULL)
                return true;
            else
                return false;
}
bool List :: delNode(int rollNo) /* Deletes the specified node from the list */
{
  Node *current, *previous;
  if(Search(rollNo,&previous, &current)==false)
	return false;
  previous->next = current->next;
  if (current == START)
     START = START->next;
  delete current;
  return true;
}

bool List :: Search(int rollNo, Node **previous, Node **current)
/* Checks whether the specified node is present in the list or not */
{
	*previous = START;
	*current = START;
/* Scan the linked list to search for the specified roll number */
 	while ((*current !=NULL) && (rollNo != (*current)->rollNumber))
	{
		*previous = *current;
		*current=(*current)->next;
	}
	return (*current !=NULL);
}

void List :: traverse()/* Displays the contents of the list */

{

   if(listEmpty())
	   cout<<"\nList is empty\n";
   else
   {
   	cout<<endl<<"The records in the list are:"<<endl;
   	Node * currentNode;
  	for(currentNode=START;currentNode!=NULL;currentNode=currentNode->next)
  	{
  	    cout<<currentNode->rollNumber<<"     "<<currentNode->name<<"\n";
    }
	cout<<endl;
   }
}

int main()
{
   List obj;
   int rollNo;
   char ch;
   while(1)
   {
     cout<<endl<<"Menu";
     cout<<endl<<"1. Add a record to the list"<<endl;
     cout<<"2. Delete a record from the list"<<endl;
     cout<<"3. View all the records in the list"<<endl;
     cout<<"4. Search for a record in the list"<<endl;
     cout<<"5. Exit"<<endl;
     cout<<endl<<"Enter your choice (1-5): ";
     cin>>ch;
     switch(ch)
     {
        case '1':
           obj.addNode();
	       break;
	case '2':
	    if(obj.listEmpty())
        {
		cout<<endl<<"List is empty"<<endl;
		break;
		}
		cout<<endl<<"\nEnter the roll number of the student whose record is to be deleted: ";
		cin>>rollNo;
		if(obj.delNode(rollNo)==false)
			cout<<endl<<"Record not found"<<endl;
		else
			cout<<endl<<"Record with roll number "<<rollNo<<" deleted "<<endl;
			break;
	case '3':
		   obj.traverse();
			break;

	case '4':
		    if(obj.listEmpty()==true)
			{
				cout<<"\nList is empty\n";
				break;
			}
			Node *previous,*current;
			cout<<endl<<"Enter the roll number of the student whose record is to be searched: ";
			cin>>rollNo;
			if(obj.Search(rollNo, &previous, &current)==false)
   			cout<<endl<<"Record not found"<<endl;
			else
			{
				cout<<endl<<"Record found"<<endl;
				cout<<"\nRoll number: " << current->
				rollNumber;
				cout<<"\n\nName: " << current->name;
				cout<<"\n";
			}
			break;
	case '5':
				exit(0);
				break;
    default:
			cout<<"Invalid option."<<endl;
	 		break;
     }
   }
return(0);
}
