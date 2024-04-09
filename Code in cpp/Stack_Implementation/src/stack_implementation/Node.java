/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package stack_implementation;

/* Class to represent a node of the stack */
	public class Node
	{
		public int info; //  Variable to store data
		public Node next; // Variable to store address of next node in the stack
		public Node(int i, Node n) // Constructor to initialize node contents
		{
			info = i;
			next = n;
		}
	}