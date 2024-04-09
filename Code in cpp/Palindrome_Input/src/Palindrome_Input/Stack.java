package palindrome;
import java.util.*;
public class Stack {
        Node top;
        public Stack()
        {
            top = null;
        }

        public void push(int element)
        {
            Node fresh;
            fresh = new Node(element, null);
            fresh.next = top;
            top = fresh;
        }
        public int pop()
        {
            int d = 0;
            d = top.info;
            top = top.next; /* Make top point to the next node in
            sequence */
            return d;

        }
    public static void main(String[] args) {
            Stack mystack = new Stack();
			char stackChar;
			char stringChar;
			int ispalindrome = 1;
			char[] str = new char[20];
			System.out.print("\nEnter a string: ");
			str = new Scanner(System.in).nextLine().toCharArray();
			for (int i = 0; i < str.length; i++)
			{
				mystack.push(str[i]);
			}
			for (int i = 0; i < str.length; i++)
				{
					stringChar = Character.toLowerCase(str[i]);
					stackChar = (char)mystack.pop();
					stackChar = Character.toLowerCase(stackChar);
					if (stringChar != stackChar)
					{
						ispalindrome = 0;
						break;
					}
				}
				if (ispalindrome == 1)
				{
					System.out.println("\nString is a palindrome");
				}

				else
				{
					System.out.println("\nString is not a palindrome");
				}

				new Scanner(System.in).nextLine();
            }
    }
