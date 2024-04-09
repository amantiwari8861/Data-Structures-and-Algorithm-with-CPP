package implement_queue;
import java.util.*;
/* Class to represent a queue */
public class Queue {
private Node FRONT, REAR; // Pointers to the first and last nodes of the queue
		public Queue()
		{
			/* Set FRONT and REAR to null as the queue is initially empty. */
			FRONT = null;
			REAR = null;
		}
		public void insert(int element) // Inserts a node in the queue
		{
			Node newnode;
			newnode = new Node(element, null);
			if (FRONT == null)
			{
				/* If the queue is empty, then both FRONT and REAR should point to the new node. */
				FRONT = newnode;
				REAR = newnode;
			}
			else
			{
				/* If the queue is NOT empty, then REAR points to the last node. REAR should now point to the new node. */
				REAR.next = newnode;
				REAR = newnode;
			}
			System.out.println("\nNumber " + element + " is inserted into the queue\n");
		}
            public void remove() // Deletes node from the queue
            {
			if (FRONT == null) // Check if the queue is empty
			{
				System.out.println("Queue is empty");
				return;
			}
			else
			{
				System.out.println("\nThe element deleted from the queue is: " + FRONT.data);
				FRONT = FRONT.next; // FRONT will now point to the next node in the queue.
			}
  }
		public void display() // displays the elements of the queue
		{
			Node tmp;
			if (FRONT == null) // Checks if the queue is empty
			{
				System.out.println("Queue is empty");
				return;
			}
			else
			{
				System.out.println("\nElements in the queue are\n");
				for (tmp = FRONT; tmp != null; tmp = tmp.next) // traverse the queue through tmp node
				{
					System.out.print(tmp.data + "   ");
				}
				System.out.println();
			}
		}
               
    public static void main(String[] args) {
        Queue q=new Queue();
        while (true)
	{
	try
	{
		System.out.println("\nMenu");
		System.out.println("1. Implement insert operation in the queue");
		System.out.println("2. Implement a delete operation on the queue");
		System.out.println("3. Display values");
		System.out.println("4. Exit");
		System.out.print("\nEnter your choice (1-4): ");
		char ch = new Scanner(System.in).nextLine().charAt(0);
		System.out.println();
		switch (ch)
		{
		case '1':
			System.out.print("Enter a number: ");
			int num = Integer.parseInt(new Scanner(System.in).nextLine());
			q.insert(num);
			break;
		case '2':
			q.remove();
			break;
		case '3':
			q.display();
			break;
		case '4':
			return;
		default:
			System.out.println("Invalid option!!");
			break;
			
		}
	}
	catch (RuntimeException e)
	{
	System.out.println("Check for the values entered." + e.toString());
	}
	}
	}
    }
    

