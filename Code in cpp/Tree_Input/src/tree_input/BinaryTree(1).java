/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tree_input;
import java.util.*;
public class BinaryTree {
   public Node ROOT,parent,currentNode;
	public BinaryTree()
		{
			ROOT = null; // Initializing ROOT to null
		}
		public  void insert(String element) // Inserts a Node in the Binary Search Tree
		{
			Node tmp;
			parent = currentNode = null;
			find(element);
			if (currentNode != null) /* Checks if the node to be
            inserted is already present or not */
			{
				System.out.println("Duplicate words not allowed");
				return;
			}
			else // If the specified Node is not present
			{
				tmp = new Node(element, null, null); /* Creates a
                Node */
				if (parent == null) // If the tree is empty
				{
					ROOT = tmp;
				}
				else
				{
					if (element.compareTo(parent.info) < 0)
					{
						parent.lchild = tmp;
					}
					else
					{
						parent.rchild = tmp;
					}
				}
			}
		}
		public  void find(String element)
{
			/* This function finds the currentNode of the specified Node as well as the 
			   currentNode of its parent. */

			currentNode = ROOT;
			parent = null;
			while ((currentNode != null) && (!element.equals(currentNode.info)))
			{
				parent = currentNode;
				if (element.compareTo(currentNode.info) < 0)
				{
					currentNode = currentNode.lchild;
				}
				else
				{
					currentNode = currentNode.rchild;
				}
			}
}
		public final void inorder(Node ptr) // Performs the inorder traversal of the tree
		{

			if (ptr != null)
			{
				inorder(ptr.lchild);
				System.out.print(ptr.info + "   ");
				inorder(ptr.rchild);
			}
		}
                 public final void remove() // Deletes the specified Node from the tree
 {
			if (ROOT == null) // Checks whether the tree is empty
			{
				System.out.println("Tree is empty");
				return;
			}
		 parent = currentNode = null;
			String element;
			System.out.print("Enter the word to be deleted: ");
			element = new Scanner(System.in).nextLine();
			find(element); // Finds the currentNode of the Node and its parent
			if (currentNode == null)
			{
				System.out.println("\nWord not found in the dictionary");
				return;
			}
			/* Depending upon the status of the child nodes, the lines of code below
			   call the appropriate function for performing the deletion of the specified
			   node from the tree. */
			if (currentNode.lchild == null && currentNode.rchild == null)
			{
				case_1();
			}
			else if (currentNode.lchild != null && currentNode.rchild == null)
			{
				case_2();
			}
			else if (currentNode.lchild == null && currentNode.rchild != null)
			{
				case_2();
			}
			else
			{
				case_3();
			}
 }

		public void case_1() // This function is invoked if the Node to be deleted is the leaf Node
		{
			if (parent == null)
			{
				ROOT = null;
			}
			else
			{
				if (currentNode == parent.lchild)
				{
					parent.lchild = null;
				}
				else
				{
					parent.rchild = null;
				}
			}
		}
		public void case_2() // This function is invoked if the node to be deleted has one child (left or right)
		{
			Node child;
			if (currentNode.lchild != null)
			{
				child = currentNode.lchild;
			}
			else
			{
				child = currentNode.rchild;
			}
			if (parent == null)
			{
				ROOT = child;
			}
			else
			{
				if (currentNode == parent.lchild)
				{
					parent.lchild = child;
				}
				else
				{
					parent.rchild = child;
				}
			}
		}
		public void case_3() // This function is invoked when the Node to be deleted has two children
		{
			Node inorder_suc, inorder_parent;
			inorder_parent = currentNode;
			inorder_suc = currentNode.rchild;
			while (inorder_suc.lchild != null)
			{
				inorder_parent = inorder_suc;
				inorder_suc = inorder_suc.lchild;
			}

			currentNode.info = inorder_suc.info;

			if (inorder_suc.lchild == null && inorder_suc.rchild == null)
			{
				case_1();
			}
			else
			{
				case_2();
			}
		}
     public static void main(String[] args)
 {
			BinaryTree b = new BinaryTree();
			while (true)
			{
				System.out.println("\nMenu");
				System.out.println("1. Implement insert operation");
				System.out.println("2. Perform inorder traversal");
				 System.out.println("3. Implement delete operation");
				System.out.println("4. Exit");
				System.out.print("\nEnter your choice (1-4): ");
				char ch = new Scanner(System.in).nextLine().charAt(0);
				System.out.println();
				switch (ch)
				{
					case '1':
						   System.out.print("Enter a word: ");
						   String word = new Scanner(System.in).nextLine();
						   b.insert(word);
						   break;
					case '2':
						  if (b.ROOT == null)
						  {
								System.out.println("Tree is empty");
								new Scanner(System.in).nextLine();
								return;

						  }
							else
							{
							 b.inorder(b.ROOT);
							}
						  break;
				   case '3':
						  b.remove();
						  break;
					case '4':
						return;
					default:
							System.out.println("Invalid option");
							break;
				}

			}
 }
	}
