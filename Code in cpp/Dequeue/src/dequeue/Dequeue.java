
package dequeue;
import java.util.*;

public class Dequeue {
Node FRONT, REAR;
        public Dequeue()
        {
            //Initially, FRONT and REAR will point to null as the queue is empty
            FRONT = null;
            REAR = null;
        }
        public void insert_left(int element)//Inserts node to the left of the queue
        {
            Node newnode;
            newnode = new Node(element, null);
            if (FRONT == null)
            {
                //If the queue is empty i.e if FRONT points to null, then the 
                //first node to be inserted in the queue will act as both REAR and FRONT.                
                FRONT = newnode;
                REAR = newnode;
            }
            else
            {
                //If queue is NOT empty, then the next pointer of the new node will 
                //point to FRONT. Now the inserted node will become FRONT.
                newnode.next = FRONT;
                FRONT = newnode;
            }
        }
        public void insert_right(int element)//Inserts node to the right of the queue
        {
            Node newnode;
            newnode = new Node(element, null);
            if (FRONT == null)
            {
                //If the queue is empty i.e if FRONT points to null, then the 
                //first node to be inserted in the queue will act as both REAR and FRONT.                
                FRONT = newnode;
                REAR = newnode;
            }
            else
            {
                //If queue is NOT empty, then the next pointer of the REAR node will
                //point to the node to be inserted. Now the inserted node will become
                //REAR.              
                REAR.next = newnode;
                REAR = newnode;
            }
        }
public void delete_right() //Deletes node from the right of the queue
{
			if (FRONT == null) //Checks if the queue is empty
			{
				System.out.println("Queue is empty");
			}
			else
			{
				if (FRONT.next == null) //Checks if there is only one element in the queue.
				{
					System.out.println("\nValue deleted from the queue is " + FRONT.data);
					FRONT = null;
					REAR = null;
				}
				else
				{
					Node tmp;
					tmp = FRONT; //node tmp is made to point to FRONT.
					while (tmp.next != REAR)
					{
						tmp = tmp.next;
					}
					//At the end of the while loop, tmp will point to the 
					//second last element of the queue.
					System.out.println("\nValue deleted from the queue is  " + tmp.next.data);
					REAR = tmp; //tmp will become REAR and the next pointer of tmp will point to null.
					tmp.next = null;
				}
			}
}    
public final void delete_left() //Deletes node from the left of the queue
{
			if (FRONT == null) //Checks if the queue is empty
			{
				System.out.println("Queue is empty");
				return;
			}
			else
			{
				if (FRONT.next == null) //Checks if there is only one element in the queue.
				{
					System.out.println("\nValue deleted from the queue is " + FRONT.data);
					FRONT = null;
					REAR = null;
				}
				else
				{
					System.out.println("\nValue deleted from the queue is " + FRONT.data);
					Node tmp;
					tmp = FRONT; //tmp is made to point to FRONT
					FRONT = FRONT.next; //The next node of FRONT will now become FRONT
				}
			}
}
 public void display() //Displays the elements of the queue
 {
			Node tmp;
			if (FRONT == null) //Checks if the queue is empty
			{
				System.out.println("Queue is empty");
			}
			else
			{
				System.out.println("\nThe elements in the queue are........\n");
				//tmp is made to point to FRONT and the queue is traversed using tmp.
				for (tmp = FRONT; tmp != null; tmp = tmp.next)
				{
					System.out.print(tmp.data + "    ");
				}
			}
			System.out.println();
 }
    public static void main(String[] args) {
       Dequeue d = new Dequeue();
			int num;
			while (true)
			{

				System.out.println("\nMenu");
				System.out.println("1. Insert value to the left of the queue");
				System.out.println("2. Insert value to the right of the queue");
				System.out.println("3. Delete value from left");
				System.out.println("4. Delete value from right");
				System.out.println("5. Display the values");
				System.out.println("6. Exit.");
				System.out.print("\nEnter your choice (1-6): ");
				char ch = new Scanner(System.in).nextLine().charAt(0);
				System.out.println();
				switch (ch)
				{
					case '1':
					{
							System.out.print("Enter a number: ");
							num = Integer.parseInt(new Scanner(System.in).nextLine());
							d.insert_left(num);
					}
						break;
					case '2':
					{
							System.out.print("\nEnter a number: ");
							num = Integer.parseInt(new Scanner(System.in).nextLine());
							d.insert_right(num);
					}
						break;
					case '3':
					{
							d.delete_left();
					}
						break;
					case '4':
					{
							d.delete_right();
					}
						break;
					case '5':
					{
							d.display();
					}
						break;
					case '6':
					{
							return;
					}
					default:
					{
							System.out.println("Invalid option");
					}
						break;
				}

			}
		 }

    }
