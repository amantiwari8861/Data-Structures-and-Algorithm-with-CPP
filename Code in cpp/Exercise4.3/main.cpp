#include <iostream>
#include <cstring>

using namespace std;


class Node
{
   //Each node consists of the information part and a lik to the next node.
   public:
   int rollNumber;
   char name[20];
   Node * next;
};

class List
{
  Node *START;
  public:
  List();
  void addNode(int, char[]);
  bool listEmpty();
  void traverse();
  void reverse();
};

List :: List()
{
   START=NULL;
}
void List :: addNode(int rollNo, char nm[])//Adds a Node in the list
{

	Node *newnode=new Node;
	newnode->rollNumber=rollNo;
	strcpy(newnode->name,nm);

   if(START == NULL || rollNo <= START->rollNumber)//If the node to be inserted is the first node
   {
	   if((START !=NULL) && (rollNo == START->rollNumber))
	   {
		   cout<<"\nDuplicates not allowed\n";
		   return;
	   }
	newnode->next=START;
	START=newnode;
	return;
   }

   Node *previous, *current;
   for(previous=current=START;current!=NULL && rollNo >= current->rollNumber;previous=current,current=current->next)
   {
		if(rollNo == current->rollNumber)
		{
			cout<<"\nDuplicates not allowed\n";
		   return;
		}
   }

   //Once the above for loop is executed, previous and current are positioned in such
   //a manner that the position for the new node is in between them.
   newnode->next=current;
   previous->next=newnode;
}

bool List :: listEmpty()
{
	if (START == NULL)
                return true;
            else
                return false;
}
void List :: traverse()//Traverses the list
{

    Node * currentNode;
    for(currentNode=START;currentNode!=NULL;currentNode=currentNode->next)
    {
        cout<<currentNode->rollNumber<<"     "<<currentNode->name<<"\n";
    }
	cout<<endl;

}
void List :: reverse()
{
			if(listEmpty())
			{
				cout<<"\nList is empty.\n";
			}
			else
			{
			Node *ptr1, *ptr2, *ptr3;
            if (START->next == NULL)
                return;
            ptr1 = START;
            ptr2 = ptr1->next;
            ptr3 = ptr2->next;

            ptr1->next = NULL;
            ptr2->next = ptr1;
            while (ptr3 != NULL)
            {
                ptr1 = ptr2;
                ptr2 = ptr3;
                ptr3 = ptr3->next;
                ptr2->next = ptr1;
            }
            START = ptr2;
        }
}

int main()
{
   List obj;
   int num;

   char ch;
   char pro='y';
   int k=0;
   Point:
     while (k == 0)

   {

      int rollNo;
      char nm[20];


                  cout<<"\nEnter the roll number of a student(in figures): ";
      cin>>rollNo;



     cout<<"\nEnter the name of the student: ";
      cin>>nm;

		   for(int l=0;l<20; l++)
		   {
        if (nm[l] == '0' || nm[l] == '1' || nm[l] == '2' || nm[l] == '3' || nm[l] == '4' || nm[l] == '5' || nm[1] == '6' || nm[1] == '7' || nm[1] == '8' || nm[1] == '9')
                        {
                            cout<<"A name cannot begin with an interger value";
                            goto Point;
                        }
                        else
                        {
                            goto con;
                        }
		   }


            con:


      obj.addNode(rollNo, nm);

      cout << "\nDo you wish to continue (y/n): ";
      cin >> pro;
      if((pro=='n')||(pro=='N'))
      break;


   }


   cout << "\nThe list of records is\n";
   obj.traverse();

   obj.reverse();
   cout << "\nThe reversed list is:\n";
   obj.traverse();


return(0);
}








