#include <iostream>

using namespace std;


class Node
{
	public:
		int info;
		Node *next;
};

class Stack
{

	private:
		Node *top;

	public:
		Stack()
		{
			top = NULL;
		}

		int empty()
		{
			if (top == NULL)
				return(true);
			else
				return(false);
		}

		void push( int passed_value)
		{
			Node *temp;

			if ( top == NULL )
			{
				top = new Node;
				top->info = passed_value;
				top->next = NULL;
			}
			else
			{
				temp = new Node();
				temp->info = passed_value;
				temp->next = top;
				top = temp;
			}

		}



		int pop()
		{
			Node *tmp;
			tmp = top; /* Make tmp point the first node of the
              list */

			top = top->next;
			int x = tmp->info;
			delete(tmp);
			return(x);
		}


		};



		int main()
{
	int m,n,p;
	Stack mystack;


cout<<"Enter a number to convert: ";
cin>>m;
if(m==0)
{
   cout<<"Binary equivalent: "<<0;
}
else{

while(m)
{
n = m % 2;
mystack.push(n);
m = m / 2;
}
cout<<"Binary equivalent: ";
while(!mystack.empty())
{
p = mystack.pop();
cout<<p;
}
cout<<endl;
}
}



