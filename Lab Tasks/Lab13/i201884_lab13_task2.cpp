#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *left, *right;
};

struct Node *new_Node(int i)
{
	Node *temp = new Node;
	temp->data = i;
	temp->left = temp->right = NULL;
	return temp;
}

int sibling(Node *root, Node *p, Node *q)
{
		
    if (root==NULL)
	{
		return 0;
	}
 
    return ((root->left==p && root->right==q)|| (root->left==q && root->right==p)|| sibling(root->left, p, q)|| sibling(root->right, p, q));
}
 
int level( Node *root,  Node *ptr, int lv)
{
	if (root == NULL) 
	{
		return 0;
	}
    if (root == ptr)
	{
		return lv;
	}
 
    int l = level(root->left, ptr, lv+1);
    if (l != 0)
	{
		return l;
	}

    return level(root->right, ptr, lv+1);
}
 
int cousin( Node *root,  Node *p,  Node *q)
{
    if ((level(root,p,1) == level(root,q,1)) && !(sibling(root,p,q)))
    {
        return 1;
    }
    else
	{
		return 0;
	}
}

int main()
{
	Node *root = new Node;
	
	root->left = new_Node(2);
	root->right = new_Node(3);
	root->left->left = new_Node(4);
	root->left->right = new_Node(5);
	root->left->right->right = new_Node(15);
	root->right->left = new_Node(6);
	root->right->right = new_Node(7);
	root->right->left->right = new_Node(8);

	Node *Node1 = new Node;
	Node *Node2 = new Node;
	Node1 = root->left->left;
	Node2 = root->right->right;

	if (cousin(root,Node1,Node2) == 1)
	{
		cout<<"Yes it is cousin"<<endl;
	}
	else
	{
		cout<<"No it is not cousin"<<endl;
	}
}
