/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reversinglist;
import java.util.*;
/**
 *
 * @author Ashish.Srivastav
 */

public class List
{
	private Node START;
	public List()
	{
		START = null;
	}


	public final void addNode(int rollNo, String nm) //Adds a Node in the list
	{
		Node newnode = new Node();
		newnode.rollNumber = rollNo;
		newnode.name = nm;

		if (START == null || rollNo <= START.rollNumber) //If the node to be inserted is the first node
		{
			if ((START != null) && (rollNo == START.rollNumber))
			{
				System.out.println("Duplicates not allowed");
				return;
			}
			newnode.next = START;
			START = newnode;
			return;
		}

		Node previous, current;
		for (previous = current = START; current != null && rollNo >= current.rollNumber; previous = current, current = current.next)
		{
			if (rollNo == current.rollNumber)
			{
				System.out.println("Duplicates not allowed");
				return;
			}
		}

		//Once the above for loop is executed, previous and current are positioned in such
		//a manner that the position for the new node is in between them. 
		newnode.next = current;
		previous.next = newnode;
	}

	public final boolean listEmpty()
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
	public final void traverse() //Traverses the list
	{

		Node currentNode;
		for (currentNode = START; currentNode != null; currentNode = currentNode.next)
		{
			System.out.println(currentNode.rollNumber + "     " + currentNode.name);
		}
		System.out.println();

	}
	public final void reverse()
	{
		if (listEmpty())
		{
			System.out.println("List is empty.");
		}
		else
		{
			Node ptr1, ptr2, ptr3;
			if (START.next == null)
			{
				return;
			}
			ptr1 = START;
			ptr2 = ptr1.next;
			ptr3 = ptr2.next;

			ptr1.next = null;
			ptr2.next = ptr1;
			while (ptr3 != null)
			{
				ptr1 = ptr2;
				ptr2 = ptr3;
				ptr3 = ptr3.next;
				ptr2.next = ptr1;
			}
			START = ptr2;
		}
	}

	public static void main(String[] args)
	{
		List obj = new List();
		int num;
		char ch;
		while (true)
		{
			int rollNo;
			String nm = "";

			System.out.println("Enter the roll number of student (in figures): ");
			rollNo = Short.parseShort(new Scanner(System.in).nextLine());
			int k = 0;
			while (k == 0)
			{
				System.out.println("Enter the name of the student: ");
				//cin>>nm;
				nm = new Scanner(System.in).nextLine();
				char[] myarr = nm.toCharArray();
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
			obj.addNode(rollNo, nm);
			System.out.println("Do you wish to continue (y/n): ");
			char ch1;
			ch1 = new Scanner(System.in).nextLine().charAt(0);
			if ((ch1 == 'n') || (ch1 == 'N'))
			{
				break;
			}


		}

		System.out.println("The list of records is");
		obj.traverse();

		obj.reverse();
		System.out.println("\nThe reversed list is:\n");
		obj.traverse();
		new Scanner(System.in).nextLine();

	}
}