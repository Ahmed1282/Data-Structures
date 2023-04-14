#include <iostream>
using namespace std;

struct Node
{
	Node* left;
	Node* right;
	int data;

};

void insert(Node* root, int d)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = d;
		root->left = NULL;
		root->right = NULL;
	}
	else
	{
		Node* p, * q;
		p = q = root;
		while (q != NULL)
		{
			if (q->data == d)
			{
				cout << d << " : is a duplicate value."<<endl;
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
		Node* temp = new Node;
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

int maxHeight(Node* ptr)
{
	if(ptr == NULL)
	{
		return -1;
	}
	else
	{
		int rightHeight = maxHeight(ptr->right);
		int leftHeight = maxHeight(ptr->left);
		if(rightHeight > leftHeight)
		{
			return rightHeight+1;
		}
		else
		{
			return leftHeight+1;
		}
	}
}

int Depth(Node* root, int v)
{
    if (root == NULL)
    {
        return -1;
	}
    int d = -1;
    if ((root->data == v) || (d = Depth(root->left, v)) >= 0 || (d = Depth(root->right, v)) >= 0)
    {
 		return d + 1;
 	}
    return d;
}

void show(Node* root)
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



int main()
{
	int size;
	cout<<"Enter size of the tree: ";
	cin>>size;
	int arr[size];
	for(int i=0;i<size;i++)
	{
		cout<<"Enter Node/Leaf No."<<i+1<<": ";
		cin>>arr[i];
	}
	
	Node* root = new Node;
	root->data = arr[0];
	root->left = NULL;
	root->right = NULL;
	for (int i = 1; i < size; i++)
	{
		insert(root, arr[i]);
	}
	//Task1
	show(root);
	cout<<endl;
	
	
	//Task2
	int h;
	h = maxHeight(root);
	cout<< "Max Height = "<<h<<endl;
	
	//Task 3
	int k;
	cout<<endl;
	cout<<"Enter Node: ";
	cin>>k;
    cout << "Depth: " << Depth(root, k) <<endl;
	

}
