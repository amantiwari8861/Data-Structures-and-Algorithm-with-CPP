#include <iostream>
#include <cstring>
using namespace std;

class Node
{
/* The Node class consists of three data members, the
information, reference to the right child, and reference to the left child. */
	public:
	char info[50];
	Node *lchild;
	Node *rchild;
	Node(char i[20],Node *l,Node *r)
	{
		strcpy (info, i);
		lchild = l;
		rchild = r;
	} /* Constructor for the Node class */
};
class BinaryTree
{
  public:
  Node *ROOT;
  BinaryTree();
  void insert(char element[20]);
  void find(char element[20], Node **parent, Node **location);
  void inorder(Node *ptr);
  void preorder(Node *ptr);
  void postorder(Node *ptr);

};
BinaryTree :: BinaryTree()
{
	ROOT=NULL; /* Initializing ROOT to null */
}
void BinaryTree :: insert(char element[50]) /* Inserts a Node in the Binary Search Tree */
{
	Node *tmp, *parent,*currentNode;
	find(element,&parent,&currentNode);
if(currentNode!=NULL) /* Checks if the node to be inserted is already present or not */
	{
		cout<<"\nDuplicate words not allowed";
		return;
	}
	else /* If the specified Node is not present */
	{
		tmp=new Node(element,NULL,NULL); // creates a node
		if(parent==NULL) /* If the tree is empty */
			ROOT=tmp;
		else
			if(strcmp(element,parent->info)<0)
				parent->lchild=tmp;
			else
				parent->rchild=tmp;
	}
}
void BinaryTree :: find(char element[50],Node **parent, Node **currentNode)
{
    /* This function finds a given element in the tree and
    returns a variable containing the address of the
    corresponding node. It also returns a variable
    containing the address of the parent of the node. */
		*currentNode = ROOT;
            *parent = NULL;
            while ((*currentNode != NULL) && (strcmp((*currentNode)
            ->info,element) != 0))
            {
                *parent = *currentNode;
                if (strcmp(element,(*currentNode)->info)<0)
                    *currentNode = (*currentNode)->lchild;
                else
                    *currentNode = (*currentNode)->rchild;
            }
}


void BinaryTree :: inorder(Node *ptr) /* Performs the inorder traversal of the tree */
{

	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		cout<<ptr->info<<"   ";
		inorder(ptr->rchild);
	}

}

int main()
{
	BinaryTree b;
//	 exit;
	char ch,word[50];
	//int num;
	do
	{
		cout<<"\nMenu";;
		cout<<"\n1. Implement insert operation"<<endl;
		cout<<"2. Perform inorder traversal"<<endl;
	cout<<"3. Exit"<<endl;
		cout<<"\nEnter your choice (1-3): ";
		cin>>ch;
		switch(ch)
		{
		case '1':
			{

				cout<<"\nEnter a word: ";
				cin>>word;
				b.insert(word);
			}
			break;
		case '2':
			{
if(b.ROOT==NULL)
	{
		cout<<"Tree is empty";
		return 0;
	}

				cout<<"\n";
				b.inorder(b.ROOT);
				cout<<"\n";
			}
			break;

		case '3':

			break;
		default:
			{
				cout<<"Invalid Option."<<endl;
				break;
			}
		}
	} while(ch!='3');
	return 0;
}
