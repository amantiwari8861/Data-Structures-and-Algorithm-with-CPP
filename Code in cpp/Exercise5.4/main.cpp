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
			{


				return(false);
			}
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


class Expression
{
    char exp[50];


    public:

    void read()
    {
        cout << "\nEnter an expression: ";
        cin >> exp;
    }

    int openingParenthesis(char entry)
    {
        if ((entry == '(') || (entry == '{') || (entry == '['))
            return (1);
        else
            return (0);
    }

    int closingParenthesis(char entry)
    {
        if ((entry == ')') || (entry == '}') || (entry == ']'))
            return (1);
        else
            return (0);
    }

    int match(char entry1, char entry2)
    {
        if ((entry1 == '(') && (entry2 == ')'))
            return (1);
        else if ((entry1 == '{') && (entry2 == '}'))
            return (1);
        else if ((entry1 == '[') && (entry2 == ']'))
            return (1);
        else
            return (0);

    }

    int checkParenthesis()
    {
        Stack s;
        char entry;

        //Determine the length of the expression
	int len;

        for (len=0; exp[len]!= '\0'; len++);

        for (int i = 0; i < len; i++)
        {
            if (openingParenthesis(exp[i]))
                s.push(exp[i]);
            else if (closingParenthesis(exp[i]))
            {
                if (s.empty())
                    return (1);
                entry = s.pop();

                if (!match(entry, exp[i]))
                    return (2);
            }
        }

        if (!s.empty())
            return (3);
        else
            return (0);

    }
};

int main()
{
    char choice = 'y';
    Expression expr;

    while (choice == 'y')
    {
        expr.read();
        int flag = expr.checkParenthesis();
        if (flag == 1)
            cout<<"\nNumber of closing parentheses is more than the number of opening parentheses.";
        else if (flag == 2)
            cout << "\nA closing parenthesis does not match its corresponding opening parenthesis.";
        else if (flag == 3)
            cout << "\nNumber of opening parentheses is more than the number of closing parentheses.";
            else
            cout<<"\nThe entered expression contains the correct number of parenthesis.";


        cout << "\n\nDo you want to continue? (y/n):";
        cin >> choice;
    }
}
