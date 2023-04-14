//Muhammad Ahmed Baig
//20i-1884
//Assignment 3
//Section C and Lab Section D

#include <iostream>
#include <fstream>
using namespace std;

//Binary Search Tree Class
class BST
{
	//Private Members
	private:
		BST *right; //right pointer
		BST *left; //left pointer
		string value; //value
		
	public:
		//constructor
		BST();
		//paramaised constructor 
		BST(string);
		
		//insertion fucntion
		BST *insert(BST* ,string );
		
		//search function
		static int search(BST* root,string d)
		{
			int s=1;
			if(root==NULL)
			{
				return 0;
			}
			if(root->value==d)
			{
				return s+search(root->left, d);
			}
			else if(d > root->value)
			{
				return search(root->right, d);
			}
			else if(d < root->value)
			{
				return search(root->left, d);
			}
		}
		/*
		void Search(node *root, int d)
		{
			int depth = 0;
			BST *temp = NULL;
			temp = root;
			while(temp != NULL)
			{
				depth++;
				if(temp->value == d)
				{
					cout<<"Data found at depth: "<<depth;
					return;
				}
				else if(temp->value < d)
				{
					temp = temp->right;
				}
				else if(temp->value > d)
				{
					temp = temp->left;
				}
			}
			cout<<"Data not found";
			return;
		}*/
		void Delate(BST *root, string d)
	{
		int s=1;
		if(root==NULL)
		{
			cout<<"deleted"<<endl;
		}
		if(root->value==d)
		{
			delete root;
		}
		else if(d > root->value)
		{
				//return search(root->right, d);
		}
		else if(d < root->value)
		{
			
			//return search(root->left, d);
		}
		cout<<"Word Deleted"<<endl;
		delete root;
	}
};

//constructor
BST::BST()
{
	left = NULL;
	right = NULL;
	this->value = "";
}

//paramaised constructor 
BST::BST(string value)
{
	left = NULL;
	right = NULL;
	this->value = value;
}

//insertion fucntion
BST * BST::insert(BST* root, string d)
{
	if (root == NULL)
	{
		return new BST(d);
	}
	if (d > root->value)
	{
		root->right = insert(root->right, d);
	}
	else 
	{
		root->left = insert(root->left, d);
	}	
	return root;
}

void Delete(BST *root, string d)
{
	cout<<"Word Deleted"<<endl;
	delete root;
}		

int main()
{
	string str,text,keyword;
	BST t, *root = NULL, s;
	
	//asking for file name
	cout<<"Please enter a filename:"<<endl;
	cout<<">";
	cin>>str;
	//check if correct file
	if(str == "Assignment_data.txt")
	{
		cout<<"File loaded successfully."<<endl<<endl;
	}
	//check if wrong file
	else
	{
		cout<<"file not found"<<endl;
		exit(0);
	}
	int check;
	cout<<"1.Find or 2.Delete"<<endl;
	cin>>check;
	if (check == 1)
	{
		//opening file
		ifstream in("Assignment_data.txt");
		//storing first text in root
		root = t.insert(root, text);
		for(;in>>text;)
		{
			//inserting text
			t.insert(root, text);
		}
		cout<<"Please enter a word to search:"<<endl;
		cout<<">";
		cin>>keyword;
		cout<<endl;
		//searching for the number or repeated word
		cout<<BST::search(root, keyword);
		cout<<" result(s) found"<<endl;
	}
	else if(check ==2)
	{
		cout<<endl;
		string st;
		cout<<"Enter the word to delete: ";
		cin>>st;
		Delete(root,st);
		
	}
	return 0;
}
