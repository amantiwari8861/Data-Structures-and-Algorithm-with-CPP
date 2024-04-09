#include <iostream>

using namespace std;

#include <cstring>
#include <cstdlib>

class Node
{
   public:
	   int data;
	   Node *next;
	   Node(int d, Node *n=NULL): data(d),next(n){} /* Creates node */
};

class Node1
{
   public:
	   int data;
	   Node1 *next;

};

class Stack
{

	private:
		Node1 *top;

	public:
		Stack()
		{
			top = NULL;
		}

		void push( int passed_value)
		{
			Node1 *temp;

			if ( top == NULL )
			{
				top = new Node1;
				top->data = passed_value;
				top->next = NULL;
			}
			else
			{
				temp = new Node1();
				temp->data = passed_value;
				temp->next = top;
				top = temp;
			}

		}


		int pop()
		{
			Node1 *tmp;
			tmp = top; /* Make tmp point the first node of the
              list */

			top = top->next;
			int x = tmp->data;
			delete(tmp);
			return(x);
		}
};

int main()
{
char stackChar;
char stringChar;
char str[20];

int ispalindrome=1;



Stack mystack;



    cout << "\nEnter a string: ";
     cin.getline(str,20);

         int len;

        for (len=0; str[len]!= '\0'; len++);

        for (int i = 0; i < len; i++)
        {

             mystack.push(i);

        }



 for (len=0; str[len]!='\0'; len++)
 {
     stackChar=mystack.pop();
     stackChar=tolower(stackChar);
      stringChar=tolower(str[len]);

if (stackChar==stringChar)
{

ispalindrome = 0;
break;
}
 }


if(ispalindrome==1)
{
    cout<<"\nString is a palindrome";
}

else
{
        cout<<"\nString is not a palindrome";
}

}


