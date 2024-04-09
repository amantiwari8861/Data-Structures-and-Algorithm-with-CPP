#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
class Node
{
	/* A Node class consists of three things, the information, reference to the
       right child, and reference to the left child. */
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
  void find(char element[20], Node **parent,Node **location);
  void inorder(Node *ptr);
     void findmin(Node *Tree);
     Node* predecessor(Node *Tree, char element[50]);
  void remove();
  void case_1(Node *parent,Node *currentNode);
  void case_2(Node *parent,Node *currentNode);
  void case_3(Node *parent,Node *currentNode);
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
		tmp=new Node(element,NULL,NULL); /* creates a Node */
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
	/* This function finds the currentNode of the specified Node as well as the
       currentNode of its parent. */

			*currentNode = ROOT;
            *parent = NULL;

            while ((*currentNode != NULL) && (strcmp((*currentNode)->info,element) != 0))
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
	if(ROOT==NULL)
	{
		cout<<"Tree is empty";
		return;
	}
	if(ptr!=NULL)
	{
		inorder(ptr->lchild);
		cout<<ptr->info<<"   ";
		inorder(ptr->rchild);
	}

}

void BinaryTree :: remove() /* Deletes the specified Node from the tree */
{

	if(ROOT==NULL) /* Checks whether the tree is empty */
	{
		cout<<"\nTree is empty\n";
		return;
	}
	Node *parent,*currentNode;
	char element[50];
	cout<<"\nEnter the word to be deleted: ";
	cin>>element;
	find(element, &parent,&currentNode); /* Finds the currentNode of the Node and its parent */
	if(currentNode==NULL)
	{
		cout<<"\nWord not found in the dictionary"<<endl;
		return;
	}
	/* Depending upon the status of the child nodes, the lines of code below
       call the appropriate function for performing the deletion of the specified
       node from the tree. */
	if(currentNode->lchild==NULL && currentNode->rchild==NULL)
		case_1(parent,currentNode);
	else if(currentNode->lchild !=NULL && currentNode->rchild==NULL)
		case_2(parent,currentNode);
	else if(currentNode->lchild==NULL && currentNode->rchild!=NULL)
		case_2(parent,currentNode);
	else
		case_3(parent,currentNode);
}
void BinaryTree :: case_1(Node *parent,Node * currentNode) /* This function is invoked if the Node to be deleted is the leaf Node */
{
	if(parent==NULL)
		ROOT=NULL;
	else
	{
		if(currentNode==parent->lchild)
			parent->lchild=NULL;
		else
			parent->rchild=NULL;
	}
	delete currentNode;
}
void BinaryTree :: case_2(Node *parent,Node *currentNode) /* This function is invoked if the node to be deleted has one child (left or right) */
{
	Node *child;
	if(currentNode->lchild!=NULL)
		child=currentNode->lchild;
	else
		child=currentNode->rchild;
	if(parent==NULL)
		ROOT=child;
	else
	 if(currentNode==parent->lchild)
			parent->lchild=child;
		else
			parent->rchild=child;
	delete currentNode;
}

void BinaryTree :: case_3(Node *parent, Node *currentNode) /* This function is invoked when the Node to be deleted has two children */
{
			Node *inorder_suc, *inorder_parent;
            inorder_parent = currentNode;
            inorder_suc = currentNode->rchild;
            while (inorder_suc->lchild != NULL)
            {
                inorder_parent = inorder_suc;
                inorder_suc = inorder_suc->lchild;
            }
strcpy(currentNode->info,inorder_suc->info);
	if(inorder_suc->lchild==NULL && inorder_suc->rchild==NULL)
		case_1(inorder_parent,inorder_suc);
	else
		case_2(inorder_parent,inorder_suc);

}
     void BinaryTree ::  findmin(Node *Tree)
        {

          if (Tree == NULL)
                cout<<"\nEmpty tree";
            else
            {

                while (Tree->lchild!= NULL)
                {
                    Tree = Tree->lchild;
                }
                cout<<"\nMinimum node is " << Tree->info<<"\n";
            }
        }


Node* BinaryTree::predecessor(Node *pointer, char element[50])
        {

            Node *pred;
            pred = NULL;

            while (pointer!=NULL)
            {
                if (strcmp(pointer->info, element) < 0)
                           {

                    pred = pointer;
                    pointer = pointer->rchild;

                }

                else  if (strcmp(pointer->info, element) == 0)
                     {

                    if (pointer->lchild!=NULL)
                    {

                        pred = pointer->lchild;

                        if (pred!=NULL)
                        {
                            while (pred->rchild!=NULL)
                                pred = pred->rchild;
                        }
                    }

                    return pred;

                }
                else
                {
                    pointer = pointer->lchild;

                }
            }

            return NULL; //not in the tree

        }



int main()
{
	BinaryTree b;
	char ch,word[50],SearchWord[50];
	while(1)
	{
		cout<<"\nMenu";;
		cout<<"\n1. Implement insert operation"<<endl;
		cout<<"2. Perform inorder traversal"<<endl;
        cout<<"3. Implement search operation"<<endl;
        cout<<"4. Find minimum node"<<endl;
        cout<<"5. Locate the inorder predecessor of a node"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"\nEnter your choice (1-6): ";
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
			{
			    cout<<"\nEnter the word to be searched: ";
				cin>>SearchWord;
                Node *temp,*parent,*currentNode;

                    b.find(SearchWord,&parent,&currentNode);
                          if (currentNode!=NULL)
                                cout<<"\nWord found in the dictionary\n";
                            else
                                cout<<"\nWord not found in the dictionary\n";
                            break;
			}
			break;
			 case '4':
                        {

                            b.findmin(b.ROOT);

                        }
                        break;


                         case '5':
                        {
                            cout<<"\nEnter the word whose inorder predecessor needs to be found : ";
                            cin>>word;
                            Node *temp,*parent,*currentNode;
                            b.find(word,&parent,&currentNode);
                               if (currentNode!= NULL)
                              {
                                    Node *predecesor_word, *pointer;
                                    pointer=b.ROOT;
                                    predecesor_word= b.predecessor(pointer,word);

                                          if (predecesor_word != NULL)
                                          cout<<"\nInorder predecessor is "<<predecesor_word->info<<"\n";
                                          else
                                          {

                                              cout<<"\nPredecessor of the word does not exist\n";
                                          }
                               }

                               else
                                   {

                                cout<<"\nWord not found in the dictionary\n";
                                   }
                               break;
                               }

		case '6':
			{
				exit(0);
			}
			break;
		default:
			{
				cout<<"Invalid Option."<<endl;
				break;
			}
		}


	}
}
