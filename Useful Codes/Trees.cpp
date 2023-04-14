#include <iostream>
using namespace std;

struct Tree
{
	Tree* left;
	Tree* right;
	int data;

};

void rec_insert(Tree* p, Tree* q, int d)
{
	if (q == NULL)
	{
		Tree* temp = new Tree;
		temp->data = d;
		temp->left = NULL;
		temp->right = NULL;


		if (p->data > d)
		{
			p->left = temp;
		}
		else if (p->data < d)
		{
			p->right = temp;
		}
		return;
	}
	else
	{
		while (q != NULL)
		{
			if (q->data == d)
			{
				cout << d << " : is a duplicate value.\n";
				return;
			}
			else if (q->data > d)
			{
				rec_insert(q, q->left, d);
			}
			else if (q->data < d)
			{
				rec_insert(q, q->left, d);
			}
		}
		
	}

}

void insert(Tree* root, int d)
{
	if (root == NULL)
	{
		root = new Tree;
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		Tree* p, * q;
		p = q = root;
		while (q != NULL)
		{
			if (q->data == d)
			{
				cout << d << " : is a duplicate value.\n";
				return;
			}
			else if (q->data > d)
			{
				p = q;
				q = q->left;
			}
			else if (q->data < d)
			{
				p = q;
				q = q->right;
			}
		}
		Tree* temp = new Tree;
		temp->data = d;
		temp->left = NULL;
		temp->right = NULL;


		if (p->data > d)
		{
			p->left = temp;
		}
		else if (p->data < d)
		{
			p->right = temp;
		}
	}

}

void show(Tree* root)
{
	cout << root->data << endl;
	if (root->left != NULL)
	{
		cout << "The Left  child of " << root->data << " is :\t ";
		show(root->left);

	}
	if (root->right != NULL)
	{
		cout << "The Right child of " << root->data << " is :\t ";
		show(root->right);

	}
}
void inorder(Tree* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		cout << root->data << endl;
		inorder(root->right);

	}
}

void preorder(Tree* root)
{
	if (root != NULL)
	{
		cout << root->data << endl;
		preorder(root->left);
		preorder(root->right);

	}
}

void postorder(Tree* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->data << endl;

	}
}

struct Node {
	Tree* data;
	Node* next;
};
class queue {
private:
	int size;
	Node* front;
	Node* rear;
public:
	queue()
	{
		front = NULL;
		rear = NULL;
		size = 0;
	}
	void enqueue(Tree* root)
	{
		if (size == 0)
		{
			Node* tmp = new Node;
			tmp->data = root;
			front = tmp;
			rear = tmp;
			size++;
		}
		else
		{
			Node* tmp = new Node;
			tmp->data = root;
			rear->next = tmp;
			rear = rear->next;
			size++;
		}
	}
	Tree* dequeue()
	{
		if (size == 0)
		{
			cout << "Queue is Empty.\n";
			return NULL;
		}
		else
		{
			Node* tmp = front;
			Tree* n = front->data;
			front = front->next;
			size--;
			delete tmp;
			return n;

		}
	}
	bool isEmpty()
	{
		if (size >= 1)
			return false;
		else
			return true;
	}
};
void BFT(Tree* root)
{
	queue q;
	q.enqueue(root);

	while (!q.isEmpty())
	{
		Tree* tmp = q.dequeue();
		cout << tmp->data << endl;
		if (tmp->left != NULL)
		{
			q.enqueue(tmp->left);

		}
		if (tmp->right != NULL)
		{
			q.enqueue(tmp->right);

		}

	}

}
int main()
{
	int arr[] = { 4,5,9,3,4,7,0,2,4,6,8,9,5 };
	Tree* root = new Tree;
	root->data = arr[0];
	root->left = NULL;
	root->right = NULL;

	for (int i = 1; i < 13; i++)
	{
		insert(root, arr[i]);
	}

	//simple
	show(root);

	//depth first variants
	
	
	//cout << "Visiting Nodes:\n";
	postorder(root);
	//inorder(root);
	//preorder(root);

	//depth first variants
	//BFT(root);

}
