#include <iostream>
using namespace std;

/* Class to represent a node of the stack */

class Node
{
	public:
		int info; // Variable to store data
       		Node *next;  // Variable to store address of next node in the stack */

};

/* Class to represent a stack */

class Stack
{

	private:
		Node *top; // Refers to the top of the stack

	public:
		Stack() //Initializes stack
		{
			top = NULL;
		}

		int empty()// Checks whether the stack is empty
		{
			if (top == NULL)
				return(true);
			else
				return(false);
		}

		void push( int passed_value) /* Inserting an element in the stack*/
		{
			Node *temp; // Refers to new node

				temp = new Node();/* Allocating memory to the new node*/

				temp->info = passed_value; ;/* Storing data into the new node */

				temp->next = top;
/* Make next field of the new node point to the top of the stack*/
				top = temp;/*Make top point to the new node */

			cout << endl << passed_value << " pushed." << endl;
		}


		int pop()// Pops an element from the stack
		{
			Node *tmp;
			tmp = top; /* Make tmp point the first node of the
              list */

			top = top->next; /* Make top point to the next element in the stack */
			int x = tmp->info;/* Storing popped element in the x variable*/
			delete(tmp); // Deallocating memory
			return(x);// Returning popped element
		}

		void display()
		{
			if (top == NULL) // If stack is empty
				cout << endl << "Stack Empty." << endl;
			else
			{

				Node *currentNode;

				cout << endl << "The contents of the stack are:" << endl;
// Traverse the stack from the beginning till end
				for (currentNode = top; currentNode!=NULL;
                         currentNode = currentNode->next)
				{
					cout<<currentNode->info<<"\n";
				}
			}

		}
};


int main()
{
	int choice,x,num;
	Stack mystack;

	do
	{
		cout<<"\n***STACK MENU***\n\n";
		cout<<"1. PUSH\n";
		cout<<"2. POP\n";
		cout<<"3. Display\n";
		cout<<"4. Exit\n";

		cout<<"\nEnter your choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"\nEnter a number: ";
				cin>>num;

				mystack.push(num);
				break;

			case 2:
				if (mystack.empty())
				{
					cout << endl << "Stack Empty." <<
                                endl;
					break;
				}

				x = mystack.pop();
				cout << endl << "The popped value is " << x
                         << endl;
				break;

			case 3:
				mystack.display();
				break;

			case 4:
				break;

			default:
				cout<<"\nInvalid choice. Try again\n";

		}
	}while (choice != 4);
}
