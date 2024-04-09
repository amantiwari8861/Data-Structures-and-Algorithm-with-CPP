#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;


class Node
{
   //Each node consists of the information part and a lik to the next node.
   public:
   char info[20];
   Node * next;
};

class List
{
  Node *START;
  public:
  List();
  void addNode(char element[20]);
  void sort();
  void traverse();
};

List :: List()
{
   START=NULL;
}
void List :: addNode(char element[20])//Adds a Node in the list
{
   Node *newnode = new Node;
   strcpy(newnode->info,element);
   newnode->next=NULL;
   if(START == NULL)//If the node to be inserted is the first node
   {
	newnode->next=START;
	START=newnode;
	return;
   }
   Node *currentNode;
   for(currentNode=START;currentNode->next!=NULL;currentNode=currentNode->next){}
   currentNode->next=newnode;
}

void List :: traverse()//Traverses the list
{

   if(START==NULL)//Checks whether the list is empty
   {
   cout<<"\nList is empty\n";
   return;
   }
    cout<<"\nList is\n";
    Node *currentNode;
    for(currentNode=START;currentNode!=NULL;currentNode=currentNode->next)
    {
        cout<<currentNode->info<<"     ";
    }
}

void List :: sort()
{
	Node *LAST;
            LAST = NULL;
            Node *ptr1, *ptr2;
            while (START->next != LAST)
            {
                ptr1 = START;
                ptr2 = START->next;
                while (ptr2 != LAST)
                {
                    if(strcmp(ptr1->info,ptr2->info)>0)

                    { char str[20];
                     strcpy(str, ptr1->info);
                     strcpy(ptr1->info, ptr2->info);
                     strcpy(ptr2->info, str);
                    }
                   ptr1 = ptr1->next;
                   ptr2 = ptr2->next;
                }
                LAST = ptr1;
            }
            traverse();
}

int main()
{
   List obj;
   char name[20];
   char ch;
   while(1)
   {
       Point:
	 cout<<"\nMenu.";
	 cout<<endl<<"1. Add element."<<endl;
	 cout<<"2. Sort."<<endl;
     cout<<"3. Traverse."<<endl;
     cout<<"4. EXIT."<<endl;
     cout<<"Enter your choice: ";
     cin>>ch;
     switch(ch)
     {
        case '1':
	        {
		   cout<<"\nEnter a name: ";
		   cin>>name;
		   for(int l=0;l<20; l++)
		   {
                        if (name[l] == '0' || name[l] == '1' || name[l] == '2' || name[l] == '3' || name[l] == '4' || name[l] == '5' || name[l] == '6' || name[l] == '7' || name[l] == '8' || name[l] == '9')
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
		                               obj.addNode(name);
                            cout<<"\nInserted "<<name<<"\n";



		}
		break;

	case '2':
		{
		    obj.sort();
		}
		break;
	case '3':
		{
		   obj.traverse();
		}
		break;

	case '4':
		{
			exit(0);
		}
		break;
		default:
		{
			cout<<"Invalid option."<<endl;
		}
		break;
     }
   }
   return(0);
}









