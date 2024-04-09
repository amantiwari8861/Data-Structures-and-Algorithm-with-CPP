package check_parenthesis;
class Stacks {
        Node top;
        public Stacks()
        {
            top = null;
        }
        public boolean empty()
        {
            if (top == null)
                return (true);
            else
                return (false);
        }
        public void push(int element)
        {
            Node fresh;
            fresh = new Node(element, null);

            fresh.next = top;
            top = fresh;
        }

       public char pop()
        {
            char value;
            value = (char)top.info;
            top = top.next; /* Make top point to the next node in
            sequence */
            return value;
       }
    }
 
