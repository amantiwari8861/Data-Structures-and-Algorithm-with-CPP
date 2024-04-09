/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package reversestring;

/**
 *
 * @author Ashish.Srivastav
 */
public class Node {
        public char info;
        public Node next;
        public Node(char i, Node n)
        {
            info = i;
            next = n;
        }
    }