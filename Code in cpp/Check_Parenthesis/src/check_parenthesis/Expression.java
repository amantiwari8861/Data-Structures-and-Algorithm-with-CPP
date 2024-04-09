package check_parenthesis;

import java.util.Scanner;

public  class Expression
    {
        char[] exp = new char[50];
        char[] postfix = new char[50];

        public void read()
        {
            System.out.print("\nEnter an expression: ");
	    exp = new Scanner(System.in).nextLine().toCharArray();
        }
    public int checkParenthesis()
        {
			Stacks s = new Stacks();
			char entry;

			for (int i = 0; i < exp.length; i++)
			{
				if (openingParenthesis(exp[i]))
				{
					s.push(exp[i]);
				}
				else if (closingParenthesis(exp[i]))
				{
					if (s.empty())
					{
						return (1);
					}
					entry = s.pop();

					if (!match(entry, exp[i]))
					{
						return (2);
					}
				}
			}

			if (!s.empty())
			{
				return (3);
			}
			else
			{
				return (0);
			}

}

	public	static void main(String[] args)
		{
			Expression exp = new Expression();
			char choice = 'y';
			while (choice == 'y')
			{
				exp.read();
				int flag = exp.checkParenthesis();
				if (flag == 1)
					System.out.println("\nNumber of closing parentheses is more than the number of opening parentheses.");
				else if (flag == 2)
					System.out.println("\nA closing parenthesis does not match its corresponding opening parenthesis.");
				else if (flag == 3)
                        		System.out.println("\nNumber of opening parentheses is more than the number of closing parentheses.");
				else
					System.out.println("\nThe entered expression contains the correct number of parenthesis.");
			
				System.out.print("\nDo you want to continue? (y/n): ");
				choice = new Scanner(System.in).nextLine().charAt(0);
			}
		}   

       private boolean openingParenthesis(char entry)
        {
            if ((entry == '(') || (entry == '{') || (entry == '['))
                return (true);
            else
                return (false);
        }

        private boolean closingParenthesis(char entry)
        {
            if ((entry == ')') || (entry == '}') || (entry == ']'))
                return (true);
            else
                return (false);
        }

        private boolean match(char entry1, char entry2)
        {
            if ((entry1 == '(') && (entry2 == ')'))
                return (true);
            else if ((entry1 == '{') && (entry2 == '}'))
                return (true);
            else if ((entry1 == '[') && (entry2 == ']'))
                return (true);
            else
                return (false);

        }
    
}