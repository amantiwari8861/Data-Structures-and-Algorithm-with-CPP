#include <iostream>

using namespace std;


class Node
{
   public:
	   int data;
	   Node *next;
	   Node(int d, Node *n=NULL): data(d),next(n){} /* Creates node */
};
class LinkedQueues
{
	Node *FRONT,*REAR;
    public:
	LinkedQueues();
	void insert(int element);
	void remove();
	void display();
};
LinkedQueues :: LinkedQueues()
{
	 /* Set FRONT and REAR to NULL as the queue is initially empty. */
	FRONT=REAR=NULL;
}
void LinkedQueues :: insert(int element) /* Inserts node in the queue */
{
	Node *newnode;
    newnode = new Node(element,NULL);
    if (FRONT == NULL)
      {
        /* If the queue is empty, then the new node will act as both FRONT and REAR. */
         FRONT = newnode;
         REAR = newnode;
      }
    else
     {
        /* If the queue is NOT empty, then REAR points to the new node.
           The new node now becomes REAR. */
        REAR->next = newnode;
        REAR = newnode;
     }
          cout<<"\nNumber "<<element<<" inserted into the queue "<<endl;
}

void LinkedQueues :: remove() /* deletes node from the queue */
{
	if (FRONT == NULL) /* Check if the queue is empty */
     {
       cout<<"Queue is empty\n";
       return;
     }
    else
     {
       cout<<"\nThe element deleted from the queue is: "<< FRONT->data<<endl;
       FRONT = FRONT->next; /* the next node of FRONT will now become FRONT */
     }
}

void LinkedQueues :: display()
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
	LinkedQueues q;
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
