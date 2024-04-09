package tree_input;


    /* A Node class consists of three things, the information, reference to the 
       right child, and reference to the left child. */
  public  class Node
    {
        public String info;
        public Node lchild;
        public Node rchild;

        public Node(String i, Node l, Node r) /* Constructor for the Node class */
        {
            info = i;
            lchild = l;
            rchild = r;
        }
    }