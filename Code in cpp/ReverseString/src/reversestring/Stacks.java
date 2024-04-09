package reversestring;
import java.util.*;
public class Stacks {
   	private Node top;
		public Stacks()
		{
			top = null;
		}

		private boolean empty()
		{
			if (top == null)
			{
				return (true);
			}
			else
			{
				return (false);
			}
		}

		public void push(char element)
		{
			Node fresh;
			fresh = new Node(element, null);

			fresh.next = top;
			top = fresh;

		}

		public void pop()
		{
			System.out.print(top.info);
			top = top.next; /* Make top point to the next node in
            sequence */
		}


		public static void main(String[] args)
		{
			Stacks s = new Stacks();
			 char[] str = new char[20];
			System.out.print("\nEnter a string: ");
			str = new Scanner(System.in).nextLine().toCharArray();
			for (int i = 0; i < str.length; i++)
			{
				s.push(str[i]);
			}
			System.out.print("\nThe reversed string is: ");
			while (!s.empty())
			{
				s.pop();

			}
		 new Scanner(System.in).nextLine();
		}
}
