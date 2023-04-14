#include<iostream>
using namespace std;

class Node
{
	public:
		int key;
		int height;
		Node *left;
		Node *right;	
};

int max(int first, int second)
{
	return (first > second) ? first : second;
}

int height(Node *node)
{
	if (node == NULL)
	{
		return 0;
	}
	return node->height;
}


Node* newNode(int k)
{
	Node* node = new Node();
	node->key = k;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;

	return(node);
}

Node *rightRotate(Node *temp)
{
	Node *a = temp->left;
	Node *b = a->right;
	a->right = temp;
	temp->left = b;
	temp->height = max(height(temp->left),
	height(temp->right)) + 1;
	a->height = max(height(a->left),
	height(a->right)) + 1;

	return a;
}

Node *leftRotate(Node *temp)
{
	Node *a = temp->right;
	Node *b = a->left;	
	a->left = temp;
	temp->right = b;
	temp->height = max(height(temp->left),
	height(temp->right)) + 1;
	a->height = max(height(a->left),
	height(a->right)) + 1;
	
	return a;
}
bool isPrime(int num)
{
	if (num <= 1)
	{
		return false;
	}
	
	for (int i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

Node* insert(Node* n, int key)
{

	if (n == NULL)
	{
		return(newNode(key));
	}
	if (key < n->key)
	{
		n->left = insert(n->left, key);
	}
	else if (key > n->key)
	{
		n->right = insert(n->right, key);
	}
	else
	{
		return n;
	}
	if (!isPrime(key))
	{
		if (key % 2 != 0)
		{
			return rightRotate(n);
		}
		else
		{
			return leftRotate(n);
		}
	}
	
	return n;
}
void preOrder(Node *node)
{
	if(node != NULL)
	{
		cout << node->key << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

int main()
{
	Node *root = NULL;
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 60);
	root = insert(root, 35);
	cout << "Preorder traversal of the constructed binary tree is "<<endl;
	preOrder(root);
	return 0;
}
