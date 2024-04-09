#include <iostream>
using namespace std;

/* Class to represent in a node in the queue */
class Node
{
   public:
	   int data;
	   Node *next;
	   Node(int d, Node *n=NULL): data(d),next(n){} /* Creates node */
};
/* Class to represent a queue */
class LinkedQueue
{
	Node *FRONT,*REAR;
    public:
	LinkedQueue();
	void insert(int element);
	void remove();
	void display();
};
LinkedQueue :: LinkedQueue()
{
	 /* Set FRONT and REAR to NULL as the queue is initially empty. */
	FRONT=REAR=NULL;
}
void LinkedQueue :: insert(int element) /* Inserts node in the queue */
{
	Node *newnode;
    newnode = new Node(element,NULL);
    if (FRONT == NULL)
      {
        /* If the queue is empty, then both FRONT and REAR should point to the new node. */
         FRONT = newnode;
         REAR = newnode;
      }
    else
     {
        /* If the queue is NOT empty, then REAR points to the last node. REAR should now point to the new node.  */
        REAR->next = newnode;
        REAR = newnode;
     }
          cout<<"\nNumber "<<element<<" inserted into the queue "<<endl;
}

void LinkedQueue :: remove() /* deletes node from the queue */
{
	if (FRONT == NULL) /* Check if the queue is empty */
     {
       cout<<"Queue is empty\n";
       return;
     }
    else
     {
       cout<<"\nThe element deleted from the queue is: "<<
FRONT->data<<endl;
       FRONT = FRONT->next; /* FRONT will now point to the next node in the queue. */
     }
}

void LinkedQueue :: display()
{
	Node *tmp;
 	if (FRONT == NULL) /* Checks if the queue is empty */
      {
        cout<<"Queue is empty\n";
        return;
      }
    else
      {
		  cout<<"\nThe queue is.....\n\n";
		  for (tmp = FRONT; tmp != NULL; tmp = tmp->next) /* traverse the queue through tmp node */
          {
            cout<<tmp->data<<"   ";
          }
           cout<<endl;
      }
}

int main()
{
	LinkedQueue q;
	char ch;
	int num;
	do
	{
		cout<<"\nMenu";
		cout<<"\n1. Implement insert operation in the queue"<<endl;
        cout<<"2. Implement delete operation on the queue"<<endl;
        cout<<"3. Display values"<<endl;
        cout<<"4. Exit"<<endl;
		cout<<"\nEnter your choice (1-4): ";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
		  case '1':
			 {
				cout<<"Enter a number: ";
                cin>>num;
                q.insert(num);
			 }
			 break;
		  case '2':
			  {
				q.remove();
			  }
			  break;
		  case '3':
			  {
				  q.display();
			  }
			  break;
		  case '4':

			  break;
		  default:
			  {
				  cout<<"Invalid option."<<endl;
			  }
			  break;
		}
	}
	while(ch!='4');
}
