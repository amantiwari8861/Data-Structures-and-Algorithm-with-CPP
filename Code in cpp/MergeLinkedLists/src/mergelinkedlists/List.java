/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mergelinkedlists;

import java.util.Scanner;

public class List {

    /**
     * @param args the command line arguments
     */
    Node START;
        public List()
        {
            START = null;
        }
        void reset()
        {
            START = null;
        }
 public void addNode(int element) //Adds a Node in the list
 {
		Node newnode = new Node();
		newnode.info = element;
		if (START == null || element <= START.info) //If the node to be inserted is the first node
		{
			newnode.next = START;
			START = newnode;
			return;
		}
		Node previous, current;
		for (previous = current = START; current != null && element > current.info; previous = current, current = current.next)
		{
		}
		newnode.next = current;
		previous.next = newnode;
}
private Node getStart()
	{
		return START;
	}
private void traverse()
{
	Node ptr;
	for (ptr = START; ptr != null; ptr = ptr.next)
	{
		System.out.print(ptr.info + "     ");
	}
    System.out.println();
}
private List merge(List l2)
{
Node p1 = START;
Node p2 = l2.getStart();
List l3 = new List();
while (true)
{
	if (p1.info <= p2.info)
		{
		l3.addNode(p1.info);
		if (p1.next == null)
		{
		while (p2 != null)
			{
				l3.addNode(p2.info);
				p2 = p2.next;
			}
		return l3;
		}
	p1 = p1.next;
	}
	else
		{
		l3.addNode(p2.info);
		if (p2.next == null)
		{
		while (p1 != null)
		{
		l3.addNode(p1.info);
		p1 = p1.next;
		}
		return l3;
		}
	p2 = p2.next;
	}
}
}
   public static void main(String[] args)
   {
        // TODO code application logic here
        List list1 = new List();
	List list2 = new List();
	List list3 = new List();
	while (true)
	{
		System.out.println("\nMenu");
		System.out.println("1. Create lists.");
		System.out.println("2. Merge lists");
		System.out.println("3. Exit.");
		System.out.print("\nEnter your choice: ");
		char ch = new Scanner(System.in).nextLine().charAt(0);
		switch (ch)
		{
			case '1':
			{
			char choice = 'y';
			System.out.println("\nCreate first list....\n");
			list1.START = null;
			while (choice == 'y')
			{
			System.out.print("\nEnter a number: ");
			int num = Integer.parseInt(new Scanner(System.in).nextLine());
			list1.addNode(num);
			while (true)
			{
			System.out.print("\nAdd more elements? (y/n): ");
			choice = new Scanner(System.in).nextLine().charAt(0);

			if (choice != 'y' && choice != 'n')
			{
			System.out.println("Invalid input");
			}
			else
			{
			break;
			}
			}
		}
	System.out.println("\nFirst list is....\n");
	list1.traverse();
	System.out.println("\nCreate second list....\n");
	list2.START = null;
	choice = 'y';
	while (choice == 'y')
	{
	System.out.print("\nEnter a number: ");
	int num = Integer.parseInt(new Scanner(System.in).nextLine());
	list2.addNode(num);
	while (true)
	{
	System.out.print("\nAdd more elements? (y/n): ");
	choice = new Scanner(System.in).nextLine().charAt(0);
        if (choice != 'y' && choice != 'n')
	 {
	System.out.println("Invalid input");
	 }
	else
	{
	break;
	}
	}
	}
	System.out.println("\nSecond list is....\n");
	list2.traverse();
	}
	break;
	case '2':
	{
	list3 = list1.merge(list2);
	list3.traverse();
	}
	break;
	case '3':
	{
	return;
	}
	default:
	{
	System.out.println("Invalid option");
	break;
	}
	}

	}
    }
    
}
