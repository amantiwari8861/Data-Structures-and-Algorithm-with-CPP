/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package doubly_input;
/**
 *
 * @author Ashish.Srivastav
 */
import java.util.*;

public class DoubleLinkedList
{
	private Node START;
	public DoubleLinkedList()
	{
		START = null;
	}

        public void addNode() //Adds a new node
        {
		int rollNo;
		String nm;
		System.out.print("\nEnter the roll number of the student: ");
		rollNo = Integer.parseInt((new Scanner(System.in)).nextLine());
		System.out.print("\nEnter the name of the student: ");
		nm = (new Scanner(System.in)).nextLine();
		Node newnode = new Node();
		newnode.rollNumber = rollNo;
		newnode.name = nm;
		if (START == null || rollNo <= START.rollNumber) //Checks if the list is empty
		{
			if ((START != null) && (rollNo == START.rollNumber))
			{
				System.out.println("\nDuplicate roll numbers not allowed");
				return;
			}
			newnode.next = START;
			if (START != null)
			{
				START.prev = newnode;
			}
			newnode.prev = null;
			START = newnode;
			return;
		}
		Node previous, current;
		for (current = previous = START; current != null && rollNo >= current.rollNumber; previous = current, current = current.next)
		{
			if (rollNo == current.rollNumber)
			{
				System.out.println("\nDuplicate roll numbers not allowed");
				return;
			}
		}
		/*On the execution of the above for loop, prev and current will point to those nodes
		between which the new node is to be inserted.*/
		newnode.next = current;
		newnode.prev = previous;

		if (current != null) // If the node to be inserted is not the last node of the list
		{
			current.prev = newnode;
		}
		previous.next = newnode;
            }
	public Node Search(int rollNo, Node previous, Node current) // Checks wheteher the specified node is present
	{
		for (previous = current = START; current!= null && rollNo != current.rollNumber; previous = current, current= current.next)
		{
		}
/* The preceding for loop traverses the list. If the specified node is found then the function returns true, otherwise false.*/
		return current;
	}
 public boolean delNode(int rollNo) //Deletes the specified node
{
		Node previous, current;
		previous = current = null;
		for (previous = current = START; current!= null && rollNo != current.rollNumber; previous = current, current= current.next);
		
		if (current==null)
		{
			return false;
		}
		if (current == START) //If the first node is to be deleted
		{
			START = START.next;
			if (START != null)
			{
				START.prev = null;
			}
			return true;
		}
		previous.next = current.next;
		if (current.next != null) // If the node to be deleted is not the last node of the list
		{
			current.next.prev = previous;
		}
		return true;
}
	public void traverse() // Traverses the list
	{

		if (listEmpty())
		{
			System.out.println("\nList is empty");
		}
		else
		{
			System.out.println("\nRecords in the ascending order of roll numbers are:\n");
			Node currentNode;
			for (currentNode = START; currentNode != null; currentNode = currentNode.next)
			{
				System.out.print(currentNode.rollNumber + "   " + currentNode.name + "\n");
			}
		}
	}
public void revtraverse() // Traverses the list in the reverse direction
{
		if (listEmpty())
		{
			System.out.println("\nList is empty");
		}
		else
		{
			System.out.println("\nRecords in the descending order of roll numbers are:\n");
			Node currentNode;
			for (currentNode = START; currentNode.next != null; currentNode = currentNode.next)
			{
			}
			while (currentNode != null)
			{
				System.out.print(currentNode.rollNumber + "   " + currentNode.name + "\n");
				currentNode = currentNode.prev;
			}
		}
}
	public  boolean listEmpty()
	{
		if (START == null)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	public static void main(String[] args)
	{
		DoubleLinkedList obj = new DoubleLinkedList();
		while (true)
		{
			try
			{
				System.out.println("\nMenu");
				System.out.println("1. Add a record to the list");
				System.out.println("2. Delete a record from the list");
				System.out.println("3. View all records in the ascending order of roll numbers");
				System.out.println("4. View all records in the descending order of roll numbers");
				System.out.println("5. Search for a record in the list");
				System.out.println("6. Exit\n");
				System.out.print("Enter your choice (1-6): ");
				char ch = new Scanner(System.in).nextLine().charAt(0);
				switch (ch)
				{
					case '1':
					{
							obj.addNode();
					}
						break;
					case '2':
					{
							if (obj.listEmpty())
							{
								System.out.println("\nList is empty");
								break;
							}
							System.out.print("\nEnter the roll number of the student whose record is to be deleted: ");
							int rollNo = Integer.parseInt(new Scanner(System.in).nextLine());
							System.out.println();
							if (obj.delNode(rollNo) == false)
							{
								System.out.println("Record not found");
							}
							else
							{
								System.out.println("Record with roll number " + rollNo + " deleted \n");
							}
					}
						break;
					case '3':
					{
							obj.traverse();
					}
						break;
					case '4':
					{
							obj.revtraverse();
					}
						break;
					case '5':
					{
							if (obj.listEmpty() == true)
							{
								System.out.println("\nList is empty");
								break;
							}
							Node prev, curr;
							prev = curr = null;
							System.out.print("\nEnter the roll number of the student whose record you want to search: ");
							int num = Integer.parseInt(new Scanner(System.in).nextLine());
							Node temp = obj.Search(num, prev, curr);
							if(temp==null)
							{
							System.out.println("\nRecord not found");
							}
							else
							{
							System.out.println("\nRecord found");
							System.out.println("\nRoll number: " + curr.rollNumber);
							System.out.println("\nName: " + curr.name);
							}
					}
						break;
					case '6':
						return;
					default:
					{
							System.out.println("\nInvalid option");
					}
						break;
				}
			}
			catch (RuntimeException e)
			{
				System.out.println("Check for the values entered.");
			}
		}
	}
}