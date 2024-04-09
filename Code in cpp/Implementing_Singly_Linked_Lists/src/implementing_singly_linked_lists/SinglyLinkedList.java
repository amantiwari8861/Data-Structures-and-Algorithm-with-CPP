package implementing_singly_linked_lists;
import java.util.*;
/* Create a class to represent the linked list. To represent a linked list, you only need a reference to the first node of the list. */
public class SinglyLinkedList
{
public Node START; //Reference to the first node of the list.
public SinglyLinkedList ()
{
	START = null;
}
public void addNode() // Adds a Node in the list
{
	int rollNo;
	String nm;
        System.out.print("\nEnter the roll number of the student: ");
	rollNo = Integer.parseInt(new Scanner(System.in).nextLine());
	System.out.print("\nEnter the name of the student: ");
	nm = new Scanner(System.in).nextLine();
        // create a new node and assign values to it
	Node newnode = new Node();
	newnode.rollNumber = rollNo;
	newnode.name = nm;
	/* Locate the position of the new node in the list */
		Node previous, current;
		previous = null;
		current = START;
 /* Scan through the linked list until you find a node whose roll number is greater than the roll number of the new node.*/	
	while ((current != null) && (rollNo >= 	current.rollNumber))
		{
		if (rollNo == current.rollNumber)
		{
		System.out.println("\nDuplicate roll numbers not allowed\n");
		return;
		}
		previous = current;
		current = current.next;
	}
/* Once the above for loop is executed, prev and current are positioned in such a manner that the position for the new node is in between them. */          
	newnode.next = current;
        if(previous==null)
            START=newnode;
        else
            previous.next = newnode;
	}
public boolean delNode(int rollNo) /* Deletes the specified node from the list */
	{
	Node previous, current;
	previous=null;
        current = START;
        while ((current != null) && (rollNo != current.rollNumber))
		{
		previous = current;
		current = current.next;
		}
         	if(current == null)
		{
			return false;
		}
         else
         {
/* If the node is present in the list, the following statements will be executed */
		
		if (current == START)
		{
			START = START.next;
		}
                else
                   previous.next = current.next;
		return true;
         }
	}
public Node Search(int rollNo) // Checks whether the specified node is present in the list or not
{
		Node current = START;
	/* Scan the linked list to search for the specified roll number */
		while ((current != null) && (rollNo != current.rollNumber))
		{
		 current = current.next;
		}
   return current;
}
public void traverse() // Displays the contents of the list
{
	if (listEmpty())
	{
		System.out.println("\nList is empty.\n");
	}
	else
	{
		System.out.println("\nThe records in the list are :\n");
		Node currentNode;
		for (currentNode = START; currentNode != null; currentNode = currentNode.next)
		{
		System.out.print(currentNode.rollNumber + "  " +currentNode.name + "\n");
		}
	System.out.println();
	}
}
public boolean listEmpty() // Checks whether the list is empty
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
		SinglyLinkedList obj = new SinglyLinkedList ();
		while (true)
		{
		try
		{
		System.out.println("\nMenu");
		System.out.println("1. Add a record to the list");
		System.out.println("2. Delete a record from the list");
		System.out.println("3. View all the records in the list");
		System.out.println("4. Search for a record in the list");
		System.out.println("5. Exit");
		System.out.print("\nEnter your choice (1-5): ");
		char ch = new Scanner(System.in).nextLine().charAt(0);
		switch (ch)
		{
		case '1':
			obj.addNode();
			break;
		case '2':
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
			System.out.println("\nRecord not found.");
                        }
                        else
                        {
                            System.out.println("Record with roll number " + rollNo + " deleted ");
                        }
            break;
case '3':
	obj.traverse();
	break;
case '4':
	if (obj.listEmpty() == true)
        {
	System.out.println("\nList is empty");
	break;
        }
	System.out.print("\nEnter the roll number of the student whose record is to be searched: ");
	int num = Integer.parseInt(new Scanner(System.in).nextLine());
	Node result=obj.Search(num);
        if ( result== null)
            System.out.println("\nRecord not found.");
        else
	{
	System.out.println("\nRecord found");
	System.out.println("\nRoll number: " + result.rollNumber);
	System.out.println("\nName: " + result.name);
	}
	break;
case '5':
		System.exit(0);
default:
	System.out.println("\nInvalid option");
		break;
}
}
catch (RuntimeException e)
{
	System.out.println("\nCheck the value entered.");
}
}
}   
}

