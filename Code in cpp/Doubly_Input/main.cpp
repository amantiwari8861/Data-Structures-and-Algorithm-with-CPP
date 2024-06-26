#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;
class Node
{
   /* Node class represents the node of doubly-linked list. It consists of the information part and links to its succeeding and preceeding nodes in terms of next and previous nodes.*/
public:
   int rollNumber;
   char name[20];
   Node *next; /* Points to the succeeding node */
   Node *prev; /* Points to the preceeding node */
};

class DoubleLinkedList
{

   Node *START;

public:
   DoubleLinkedList();
   bool Search(int rollNo, Node **previous, Node **current);
   bool listEmpty();
   void traverse();
   void revtraverse();
};
DoubleLinkedList ::DoubleLinkedList()
{
   START = NULL;
}
bool DoubleLinkedList ::Search(int rollNo, Node **previous, Node **current) /* Checks wheteher the specified node is present */
{

   for (*previous = *current = START; *current != NULL && rollNo != (*current)->rollNumber; *previous = *current, *current = (*current)
                                                                                                                                 ->next)
   {
   }
   return (*current != NULL);
}

bool DoubleLinkedList ::listEmpty()
{
   if (START == NULL)
      return true;
   else
      return false;
}

void DoubleLinkedList ::traverse() /* Traverses the list */
{
   if (listEmpty())
      cout << "\nList is empty.\n";
   else
   {
      cout << "\nRecords in the ascending order of roll numbers are:\n"
           << endl;
      Node *currentNode;
      for (currentNode = START; currentNode != NULL;
           currentNode = currentNode->next)
      {
         cout << currentNode->rollNumber << "   " << currentNode->name << "\n";
      }
   }
}

void DoubleLinkedList ::revtraverse() /* Traverses the list in the reverse direction */
{
   if (listEmpty())
      cout << "\nList is empty.\n";
   else
   {
      cout << "\nRecords in the descending order of roll numbers are:\n"
           << endl;
      Node *currentNode;
      for (currentNode = START; currentNode
                                    ->next != NULL;
           currentNode = currentNode->next)
      {
      }
      while (currentNode != NULL)
      {
         cout << currentNode->rollNumber << "   " << currentNode->name << "\n";
         currentNode = currentNode->prev;
      }
   }
}

int main()
{
   DoubleLinkedList obj;
   int rollNo;
   char ch;
   while (1)
   {
      cout << endl
           << "Menu";
      cout << "\n1. View all records in the ascending order of roll numbers" << endl;
      cout << "2. View all records in the descending order of roll numbers" << endl;
      cout << "3. Search for a record in the list" << endl;
      cout << "4. Exit" << endl;
      cout << "\nEnter your choice (1-4): ";
      cin >> ch;
      switch (ch)
      {
      case '1':
      {
         obj.traverse();
      }
      break;

      case '2':
      {
         obj.revtraverse();
      }
      break;
      case '3':
      {
         if (obj.listEmpty() == true)
         {
            cout << "\nList is empty\n";
            break;
         }
         Node *prev, *curr;
         cout << "\nEnter the roll number of the student whose record you want to search: ";
         cin >> rollNo;
         if (obj.Search(rollNo, &prev, &curr) == false)
            cout << "\nRecord not found" << endl;
         else
         {
            cout << "\nRecord found" << endl;
            cout << "\nRoll number: " << curr->rollNumber;
            cout << "\n\nName: " << curr->name;
            cout << "\n";
         }
         break;
      case '4':
      {
         exit(0);
      }
      break;
      default:
      {
         cout << "\nInvalid option\n";
      }
      break;
      }
      }
   }
   return (0);
}
