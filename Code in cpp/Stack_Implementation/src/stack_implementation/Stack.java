/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stack_implementation;
import java.util.*;
/**
 *
 * @author Ashish.Srivastav
 */
/* Class to represent a stack */
	public class Stack
	{
		private Node top; // Refers to the top of the stack

		public Stack() // Initializes stack
		{
			top = null;
		}
		private boolean empty() // Checks whether the stack is empty
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

		public final void push(int element) // Inserting an element in the stack
		{
			Node fresh; // refers to new node
			fresh = new Node(element, null); // allocating memory to the new node

			fresh.next = top; // Make next field of the new node point to the top of the stack
			top = fresh; // Make top points to the new node
			System.out.println("\n" + element + " pushed.");
		}

		public final void pop() // Pops an element from the stack
		{
			System.out.println("\nThe popped element is: " + top.info);
			top = top.next; /* Make top point to the next node in
            sequence */
		}
		public final void display()
		{
			Node tmp;
			if (empty()) // If stack is empty
			{
				System.out.println("\nStack Empty");
			}
			else
			{
				System.out.println("\nStack Elements:");
				// Traverse the list from beginning till end
				for (tmp = top; tmp != null; tmp = tmp.next)
				{
					System.out.println(tmp.info);
				}
				System.out.println();
			}
		}
		public static void main(String[] args)
		{
			Stack s = new Stack();
			while (true)
			{
				System.out.println();
				System.out.println("\n***Stack Menu***\n");
				System.out.println("1. Push.");
				System.out.println("2. Pop");
				System.out.println("3. Display");
				System.out.println("4. Exit");

				System.out.print("\nEnter your choice: ");

				char ch = new Scanner(System.in).nextLine().charAt(0);
                                switch (ch)
				{
					case '1':
						System.out.print("\nEnter a number: ");
						int num = Integer.parseInt(new Scanner(System.in).nextLine());
						s.push(num);
						break;
					case '2':
						if (s.empty())
						{
							System.out.println("\nStack Empty");
							break;
						}
						s.pop();
						break;
					case '3':
						s.display();
						break;
					case '4':
						return;
					default:
						System.out.println("\nInvalid Choice");
						break;
				}
			}
		}
	}