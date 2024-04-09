/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package studentlist;
import java.util.*;
/**
 *
 * @author Ashish.Srivastav
 */
public class List {
	private Node START;
	public List()
	{
		START = null;
	}
	public final void addNode(String element) //Adds a Node in the list
	{
		Node newnode = new Node();
		newnode.info = element;
		newnode.next = null;
		if (START == null) //If the node to be inserted is the first node
		{

			newnode.next = START;
			START = newnode;
			return;
		}
		Node currentNode;
		for (currentNode = START; currentNode.next != null; currentNode = currentNode.next)
		{
		}
		currentNode.next = newnode;
	}

	public final void traverse() //Traverses the list
	{
		if (START == null) //Checks whether the list is empty
		{
			System.out.println("\nList is empty\n");
			return;
		}
		System.out.println("\nThe list is\n");
		Node currentNode;
		for (currentNode = START; currentNode != null; currentNode = currentNode.next)
		{
			System.out.print(currentNode.info + "   ");
		}
		System.out.println();
	}

	public final void sort()
	{
		Node LAST;
		LAST = null;
		Node ptr1, ptr2;
		while (START.next != LAST)
		{
			ptr1 = START;
			ptr2 = START.next;
			while (ptr2 != LAST)
			{
				if ((ptr1.info.compareTo(ptr2.info) > 0))
				{
					String str;
					str = ptr1.info;
					ptr1.info = ptr2.info;
					ptr2.info = str;
				}
				ptr1 = ptr1.next;
				ptr2 = ptr2.next;
			}
			LAST = ptr1;
		}
		traverse();
	}
	public static void main(String[] args)
	{
		List obj = new List();
		while (true)
		{
			try
			{
				String name = "";
				System.out.println("\nMenu.");
				System.out.println("1. Add element.");
				System.out.println("2. Sort the list.");
				System.out.println("3. Traverse.");
				System.out.println("4. Exit.");
				System.out.print("\nEnter your choice: ");
				char ch = new Scanner(System.in).nextLine().charAt(0);
				switch (ch)
				{
					case '1':
					{
							int k = 0;
							while (k == 0)
							{
								System.out.print("\nEnter name: ");
								name = new Scanner(System.in).nextLine();
								char[] myarr = name.toCharArray();
								if (myarr[0] == '0' || myarr[0] == '1' || myarr[0] == '2' || myarr[0] == '3' || myarr[0] == '4' || myarr[0] == '5' || myarr[0] == '6' || myarr[0] == '7' || myarr[0] == '8' || myarr[0] == '9')
								{
									System.out.println("A name cannot start with a numeric value");
									continue;
								}
								else
								{
									k = 1;
								}
							}
							System.out.println();
							obj.addNode(name);
							System.out.println("\nInserted " + name + "\n");
					}
						break;
					case '2':
					{
							obj.sort();
					}
						break;
					case '3':
					{
							obj.traverse();
					}
						break;
					case '4':
						return;
					default:
					{
							System.out.println("Invalid option");
							break;
					}
				}

			}
			catch (RuntimeException e)
			{
				System.out.println("Check for the value entered.");
			}
		}

	}
    
}
