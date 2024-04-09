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
            Stack s;
            char str [20];
             cout << "\nEnter a string: ";
        cin >> str;
         int len;

        for (len=0; str[len]!= '\0'; len++);

        for (int i = 0; i < len; i++)
            s.push(str[i]);

        cout << "\nThe reversed string is: ";
        while (!s.empty())
        {
            char ch = s.pop();
            cout << ch;
        }
        cout << "\n";
        return 0;
        }





